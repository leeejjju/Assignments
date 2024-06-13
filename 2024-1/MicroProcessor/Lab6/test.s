//.syntax unified                     
.thumb
.thumb_func

.equ BTN1_MASK, 0x00800
.equ BTN2_MASK, 0x01000
.equ LED1_MASK, 0x02000
.equ LED2_MASK, 0x04000
.equ LED3_MASK, 0x08000
.equ LED4_MASK, 0x10000
.equ LED_ALL_MASK, (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)

.equ GPIO_P0_BASE, 0x50000000
.equ GPIO_OUT_REG_OFFSET, 0x504
.equ GPIO_IN_REG_OFFSET, 0x510
.equ GPIO_DIR_REG_OFFSET, 0x514
.equ GPIO_DIRSET_REG_OFFSET, 0x518
.equ GPIO_OUTCLR_REG_OFFSET, 0x50C
.equ GPIO_OUTSET_REG_OFFSET, 0x508

.equ GPIO_PIN_CNF_11_OFFSET, 0x72C // P0.11 pin configuration address offset (BTN1)
.equ GPIO_PIN_CNF_12_OFFSET, 0x730
.equ GPIO_PIN_CNF_24_OFFSET, 0x760
.equ GPIO_PIN_CNF_25_OFFSET, 0x764

.equ GPIOTE_BASE, 0x40006000
.equ GPIOTE_INTENSET_OFFSET, 0x304
.equ GPIOTE_CONFIG0_OFFSET, 0x510 // GPIOTE channel 0
.equ GPIOTE_CONFIG1_OFFSET, 0x514 // GPIOTE channel 1
.equ GPIOTE_EVENT_IN0, 0x40006100
.equ GPIOTE_EVENT_IN1, 0x40006104

.equ NVIC_BASE, 0xE000E000

.section .text                      
.global main

main:
  BL GPIO_SETUP
  BL GPIOTE_SETUP
  BL NVIC_SETUP
  WFI
  B .
//myLoop: B myLoop

 
GPIO_SETUP:
  // LED1,LED2 setting
  LDR R0, =GPIO_P0_BASE
  LDR R1, =(LED1_MASK+LED2_MASK)
  STR R1, [R0, #GPIO_DIRSET_REG_OFFSET]

  // Button1 setting
  LDR R1, =0x0003000c
  //LDR R1, =0x0000000c
  STR R1, [R0, #GPIO_PIN_CNF_11_OFFSET]
  // Button2 setting
  STR R1, [R0, #GPIO_PIN_CNF_12_OFFSET]
  
  MOV PC,LR

GPIOTE_SETUP:
  // GPIOTE setting
  LDR R0, =GPIOTE_BASE

  // Channel 0,1 interrupt setting 
  MOV R1, #0x03 // channel 0,1
  STR R1, [R0, #GPIOTE_INTENSET_OFFSET]

  // PIN_CNF[11] configurations
  // for mode setting and pin number setting
  MOV R1, #0x01 // mode = event
  MOV R2, #11   // pin number = 11
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
  // setting GPIOTE_PIN_CONFIG[11]
  STR R1, [R0, #GPIOTE_CONFIG0_OFFSET]

  // PIN_CNF[12] configurations
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
  LDR R1, =NVIC_BASE // interrupt set-enable register
  ADD R0, R1, #0x100

  // set interrupt Enable for interrupt from GPIOTE (interrupt number 6) 
  MOV R1, #(1<<6)
  STR R1, [R0]

  // set interrupt priority for GPIOTE interrupt
  // set R0 as base address for interrupt priority register 
  LDR R0, =0xE000E400 // interrupt priority register
  MOV R1, #2
  // set GPIOTE interrupt priority as 2 for interrupt from GPIOTE (interrupt number 6)
  STR R1, [R0 , #6]

  BX LR  // return

led1Toggle:
  LDR R0, =GPIO_P0_BASE
  LDR R1, [R0, #GPIO_OUT_REG_OFFSET]
  EORS R1, R1, #(LED1_MASK+LED2_MASK)
  STR R1, [R0, #GPIO_OUT_REG_OFFSET]
  BX LR   // return

.global GPIOTE_Handler
GPIOTE_Handler:
  // PUSH : save the LR value to stack 
  PUSH {LR}
  // Check if interrupt source is Button1 (GPIOTE channel 0)
  // By looking at the bit 0 of EVENT_IN0 (channel 0) register of GPIOTE
  LDR R0, =GPIOTE_EVENT_IN0
  LDR R1, [R0] // Read GPIOTE Event In0
  LDR R0, =GPIOTE_EVENT_IN1
  LDR R2, [R0] // Read GPIOTE Event In1
  ORR R1, R1, R2

  TST R1, #1 // Check if Event In0 occurred

  BEQ EXIT_GPIOTE_Handler  // If No Button1 Event, Skip the Handler

  BL led1Toggle

  // Prepare Exiting the interrupt handler by
  // Clearing the bit 0 of EVENT_IN0 (channel 0) register of GPIOTE
  LDR R0, =GPIOTE_EVENT_IN0
  MOV R1, #0
  STR R1, [R0]

  LDR R0, =GPIOTE_EVENT_IN1
  MOV R1, #0
  STR R1, [R0]
  
EXIT_GPIOTE_Handler:
  // POP: retrievd the saved LR value from the stack 
  POP {LR}
  
  // return from ISR
  BX LR
