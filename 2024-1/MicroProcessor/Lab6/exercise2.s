//.syntax unified                     
.thumb
.thumb_func

/*
Add Button-2 Event Interrupt
btn2 -> led2 blink at 10Hz rates for 5sec
btn2's interrupt priority is lower than btn1's. (set pri=3)
*/

.equ BTN1_MASK, 0x00800
.equ BTN2_MASK, 0x01000
.equ LED1_MASK, 0x02000
.equ LED2_MASK, 0x04000
.equ LED3_MASK, 0x08000
.equ LED4_MASK, 0x10000
.equ LED_ALL_MASK, (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)

.equ GPIO_P0_BASE, 0x50000000
.equ GPIO_DIRSET_REG_OFFSET, 0x518
.equ GPIO_OUT_REG_OFFSET, 0x504
.equ GPIO_PIN_CNF_11_OFFSET,    0x72C  // P0.11 pin configuration address offset (BTN1)
.equ GPIO_PIN_CNF_12_OFFSET,    0x730  // P0.11 pin configuration address offset (BTN1)

.equ GPIOTE_BASE, 0x40006000
.equ GPIOTE_INTENSET_OFFSET, 0x304
.equ GPIOTE_CONFIG0_OFFSET, 0x510 // GPIOTE channel 0
.equ GPIOTE_CONFIG1_OFFSET, 0x514 // GPIOTE channel 1
.equ GPIOTE_EVENT_IN0, 0x40006100
.equ GPIOTE_EVENT_IN1, 0x40006104


.section .text                      
.global main

//.syntax unified                     
.thumb
.thumb_func

/*
Add Button-2 Event Interrupt
btn2 -> led2 blink at 10Hz rates for 5sec
btn2's interrupt priority is lower than btn1's. (set pri=3)
*/

.equ BTN1_MASK, 0x00800
.equ BTN2_MASK, 0x01000
.equ LED1_MASK, 0x02000
.equ LED2_MASK, 0x04000
.equ LED3_MASK, 0x08000
.equ LED4_MASK, 0x10000
.equ LED_ALL_MASK, (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)

.equ GPIO_P0_BASE, 0x50000000
.equ GPIO_DIRSET_REG_OFFSET, 0x518
.equ GPIO_OUT_REG_OFFSET, 0x504
.equ GPIO_PIN_CNF_11_OFFSET,    0x72C  // P0.11 pin configuration address offset (BTN1)
.equ GPIO_PIN_CNF_12_OFFSET,    0x730  // P0.11 pin configuration address offset (BTN1)

.equ GPIOTE_BASE, 0x40006000
.equ GPIOTE_INTENSET_OFFSET, 0x304
.equ GPIOTE_CONFIG0_OFFSET, 0x510 // GPIOTE channel 0
.equ GPIOTE_CONFIG1_OFFSET, 0x514 // GPIOTE channel 1
.equ GPIOTE_EVENT_IN0, 0x40006100
.equ GPIOTE_EVENT_IN1, 0x40006104


.section .text                      
.global main

main:
  BL GPIO_SETUP
  BL GPIOTE_SETUP
  BL NVIC_SETUP
  WFI //idle when no event
  B .
//myLoop: B myLoop

 
GPIO_SETUP:
  // LED12 setting
  LDR R0, =GPIO_P0_BASE
  LDR R1, =(LED1_MASK+LED2_MASK)
  STR R1, [R0, #GPIO_DIRSET_REG_OFFSET]

  // Button12 setting
  LDR R1, =0x0003000c
  STR R1, [R0, #GPIO_PIN_CNF_11_OFFSET]
  STR R1, [R0, #GPIO_PIN_CNF_12_OFFSET]
  MOV PC,LR


GPIOTE_SETUP:
  // GPIOTE setting
  LDR R0, =GPIOTE_BASE

  // Channel 0 interrupt setting 
  MOV R1, #(0x01+0x02) // channel = 0
  STR R1, [R0, #GPIOTE_INTENSET_OFFSET]

  // btn1 -> PIN_CNF[11] configurations
  // for mode setting and pin number setting 
  MOV R1, #0x01 // mode = event
  MOV R2, #11   // pin number = 11
  LSL R2, R2, #8 // shift bits to PSEL place (BBBBB)
  ORR R1, R1, R2
  // for port number setting
  MOV R2, #0x00 // port number = 0 (active low)
  LSL R2, R2, #13 // shift bits to PORT place (C)
  ORR R1, R1, R2
  // for Polarity setting
  MOV R2, #0x02  // polarity = HiToLo (2)
  LSL R2, R2, #16 // shift bits to PORT place (DD)
  ORR R1, R1, R2
  // setting GPIOTE_PIN_CONFIG[11]
  STR R1, [R0, #GPIOTE_CONFIG0_OFFSET]


  // btn2 -> PIN_CNF[12] configurations
  // for mode setting and pin number setting
  MOV R1, #0x01 // mode = event
  MOV R2, #12   // pin number = 12
  LSL R2, R2, #8 // shift bits to PSEL place (BBBBB)
  ORR R1, R1, R2
  // for port number setting
  MOV R2, #0x00 // port number = 0
  LSL R2, R2, #13 // shift bits to PORT place (C)
  ORR R1, R1, R2
  // for Polarity setting
  MOV R2, #0x02  // polarity = HiToLo (2)
  LSL R2, R2, #16 // shift bits to PORT place (DD)
  ORR R1, R1, R2
  // setting GPIOTE_PIN_CONFIG[12]
  STR R1, [R0, #GPIOTE_CONFIG1_OFFSET]


  BX LR //MOV PC, LR


NVIC_SETUP:
  // NVIC setting

  // set R0 as base address of NVIC
  LDR R0, =0xE000E100 // interrupt set-enable register
  // set interrupt Enable for interrupt from GPIOTE (interrupt number 6) 
  MOV R1, #(1<<6) //GPIO interrupt number = 6
  STR R1, [R0]

  // set interrupt priority for GPIOTE interrupt
  // set R0 as base address for interrupt priority register 
  LDR R0, =0xE000E400 // interrupt priority register
  // set GPIOTE interrupt priority as 2 for interrupt from GPIOTE (interrupt number 6)
  MOV R1, #2 //it doesnt have to be at the top priority
  STR R1, [R0, #6] //GPIOTE interrupt number = 6

  BX LR  // return

//toggle R3's led
ledToggle:
  LDR R0, =GPIO_P0_BASE
  LDR R1, [R0, #GPIO_OUT_REG_OFFSET]
  EORS R1, R1, R3
  STR R1, [R0, #GPIO_OUT_REG_OFFSET]
  BX LR   // return


Delay_50_msec:
  LDR R2, =800000
  count_down_5:
  CMP R2, #0
  ITT NE
  SUBNE R2, R2, #1
  BNE count_down_5
  MOV PC, LR

Delay_half_sec:
  LDR R2, =8000000
  count_down_2:
  CMP R2, #0
  ITT NE
  SUBNE R2, R2, #1
  BNE count_down_2
  MOV PC, LR

.global GPIOTE_Handler
GPIOTE_Handler:
  // PUSH : save the LR value to stack 
  PUSH {LR}
  // Check if interrupt source is Button1 (GPIOTE channel 0)
  // By looking at the bit 0 of EVENT_IN0 (channel 0) register of GPIOTE
  LDR R0, =GPIOTE_EVENT_IN0
  LDR R1, [R0] // Read GPIOTE Event In0

  //******************btn2*******************
  LDR R0, =GPIOTE_EVENT_IN1
  LDR R2, [R0] // Read GPIOTE Event In1
  //*****************************************

  TST R1, #1 //is btn1 pressed?
  BEQ btn2  // If No Button1 Event, Skip this area

  btn1:
    mov r7, #10
    //blink led1,2 1Hz for 5sec
    loop_1:
      MOV R3, #(LED1_MASK + LED2_MASK)
      BL ledToggle
      bl Delay_half_sec
      subs r7, r7, #1
      it ne
      bne loop_1
    LDR R0, =GPIOTE_EVENT_IN0
    b done

  btn2:
  TST R2, #1 //is btn2 pressed?
  BEQ EXIT_GPIOTE_Handler // If No Button2 Event, Skip this area 
    
    mov r8, #100
    //blink led2 10Hz for 5sec
    loop_2:
      MOV R3, #LED2_MASK
      BL ledToggle
      bl Delay_50_msec
      subs r8, r8, #1
      it ne
      bne loop_2
    LDR R0, =GPIOTE_EVENT_IN1


  done:
  // Prepare Exiting the interrupt handler by
  // Clearing the bit 0 of EVENT_IN0 (channel 0) register of GPIOTE
  
  MOV R1, 0
  STR R1, [R0] 
  
  
EXIT_GPIOTE_Handler:
  // POP: retrievd the saved LR value from the stack 
  POP {LR}
  
  // return from ISR
  BX LR
