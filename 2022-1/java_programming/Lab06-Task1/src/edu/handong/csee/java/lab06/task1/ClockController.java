package edu.handong.csee.java.lab06.task1;


public class ClockController {

    public static void main(String[] args){
        ClockController myController = new ClockController();
        myController.run(args);
    }

    public void run(String[] args) {
        Clock myClock = new Clock();
        
        myClock.setCurrentTime(args[0]);
        myClock.setColor(args[1]);
        myClock.setType(args[2]);
        System.out.println("The current time of my clock is " + myClock.getCurrentTime());
        System.out.println("The color of my clock is " + myClock.getColor());
        System.out.println("The type of my clock is " + myClock.getType());
    }
}


