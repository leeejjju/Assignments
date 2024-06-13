.thumb
.thumb_func
.global main

.equ BTN1_MASK, 0x00800
.equ BTN2_MASK, 0x01000
.equ BTN3_MASK, 0x1000000
.equ BTN4_MASK, 0x2000000
.equ BTN_ALL_MASK, (BTN1_MASK+BTN2_MASK+BTN3_MASK+BTN4_MASK)
.equ LED1_MASK, 0x02000
.equ LED2_MASK, 0x04000
.equ LED3_MASK, 0x08000
.equ LED4_MASK, 0x10000
.equ LED_ALL_MASK, (LED1_MASK+LED2_MASK+LED3_MASK+LED4_MASK)

.equ GPIO_P0_BASE, 0x50000000
.equ GPIO_OUT_REG_OFFSET, 0x504
.equ GPIO_DIR_REG_OFFSET, 0x514
.equ GPIO_OUTCLR_REG_OFFSET, 0x50C
.equ GPIO_OUTSET_REG_OFFSET, 0x508
.equ GPIO_DIRSET_REG_OFFSET, 0x518
.equ GPIO_IN_REG_OFFSET, 0x510

.equ GPIO_PIN_CNF_11_OFFSET, 0x72C //P0.11 pin (BTN1)
.equ GPIO_PIN_CNF_12_OFFSET, 0x730 //P0.12 pin (BTN2)
.equ GPIO_PIN_CNF_24_OFFSET, 0x760 //P0.24 pin (BTN3)
.equ GPIO_PIN_CNF_25_OFFSET, 0x764 //P0.25 pin (BTN4)


// R5 is btn pushed
// R6 is mask to be toggled
// R7 is mask of current states
// R8 is flag that indicate led3 need to be toggled every one second
main:
  BL SETTING_GPIO
  BL TURN_OFF_LED

  Loop: 
    //wait for btn push event 
    BL WAIT_BTN_PUSH
    MOV R6, #0 //set mask off

    //if btn1 event occured... 
    CMP R5, #BTN1_MASK 
    IT EQ
    MOVEQ R6, #(LED1_MASK) //set mask as led1 and led2

    //if btn2 event occured... 
    CMP R5, #BTN2_MASK 
    IT EQ
    MOVEQ R6, #(LED2_MASK) //set mask as led1 and led2

    //change R7 state (toggle the mask in R6)
    BL APPLY_TOGGLE

    //if btn3 event occured... 
    CMP R5, #BTN3_MASK 
    IT EQ
    //MOVEQ R8, #1 //set flag for toggle btn3
    MOVEQ R6, #(LED3_MASK)

    //if btn4 event occured...
    CMP R5, #BTN4_MASK  
    IT EQ
    //MOVEQ R8, #0 //clear flag for toggle btn3
    MOVEQ R6, #(LED4_MASK)

    //if flag is set, update led3's mask to toggle it
    //CMP R8, #1
    //IT EQ
    //ADDEQ R6, R6, #LED3_MASK //add led3's mask

    //applicate the current mask state(R7)
    BL CHANGE_LED 
    BL Delay_one_second
    B Loop


//change the led state using R7's state 
CHANGE_LED:
  LDR R0, =GPIO_P0_BASE+ GPIO_OUT_REG_OFFSET //get current state
  STR R7, [R0] //applicate toggle of mask
  MOV PC, LR

//update R7(next led state) by toggle using R6
APPLY_TOGGLE:
  LDR R0, =GPIO_P0_BASE+ GPIO_OUT_REG_OFFSET
  LDR R7, [R0] //read state
  EOR R7, R6 //complement the mask range
  //STR R2, [R0] //applicate it
  MOV PC, LR

//turn off all of the LED
TURN_OFF_LED:
  LDR r0, =GPIO_P0_BASE+GPIO_OUTSET_REG_OFFSET
  LDR r1, =LED_ALL_MASK
  STR r1, [r0]
  MOV PC, LR


//wait for btn event and save the cause btn's mask
WAIT_BTN_PUSH:

  LDR r0, =GPIO_P0_BASE
  loop_w:
    LDR r1, [r0, #GPIO_IN_REG_OFFSET]
    MVN r1, r1

    TST R1, #(BTN1_MASK)
    ITT NE 
    MOVNE R5, #BTN1_MASK
    MOVNE PC, LR

    TST R1, #(BTN2_MASK)
    ITT NE 
    MOVNE R5, #BTN2_MASK
    MOVNE PC, LR

    TST R1, #(BTN3_MASK)
    ITT NE 
    MOVNE R5, #BTN3_MASK
    MOVNE PC, LR

    TST R1, #(BTN4_MASK)
    ITT NE 
    MOVNE R5, #BTN4_MASK
    MOVNE PC, LR

    B loop_w

  MOV PC, LR



Delay_one_second:
  LDR r2, =1600000
  count_down:
    CMP r2, #0
    ITT NE
    SUBNE r2, r2, #1
    BNE count_down
    MOV PC, LR


SETTING_GPIO:
  //set led direction
  LDR r0, =GPIO_P0_BASE
  LDR r1, =LED_ALL_MASK
  STR r1, [r0, #GPIO_DIR_REG_OFFSET]

  //set configuration of btns
  LDR r1, =0x003000c //PIN_CNF[11] address...
  LDR r0, =GPIO_P0_BASE+GPIO_PIN_CNF_11_OFFSET
  STR r1, [r0]
  LDR r0, =GPIO_P0_BASE+GPIO_PIN_CNF_12_OFFSET
  STR r1, [r0]
  LDR r0, =GPIO_P0_BASE+GPIO_PIN_CNF_24_OFFSET
  STR r1, [r0]
  LDR r0, =GPIO_P0_BASE+GPIO_PIN_CNF_25_OFFSET
  STR r1, [r0]

  MOV PC, LR

