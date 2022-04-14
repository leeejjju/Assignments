package edu.handong.csee.java.hw2.math;


/**
 * This is class for math calculate.
 * It provides several methods for mathematical operations.
*/
public class MathCalculator {

    private String name;

    /**this is method for set the driver name */
    public void setName(String newName){
        name = newName;
    }

    /**this is method for get the dricer name */
    public String getName(){
        return name;
    }

    /**this is method for calculate maximum value */
    public int getMax(int a, int b){
        
        return (a>b)?a:b; 

    }

    /**this is method for calculate minimum value */
    public int getMin(int a, int b){
        return (a<b)?a:b; 
    }

    /**this is method for calculate absolute */
    public int getAbs(int a){
        return (a > 0)?a:-a; 
    }

    /**this is method for calculate sum */
    public int getSum(int a, int b){
        return a+b;
    }

    /**this is method for calculate Difference */
    public int getDiff(int a, int b){
        return a - b;
    }

    /**this is method for calculate Product */
    public int getProduct(int a, int b){
        return a * b;
    }

    /**this is method for calculate Quotient */
    public int getQuotient(int a, int b){
        return a / b;
    }

    /**this is method for calculate Remainder */
    public int getRemainder(int a, int b){
        return a % b;
    }

    /**this is method for calculate Power */
    public int getPower(int a, int b){

        int rst = 1;

        for(int i = 0; i < b; i++){
            rst *= a;
        }

        return rst;

    }

    /**this is method for calculate Factorial */
    public int getFactorial(int a){
        int fact = 1;

        for(int i = 1; i <= a; i++){
            fact *= i;
        }

        return fact;

    }

    /**this is method for calculate GCD */
    public int getGcd(int a, int b){ 

        int num = (a>b)?a:b;

        while(true){
            if(num == 1) return 1;
            if(a%num == 0 && b%num == 0) break;
            else num--;
        }
        return num;

    }

    /**this is method for calculate LCM */
    public int getLcm(int a, int b){ 

        int num = (a>b)?a:b;

        while(true){
            
            if(num%a == 0 && num%b == 0) break;
            else num++;
        }
        return num;
    }

    /**this is method for calculate Square */
    public int getSquare(int a){
        return a*a; 

    }


    
}



