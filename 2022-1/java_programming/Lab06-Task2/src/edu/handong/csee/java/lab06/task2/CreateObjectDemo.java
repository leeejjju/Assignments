package edu.handong.csee.java.lab06.task2;

public class CreateObjectDemo {

    public static void main(String[] args) {
		
        // Declare and create a point object and two rectangle objects.
        Point originOne = new Point(23, 94);
        Rectangle rectOne = new Rectangle(originOne, 100, 200);
        Rectangle rectTwo = new Rectangle(50, 100);

        Point jcPoint = new Point(20, 40);
        Rectangle jcRectangle = new Rectangle(jcPoint, 100, 200);
        Rectangle lab06Rectangle = new Rectangle(300, 400);
        
		
        // display rectOne's width, height, and area
        System.out.println("Width of rectOne: " + rectOne.width);
        System.out.println("Height of rectOne: " + rectOne.height);
        System.out.println("Area of rectOne: " + rectOne.getArea());
		
        // set rectTwo's position
        rectTwo.origin = originOne;

        
        // display rectTwo's position
        System.out.println("X Position of rectTwo: " + rectTwo.origin.x);
        System.out.println("Y Position of rectTwo: " + rectTwo.origin.y);
		
        // move rectTwo and display its new position
        rectTwo.move(40, 72);
        System.out.println("X Position of rectTwo: " + rectTwo.origin.x);
        System.out.println("Y Position of rectTwo: " + rectTwo.origin.y);

        System.out.println("jcRectangle's origin coordinate: " + jcRectangle.origin.x + " " + jcRectangle.origin.y);
        System.out.println("jcRectangle's width and height: " + jcRectangle.width + " " + jcRectangle.height);
        System.out.println("lab06Rectangle's origin coordinate: " + lab06Rectangle.origin.x + " " + lab06Rectangle.origin.y);
        System.out.println("lab06Rectangle's area: " + lab06Rectangle.getArea());
        
        
        
        


    }
}

