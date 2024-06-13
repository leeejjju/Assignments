#include <stdint.h>
#define LED1_MASK 0x00002000
#define LED2_MASK 0x00004000
#define LED3_MASK 0x00008000
#define LED4_MASK 0x00010000
#define LED_ALL_MASK (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)
#define GPIO_P0_BASE 0x50000000
#define GPIO_OUT_REG_OFFSET 0x0504
#define GPIO_DIR_REG_OFFSET 0x0514
#define GPIO_DIRSET_REG_OFFSET 0x0518

void volatile setting() 
{
  volatile uint32_t *dir_reg = 
    (uint32_t*)(GPIO_P0_BASE+GPIO_DIR_REG_OFFSET);
  *dir_reg    = LED3_MASK;
}

void volatile turn_OFF_LED()
{
    volatile uint32_t * out_reg =
          (uint32_t *)(GPIO_P0_BASE+GPIO_OUT_REG_OFFSET);
    *out_reg = LED3_MASK;
}

void volatile turn_ON_LED()
{
  volatile uint32_t *out_reg = 
          (uint32_t *)(GPIO_P0_BASE+GPIO_OUT_REG_OFFSET);
  *out_reg = ~LED3_MASK;
}

void volatile delay_loop()
{
   __asm(
      "LDR R2, =16000000\n\t"
      "count_down: CMP R2, #0\n\t"
      "ITT NE\n\t"
      "SUBNE R2, R2, #1\n\t"
      "BNE count_down\n\t"
      "MOV PC, LR\n\t"
    );
    
    //for(int i = 6400000; i >0; i--);
}

int main()
{
   setting();
   while(1)   {
      turn_ON_LED();
      delay_loop();
      turn_OFF_LED();
      delay_loop();
   }
   return 0;
}




