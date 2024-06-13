package edu.handong.csee.se.testing;


import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


public class MathTest {
    @Test void testMax() {
        Math myMathDriver = new Math();


        double[] numbers00 = {0, 0, 0, 0,};
        assertEquals(0, myMathDriver.max(numbers00));


        double[] numbers01 = {1,2,3,4,5};
        assertEquals(5, myMathDriver.max(numbers01));
       
        double[] numbers02 = {5,4,3,2,1};
        assertEquals(5, myMathDriver.max(numbers02));
       
        double[] numbers03 = {1};
        assertEquals(1, myMathDriver.max(numbers03));


        double[] numbers04 = {1, 1};
        assertEquals(1, myMathDriver.max(numbers04));


        double[] numbers05 = {1, 2, 3, 2, 1};
        assertEquals(3, myMathDriver.max(numbers05));


        double[] numbers06 = {2, 1, 3, 1, 2};
        assertEquals(3, myMathDriver.max(numbers06));


        double[] numbers07 = {-2, 1, -3, 1, 2};
        assertEquals(2, myMathDriver.max(numbers07));
       
        double[] numbers08 = {-2, -1, -3, -1, 0};
        assertEquals(0, myMathDriver.max(numbers08));


        double[] numbers09 = {-2, -1, -3, -1, 0.9999999999999999999 };
        assertEquals(1.00000000000000001, myMathDriver.max(numbers09));


        double[] numbersNull = null;
        assertEquals(Double.NaN, myMathDriver.max(numbersNull));


    }
}
