package edu.handong.csee.java.lab04;

/**
 * this is the AdminAccount class.
 * Admin account can search the user ID and edit their information.
 */
public class AdminAccount extends Account {
    private String adminPW;

    /**this is method for search user ID */
    public void searchUserID(){
        System.out.println("3 user IDs have been searched.");
    }

    /**this is method for edit selected user information */
    public void editSelectedUserInfo(){
        System.out.println("Selected user information is edited.");
    }
}
