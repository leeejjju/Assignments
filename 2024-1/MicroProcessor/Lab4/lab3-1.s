.thumb
.thumb_func
.global main
.equ LED1_MASK, 0x02000
.equ LED2_MASK, 0x04000
.equ LED3_MASK, 0x08000
.equ LED4_MASK, 0x10000
.equ LED_ALL_MASK, (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)
.equ GPIO_P0_BASE, 0x50000000
.equ GPIO_IN_REG_OFFSET, 0x510 // Read GPIO port
.equ GPIO_OUT_REG_OFFSET, 0x504
.equ GPIO_DIR_REG_OFFSET, 0x514
.equ GPIO_DIRSET_REG_OFFSET, 0x518

main:
  LDR R0, =GPIO_P0_BASE
  LDR R1, = LED3_MASK
  STR R1, [R0,#GPIO_DIR_REG_OFFSET] // GPIO DIR (1:out, 0: input)
  loop:
    BL Toggle
    BL Delay_One_second
    B loop

// Delay Routtine
Delay_One_second:
  LDR R2, = 16000000 // loop counter for 1 sec with 64MHz system clock
  count_down:
    SUBS R2, #1
    NOP
    IT NE
    BNE count_down
  MOV PC, LR // return

Toggle:
  LDR R2, =GPIO_P0_BASE+0x504 
  LDR R1, [R2]                   
  EOR R1, R1, #LED3_MASK         
  STR R1, [R2]                   
  MOV PC, LR

// LED ON Routine
TURN_ON_LED:
  LDR R0, =GPIO_P0_BASE+0x504 // OUT register (for my board LED, 0:ON, 1:OFF)
  LDR R1, = LED3_MASK
  MVN R1, R1 // complement
  STR R1, [R0]
  MOV PC, LR // return

// LED OFF Routine
TURN_OFF_LED:
  LDR R0, =GPIO_P0_BASE+0x504 // OUT register
  LDR R1, =LED_ALL_MASK
  STR R1,[R0]
  MOV PC, LR // return