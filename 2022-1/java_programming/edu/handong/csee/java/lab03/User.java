package edu.handong.csee.java.lab03;
import java.util.ArrayList;
import edu.handong.csee.java.lab03.posting.Posting;

public class User{
	
	private ArrayList<String> listOfFriends;
	private ArrayList<String> listOfCloseFrriends;
	private String id;
	private int accountType;
	private String job;
	private String school;
	private String profileImage; //image file path
	
	public void post(Posting posting) {
		System.out.println("I'm posting something:" + posting.getContent());
		
	}
	
	public void editProfile() {
		System.out.println("I'm editing my profile");
	}
	
	
}