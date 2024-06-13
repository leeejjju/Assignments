#include <stdint.h>

void volatile TURN_ON_LED()
{
    __asm volatile(
    "LDR R0, =0x50000504\n\t"
    "LDR R1, =0x00002000\n\t"
    "MVN R1, R1\n\t"
    "STR R1, [R0]\n\t"
    "MOV PC, LR\n\t"
    );
}


void volatile Delay_loop()
{
   __asm volatile(
      "LDR R2, =16000000\n\t"
      "count_down: CMP R2, #0\n\t"
      "ITT NE\n\t"
      "SUBNE R2, R2, #1\n\t"
      "BNE count_down\n\t"
      "MOV PC, LR\n\t"
    );
}

void volatile TURN_OFF_LED()
{
    __asm(
    "LDR R0, =0x50000504\n\t" // OUT register (for my board LED, 0:ON, 1:OFF)
    "LDR R1, =0x00002000\n\t"
    "STR R1, [R0]\n\t"
    "MOV PC, LR\n\t"  
    );
}

void volatile SETTING() 
{

  __asm(
    "LDR R0, = 0x50000000\n\t"
    "LDR R1, =0x00002000\n\t"                     
    "STR R1, [R0, 0x514]\n\t");
}


int main()
{
  SETTING();

   while(1) 
   {
     TURN_ON_LED();
     Delay_loop();
     TURN_OFF_LED();
     Delay_loop();
   }
   return 0;
}


