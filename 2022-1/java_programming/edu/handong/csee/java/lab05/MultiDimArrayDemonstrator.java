package edu.handong.csee.java.lab05;

class MultiDimArrayDemonstrator {

    String[][] names = {
        {"Mr. ", "Ms. "},
        {"Mark Zuckerberg", "Barack Obama", "Bergoglio Sivori", "Angela Merkel", "Donald Trump", "Greta Thunberg", "Joseph Biden", "Kamala Harris" },
        {"1984-05-14", "1961-08-04", "1936-12-17", "1954-07-17", "1946-06-14", "2003-01-03", "1942-11-20", "1964-10-20"}
    };
    public static void main(String[] args) {
        MultiDimArrayDemonstrator runner = new MultiDimArrayDemonstrator();
        runner.run();
    }

    public void run(){
        for(int i = 0; i < 8; i++){
            if(i == 1) System.out.print(names[0][0]);
            else{
                if(i%2 == 0) System.out.print(names[0][0]);
                else System.out.print(names[0][1]);
            }
            System.out.println(names[1][i] + " (" + names[2][i] + ")");
        }
    }
}


