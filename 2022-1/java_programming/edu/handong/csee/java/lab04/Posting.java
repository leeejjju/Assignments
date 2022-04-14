package edu.handong.csee.java.lab04;

/**
 * this is Posting class.
 * Posting can edit info about port, and add numbers of some state. 
 */
public class Posting {
    
    private String title;
    private String[] content;
    private String date;
    private int numOfLikes;
    private int numOfBookmark;
    private String[] commentList;

    /**this is method for edit title */
    public void editTitle(){
        System.out.println("The subject has been changed.");
    }

    /**this is method for edit content */
    public void editContent(){
        System.out.println("The contents have been changed.");
    }

    /**this is method for add comment */
    public void addComment(){
        System.out.println("Comments have been added.");
    }

    /**this is method for add like */
    public void addLike(){
        //numOfLikes ++;
        System.out.println("Like has been added.");
    }

    /** this is method for add Bookmark */
    public void addBookMakr(){
        //numOfBookmark++;
        System.out.println("bookmark has been added.");
    }

}
