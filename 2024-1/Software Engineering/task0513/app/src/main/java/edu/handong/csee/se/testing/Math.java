package edu.handong.csee.se.testing;


public class Math {
    public double max(double[] values) {
        
        if(values == null) return Double.NaN;
        double maxval = values[0];

        for(int i = 0 ; i < values.length ; i++){
            if(maxval < values[i]) maxval = values[i];
        }
        return maxval;
    }
}
