package edu.handong.csee.java.lab04;

/**
 * this is Account class.
 * Account can do several things related to account.
 */
public class Account {

    private String id;
    private String pw;
    private boolean isLogedIn;

    /**this is method for edit ID */
    public void editID(){
        System.out.println("The ID has been changed.");
    }

    /**this is method for edit PassWord */
    public void editPW(){
        System.out.println("Your password has been changed.");
    }

    /**this is method for try login */
    public boolean tryLogIn(){
        System.out.println("You have successfully logged in.");
        return true;
    }

    
}
