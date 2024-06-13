.thumb
.thumb_func
.global main
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

main:
  LDR R0, =GPIO_P0_BASE
  LDR R1, =LED_ALL_MASK 
  STR R1, [R0, #GPIO_DIR_REG_OFFSET] // GPIO DIR (1:out, 0: input)
  // Input pin Configuratrion
  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_11_OFFSET // for GPIO P0.11 pin address
  @ A = 0(input), B = 0(connect input buffer), CC = 11 (pull up), DDD=000 (standard'0 and 1), EE=11 (SENS for LOW)
  @ EE D DD CCBA
  @ 0000 0000 0000 0011 0000 0000 0000 1100 = 0x0003000C
  LDR R1, =0x0003000c //PIN_CNF[11] address 
  STR R1, [R0]  // configure GPIO P0.11 pin 
  // as Input, Connected input buffer, 
  // Pull-up, Drive in standard strength, Sense Low input

loop:
  BL TURN_OFF_LED1
  BL Delay
  BL WAIT_BTN1_PUSH
  BL TURN_ON_LED1
  BL Delay
  BL WAIT_BTN1_PUSH
  B loop
/*delay_loop:
LDR R2, = // loop counter for 1 sec with 64MHz system clock
count_down:
CMP R2, #0
ITT NE
SUBNE R2, R2, #1
BNE count_down
MOV PC, LR*/

Delay:
  LDR R2, =1600000
  count_down:
  CMP R2, #0
  ITT NE
  SUBNE R2, R2, #1
  BNE count_down
  MOV PC, LR

TURN_ON_LED1:
  LDR R0, =GPIO_P0_BASE+ GPIO_OUT_REG_OFFSET // OUT register (for my board LED, 0:ON, 1:OFF)
  LDR R1, =(LED1_MASK+LED2_MASK)
  MVN R1, R1 // complement
  STR R1, [R0]
  MOV PC, LR

TURN_OFF_LED1:
  LDR R0, =GPIO_P0_BASE+ GPIO_OUT_REG_OFFSET // OUT register
  //LDR R1, =(LED1_MASK+LED2_MASK)
  LDR R1, =LED_ALL_MASK
  STR R1,[R0]
  MOV PC, LR

WAIT_BTN1_PUSH:
  LDR R0, =GPIO_P0_BASE
  WAIT_LOOP:
  LDR R1, [R0, #GPIO_IN_REG_OFFSET]
  MVN R1,R1
  TST R1, #BTN1_MASK
  IT EQ // IF NOT PUSHED
  BEQ WAIT_LOOP
  MOV PC, LR // return
