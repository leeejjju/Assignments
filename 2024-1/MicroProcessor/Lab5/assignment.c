#include <stdint.h>
#define LED1_MASK 0x00002000
#define LED2_MASK 0x00004000
#define LED3_MASK 0x00008000
#define LED4_MASK 0x00010000

#define GPIO_P0_BASE 0x50000000
#define GPIO_OUT_REG_OFFSET 0x0504
#define GPIO_DIR_REG_OFFSET 0x0514
#define GPIO_DIRSET_REG_OFFSET 0x0518
#define GPIO_IN_REG_OFFSET 0x510

#define BTN1_MASK 0x00800
#define BTN2_MASK 0x01000
#define GPIO_PIN_CNF_11_OFFSET 0x72C 

int curr_mask = 0;



void volatile TURN_ON_LED() {
  volatile uint32_t *OUT_REG = (uint32_t *)(GPIO_P0_BASE+GPIO_OUT_REG_OFFSET);
  *OUT_REG = ~curr_mask;
}
void volatile Delay_loop() {
    __asm(
      "LDR R2, =1600000\n\t"
      "count_down: CMP R2, #0\n\t"
      "ITT NE\n\t"
      "SUBNE R2, R2, #1\n\t"
      "BNE count_down\n\t"
      "MOV PC, LR\n\t"
    );
    //for(int i = 6400000; i >0; i--);
}

void volatile SETTING()  {
  *((uint32_t*)(GPIO_P0_BASE+GPIO_DIR_REG_OFFSET)) = LED1_MASK + LED2_MASK;
  *((uint32_t*)(GPIO_P0_BASE+GPIO_PIN_CNF_11_OFFSET)) = 0x0003000c;
}

void volatile WAIT_INPUT_PUSH() {
  while(1){
    volatile uint32_t button_state = *((uint32_t*)(GPIO_P0_BASE+GPIO_IN_REG_OFFSET));
    button_state = ~button_state;
    if(button_state & BTN1_MASK)
      break;
  }
}

int select_next_led(int num){
  
  num++;
  if(num == 0){
    curr_mask = LED2_MASK;
  }else if(num == 1){
    curr_mask = LED1_MASK;
  }else if(num == 2){
    curr_mask = LED1_MASK+LED2_MASK;
  }else if(num == 3){
    curr_mask = 0;
  }else{
    num = 0;
    curr_mask = LED2_MASK;
  }
  return num;

}

int main() {
  SETTING();
  int num = 0;

   while(1){
     num = select_next_led(num);
     TURN_ON_LED();
     Delay_loop();
     WAIT_INPUT_PUSH();
   }
   return 0;
}
