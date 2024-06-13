.thumb
.thumb_func
.global main
.equ LED1_MASK, 0x02000
.equ LED2_MASK, 0x04000
.equ LED3_MASK, 0x08000
.equ LED4_MASK, 0x10000
.equ LED_ALL_MASK, (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)
.equ GPIO_P0_BASE, 0x50000000
.equ GPIO_OUT_REG_OFFSET, 0x504
.equ GPIO_DIR_REG_OFFSET, 0x514
.equ GPIO_DIRSET_REG_OFFSET, 0x518


.equ BTN1_MASK, 0x00800
.equ BTN2_MASK, 0x01000
.equ BTN3_MASK, 0x1000000
.equ BTN4_MASK, 0x2000000
.equ BTN_ALL_MASK, (BTN1_MASK+BTN2_MASK+BTN3_MASK+BTN4_MASK)

.equ GPIO_IN_REG_OFFSET, 0x510
.equ GPIO_OUTCLR_REG_OFFSET, 0x50C
.equ GPIO_OUTSET_REG_OFFSET, 0x508
.equ GPIO_PIN_CNF_11_OFFSET, 0x72C // P0.11 pin configuration address offset (BTN1)
.equ GPIO_PIN_CNF_12_OFFSET, 0x730 // P0.10 pin configuration address offset (BTN2)
.equ GPIO_PIN_CNF_24_OFFSET, 0x760 // P0.24 pin configuration address offset (BTN3??)
.equ GPIO_PIN_CNF_25_OFFSET, 0x764 // P0.25 pin configuration address offset (BTN4??)

main:
  LDR R0, =GPIO_P0_BASE
  LDR R1, = LED_ALL_MASK
  STR R1, [R0,#GPIO_DIR_REG_OFFSET] // GPIO DIR (1:out, 0: input) 
  BL TURN_OFF_LED

  //p1.
  //BL P1
  
  //p2.
  //BL P2

  //p3.
  //BL P3

  //p4.
  BL P4

  B END


//p1.
P1:
  LDR R0, =GPIO_P0_BASE+GPIO_OUTCLR_REG_OFFSET // OUT CLEAR (for my board LED, 0:ON, 1:OFF) -> ON
  LDR R2, =GPIO_P0_BASE+GPIO_OUTSET_REG_OFFSET // OUT SET -> OFF
  LDR R1, = LED1_MASK

  loop_1:
    //turn on
    STR R1, [R0] //turn on
    BL Delay
    //change mask (LED1 or LED2)
    BL TURN_OFF_LED
    LSL R1, #1 //++
    CMP R1, #0x08000 //if out of range,
    BNE loop_1
    LDR R1, = LED1_MASK //reset it to mask1
    B loop_1
    

//p2.
P2:
  LDR R0, =GPIO_P0_BASE+GPIO_OUT_REG_OFFSET // OUT register (for my board LED, 0:ON, 1:OFF)
  LDR R1, = LED1_MASK 
  loop_2:

    //turn on
    MVN R1, R1 // complement mask to turn on(low-active)
    STR R1, [R0]
    BL Delay //wait 1 second
  
    //turn off
    MVN R1, R1 
    STR R1, [R0] 

    //load next mask
    LSL R1, #1 
    CMP R1, #0x20000 //if out of range,
    BNE loop_2
    LDR R1, = LED1_MASK //reset it to mask1
    B loop_2


//p3.
P3:
  LDR R1, =0x0003000c //PIN_CNF[11] address 

  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_11_OFFSET // for GPIO P0.11 pin address
  STR R1, [R0]  // configure GPIO P0.11 pin 

  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_12_OFFSET // for GPIO P0.11 pin address
  STR R1, [R0]  // configure GPIO P0.11 pin

  loop_3:
    BL WAIT_BTN_PUSH
    LDR R1, =(LED1_MASK+LED2_MASK) //load mask
    BL TOGGLE_LED
    BL Delay
    B loop_3


//p4.
P4:
  LDR R1, =0x0003000c //PIN_CNF[11] address 

  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_11_OFFSET // for GPIO P0.11 pin address
  STR R1, [R0]  // configure GPIO P0.11 pin 
  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_12_OFFSET // for GPIO P0.12 pin address
  STR R1, [R0]  // configure GPIO P0.12 pin
  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_24_OFFSET // for GPIO P0.24 pin address
  STR R1, [R0]  // configure GPIO P0.24 pin
  LDR R0, =GPIO_P0_BASE+GPIO_PIN_CNF_25_OFFSET // for GPIO P0.25 pin address
  STR R1, [R0]  // configure GPIO P0.25 pin

  loop_4:
    BL WAIT_BTN_PUSH_AND_SAVE
    BL GET_LED_FROM_BTN //save the correspond led mask in R1 
    BL TOGGLE_LED
    BL Delay
    //BL Delay
    B loop_4

// Delay 100ms
Delay:
  LDR R2, =1600000
  count_down:
    CMP R2, #0
    ITT NE
    SUBNE R2, R2, #1
    BNE count_down
  MOV PC, LR

// Delay 1sec
Delay_one_second:
  LDR R2, = 16000000 // loop counter for 1 sec with 64MHz system clock
  cnt_down:
    CMP R2, #0
    ITT NE
    SUBNE R2, R2, #1
    BNE cnt_down
  MOV PC, LR // return

// LED OFF Routine (for all) 
TURN_OFF_LED:
  LDR R5, =GPIO_P0_BASE+GPIO_OUT_REG_OFFSET // OUT register
  LDR R6, =LED_ALL_MASK
  STR R6,[R5]
  MOV PC, LR // return

//toggle LED (for R1's mask)
TOGGLE_LED:
  LDR R0, =GPIO_P0_BASE+ GPIO_OUT_REG_OFFSET
  LDR R2, [R0] //read state
  EOR R2, R1 //complement the mask range
  STR R2, [R0] //applicate it
  MOV PC, LR

//wait untill btn1 or btn2 is pushed
WAIT_BTN_PUSH:
  LDR R0, =GPIO_P0_BASE
  WAIT_LOOP:
    LDR R1, [R0, #GPIO_IN_REG_OFFSET]
    MVN R1,R1

    TST R1, #(BTN1_MASK+BTN2_MASK)
    IT EQ // IF NOT PUSHED
    BEQ WAIT_LOOP
    MOV PC, LR


//wait untill any btn pushed + pushed button's mask will be saved in R7
WAIT_BTN_PUSH_AND_SAVE:
  LDR R0, =GPIO_P0_BASE
  WAIT_LOOP_2:
    LDR R1, [R0, #GPIO_IN_REG_OFFSET]
    MVN R1,R1

    TST R1, #(BTN1_MASK)
    ITT NE // IF NOT PUSHED
    MOVNE R7, #BTN1_MASK
    BNE BREAK

    TST R1, #(BTN2_MASK)
    ITT NE // IF NOT PUSHED
    MOVNE R7, #BTN2_MASK
    BNE BREAK

    TST R1, #(BTN3_MASK)
    ITT NE // IF NOT PUSHED
    MOVNE R7, #BTN3_MASK
    BNE BREAK

    TST R1, #(BTN4_MASK)
    ITT NE // IF NOT PUSHED
    MOVNE R7, #BTN4_MASK
    BNE BREAK

    B WAIT_LOOP_2


GET_LED_FROM_BTN:
  CMP R7, #0 //skip if no btn is pushed
  ITT EQ
  MOVEQ R1, #0
  BEQ BREAK

  CMP R7, #BTN1_MASK //if btn1 or btn2 is pushed...
  ITT EQ
  MOVEQ R1, #LED1_MASK //check btn mask and convert to correspond led mask
  BEQ BREAK 

  CMP R7, #BTN2_MASK //if btn1 or btn2 is pushed...
  ITT EQ
  MOVEQ R1, #LED2_MASK //check btn mask and convert to correspond led mask
  BEQ BREAK 

  CMP R7, #BTN3_MASK //if btn1 or btn2 is pushed...
  ITT EQ
  MOVEQ R1, #LED3_MASK //check btn mask and convert to correspond led mask
  BEQ BREAK 

  CMP R7, #BTN4_MASK //if btn1 or btn2 is pushed...
  ITT EQ
  MOVEQ R1, #LED4_MASK //check btn mask and convert to correspond led mask
  BEQ BREAK 


BREAK:
    MOV PC, LR // return
END: