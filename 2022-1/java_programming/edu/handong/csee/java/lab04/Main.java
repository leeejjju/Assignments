package edu.handong.csee.java.lab04;

/** this is Main class */
public class Main {

    /**this is the main method */
    public static void main(String[] args) {
        Main runner = new Main();
        runner.run();
    }

    /**this is method for run the program */
    public void run(){
        Account newAccount = new Account();
        AdminAccount newAdmin = new AdminAccount();
        UserAccount newUser = new UserAccount();
        Posting newPosting = new Posting();


        newAccount.editID();
        newAccount.editPW();
        newAccount.tryLogIn();

        newAdmin.searchUserID();
        newAdmin.editSelectedUserInfo();

        newUser.post();

        newPosting.editTitle();
        newPosting.editContent();
        newPosting.addComment();
        newPosting.addLike();
        newPosting.addBookMakr();

    }


}

