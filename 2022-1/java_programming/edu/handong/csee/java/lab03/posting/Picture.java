package edu.handong.csee.java.lab03.posting;

public class Picture extends Posting{
	String picturePath;
	
	public Picture (String content, String date, String id) {
		super(content, date, id);
	}
	
	public void setPicturePath(String picturePath) {
		this.picturePath = picturePath;
	}
	
}
