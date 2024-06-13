#include <stdint.h>

#define BTN1_MASK 0x00800
#define BTN2_MASK 0x01000
#define BTN3_MASK 0x1000000
#define BTN4_MASK 0x2000000
#define BTN_ALL_MASK (BTN1_MASK+BTN2_MASK+BTN3_MASK+BTN4_MASK)
#define LED1_MASK 0x02000
#define LED2_MASK 0x04000
#define LED3_MASK 0x08000
#define LED4_MASK 0x10000
#define LED_ALL_MASK (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)

#define GPIO_P0_BASE 0x50000000
#define GPIO_OUT_REG_OFFSET 0x504
#define GPIO_DIR_REG_OFFSET 0x514
#define GPIO_OUTCLR_REG_OFFSET 0x50C
#define GPIO_OUTSET_REG_OFFSET 0x508
#define GPIO_DIRSET_REG_OFFSET 0x518
#define GPIO_IN_REG_OFFSET 0x510

#define GPIO_PIN_CNF_11_OFFSET 0x72C //P0.11 pin (BTN1)
#define GPIO_PIN_CNF_12_OFFSET 0x730 //P0.12 pin (BTN2)
#define GPIO_PIN_CNF_24_OFFSET 0x760 //P0.24 pin (BTN3)
#define GPIO_PIN_CNF_25_OFFSET 0x764 //P0.25 pin (BTN4)


void volatile TOGGLE_LED12(){

  volatile uint32_t *OUT_REG = (uint32_t*)(GPIO_P0_BASE+GPIO_OUT_REG_OFFSET);
  uint32_t curr = *OUT_REG;
  curr ^= (LED1_MASK+LED2_MASK);
  *OUT_REG = curr;
}

void volatile Delay_loop(){

  __asm volatile(
      "LDR R2, =1600000\n\t"
      "count_down: CMP R2, #0\n\t"
      "ITT NE\n\t"
      "SUBNE R2, R2, #1\n\t"
      "BNE count_down\n\t"
      "MOV PC, LR\n\t"
    );
}

void volatile SETTING(){

  *((uint32_t*)(GPIO_P0_BASE+GPIO_DIR_REG_OFFSET)) = LED1_MASK+LED2_MASK;
  *((uint32_t*)(GPIO_P0_BASE+GPIO_PIN_CNF_11_OFFSET)) = 0x003000c;
  *((uint32_t*)(GPIO_P0_BASE+GPIO_PIN_CNF_12_OFFSET)) = 0x003000c;

}

void volatile WAIT_PUSH(){

  while(1){
    volatile uint32_t button_state = *((uint32_t*)(GPIO_P0_BASE+GPIO_IN_REG_OFFSET));
    button_state = ~button_state;
    if(button_state & (BTN1_MASK)) break;
    if(button_state & (BTN2_MASK)) break;
    
  }
}


int main(){

  SETTING();
  while(1){

    TOGGLE_LED12();
    Delay_loop();
    WAIT_PUSH();

  }

  return 0;

}