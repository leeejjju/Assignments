package edu.handong.csee.java.lab07.string;

public class FamilyNamePrinter {

    //"JC Nam, JH Moon, SK Kim, SY Jung"
    /*Nam
    Moon
    Kim
    Jung*/

    public static void main(String args[]){
        FamilyNamePrinter runner = new FamilyNamePrinter(args[0]);
        runner.printFamilyNames();

    }

    private String[] stringNames;   
    private String[] familyNames;

    FamilyNamePrinter(String n){
        n = n.trim();
        stringNames = n.split(",");
        familyNames = n.split(",");
        String[] tmp;
        for(int i = 0; i < stringNames.length; i++){
            stringNames[i] = stringNames[i].trim();
            tmp = stringNames[i].split(" ");
            familyNames[i] = tmp[1];
        }

    }


    public void printFamilyNames(){
        //for(int i = 0; i < familyNames.length; i++){
        //    System.out.println(familyNames[i]);
        //}
        for(String tmp: familyNames){
            System.out.println(tmp);
        }
        

    }



    //split the string value
    //Note that there is space between "," and name. (You might need trim() method)

    
}
