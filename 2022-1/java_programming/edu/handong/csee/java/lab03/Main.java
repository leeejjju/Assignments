package edu.handong.csee.java.lab03;
import edu.handong.csee.java.lab03.posting.Picture;


public class Main{
	public static void main(String[] args) {
		User user = new User();
		Picture myPicture = new Picture("I'm posting a picture", "2019-01-01", "user1");
		user.post(myPicture);
		user.editProfile();
	}
}
