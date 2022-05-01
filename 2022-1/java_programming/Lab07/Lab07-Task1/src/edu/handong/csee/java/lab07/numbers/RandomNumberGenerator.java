package edu.handong.csee.java.lab07.numbers;

public class RandomNumberGenerator {

    
    private int firstNumber;
    private int secondNumber;
    private int randomNumber;

    public static void main(String args[]){
        RandomNumberGenerator myRandomGenerator = new RandomNumberGenerator(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        //for(int i = 0; i < 5; i++){
            myRandomGenerator.generateRandomNumber();
            System.out.println(myRandomGenerator.getRandomNumber());
        //}
        
        
    }

    public RandomNumberGenerator(int a,int b){
        firstNumber = Math.max(a, b); //max
        secondNumber = Math.min(a, b); //min
        //System.out.println(firstNumber+ ","+ secondNumber);
    }

    public void generateRandomNumber(){ //max-min  random number
        randomNumber = (int) Math.random() * (firstNumber-secondNumber+1) + secondNumber;
        //System.out.println(randomNumber + " is created.");

    }
    public int getRandomNumber(){ //getter
        return randomNumber;
    }




    
}
