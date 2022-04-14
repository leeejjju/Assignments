package edu.handong.csee.java.lab04;

/**
 * this is User class.
 * User can make some post.
 */
public class UserAccount extends Account{
    private String university;
    private String studentNum;

    /**this is method for posting */
    public void post(){
        System.out.println("You have created a post.");
    }
}
