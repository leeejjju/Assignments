import java.io.*;
import java.util.Scanner;
import java.nio.file.*;


class TestFileIO{

    public static void main(String[] args){

        TestFileIO runner = new TestFileIO();
        //runner.inputFile(args);
        //runner.outputFile(args);
        //runner.getFileName();
        //runner.makeCSVFile(args);
        runner.mkDir(args);
        runner.practiceCSV(args);
        
    }


    //write new file 
    public void inputFile(String[] args) {
        String fileName = args[0];
        PrintWriter outputStream = null;
        try{
            //outputStream = new PrintWriter(fileName);
            outputStream = new PrintWriter(new FileOutputStream(fileName, true));
            //See.FileOutputStream(File file, boolean append)
            //throw new FileNotFoundException();


        }catch(FileNotFoundException e){
            System.out.println("[Error]File not found");
            System.exit(0);
        }

        System.out.println("Enter three lines of text:");
        Scanner keyboard = new Scanner(System.in);
        for(int i = 1; i <= 3; i++){
            String line = keyboard.nextLine();
            outputStream.println(i+" : "+line);
        }
        outputStream.close();
        System.out.println("Those lines were written to "+ fileName);

    }


    //read exist file
    public void outputFile(String[] args){
        String fileName = args[0];
        Scanner inputStream = null;
        System.out.println("The file "+ fileName + "\ncontains the following lines:\n");

        try{
            inputStream = new Scanner(new File(fileName));
        }catch(FileNotFoundException e){
            System.out.println("[Error]File not found");
            System.exit(0);
        }
        while(inputStream.hasNextLine()){
            String line = inputStream.nextLine();
            System.out.println(line);
        }
        System.out.println();
        inputStream.close();


    }

    //read exist file, get file name from keyboard
    public void getFileName(){
        System.out.println("Enter the file name: ");
        Scanner keyboard = new Scanner(System.in);
        String fileName = keyboard.next();
        Scanner inputStream = null;

        
        try{
            inputStream = new Scanner(new File(fileName));
        }catch(FileNotFoundException e){
            System.out.println("[Error]File not found");
            System.exit(0);
        }

        System.out.println("The file"+fileName+"\n"+"contains the following lines:\n");
        

        while(inputStream.hasNextLine()){
            String line = inputStream.nextLine();
            System.out.println(line);
        }

        System.out.println();
        inputStream.close();
        keyboard.close();
    }

    //making csv file example
    public void makeCSVFile(String[] args){
        String filePath = args[0] + ".csv";
        File file = null;
        BufferedWriter bw = null;
        String NEWLINE = System.lineSeparator(); // \n

        try{
            file = new File(filePath);
            bw = new BufferedWriter(new FileWriter(file));
            
            bw.write("number, name, hometown");
            bw.write(NEWLINE);

            bw.write("1, Hee Han, Illsan");
            bw.write("\n");

            bw.write("2, Sijun Yang, Yangsan");
            bw.write("\r\n");

            bw.write("3, Hanmin Park, Yangsan");

            bw.flush();
            bw.close();

        }catch(Exception e){
            e.printStackTrace();
        }
        
    }


    //Lets practice to make csv file!! 
    public void practiceCSV(String[] args){

        String filePath = args[0] + "/" + args[1] + ".csv";


        File file = null;
        BufferedWriter bw = null;
        

        try{
            file = new File(filePath);
            bw = new BufferedWriter(new FileWriter(file));
            
            bw.write("this is test for appliy to java HW5\n");
            bw.write("hehe\n");


            bw.flush();
            bw.close();

        }catch(Exception e){
            e.printStackTrace();
        }
        
    }

    

    public void mkDir(String[] args) {
        String path = "";
		
        if(args[0].contains(":")){
            path = args[0];
        }else path = "./"+ args[0];
         

        File newFile = new File(path);
        boolean isWorks = false;
        
        try{isWorks = newFile.mkdirs();}
        catch(Exception e){e.getStackTrace();} 
        

        System.out.println("enterd path is "+ path);

        if (isWorks) {
            System.out.println("Folder created.");
        }else{
            System.out.println("the Folder is already exist.(or something is wrong...)");
        }

        
    }
    




}