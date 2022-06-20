import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class TestThread implements Runnable{

    public int number;


    public static void main(String args[]){	

        ArrayList<Thread> threads = null;

        System.out.println("I am main one. ");
        
        for(int i = 0; i < 10; i++){
            TestThread runnableOne=new TestThread();
            runnableOne.setNum(i);
            Thread thread = new Thread(runnableOne);
            //thread.setPriority(10);
            thread.start();
        }

        

        System.out.println("I am main two. ");


        //--------------------------------------------------------------------------

        ThreadPoolExecutor executor = (ThreadPoolExecutor) Executors.newFixedThreadPool(2);

        executor.submit(() -> {
            Thread.sleep(1000);
            return null;
        });
        executor.submit(() -> {
            Thread.sleep(1000);
            return null;
        });
        executor.submit(() -> {
            Thread.sleep(1000);
            return null;
        });

        //assertEquals(2, executor.getPoolSize());
        //assertEquals(1, executor.getQueue().size());



    }

    
    // implement the run method of Interface 
    @Override	
    public void run() {
        System.out.println("I am thread no. " + number);
    }	

    public void setNum(int x){
        number = x;
    }


}



