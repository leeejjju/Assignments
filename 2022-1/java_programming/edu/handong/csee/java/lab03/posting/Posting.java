package edu.handong.csee.java.lab03.posting;


public class Posting {
	
	String content;
	String date;
	String id;
	
	public Posting(String content, String date, String id) {
		this.content = content;
		this.date = date;
		this.id = id;
	}
	
	public String getContent() {
		return content;
	}
	
}
