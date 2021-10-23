import java.util.Scanner;

public class KBC{

public static void main(String[] args){

int moneywon=0;
int question=1;

Scanner s=new Scanner(System.in);

System.out.println();
System.out.println("\t  ********************************************");
System.out.println("Welcome to -----------------KBC-----------------------");

System.out.println("\t  ********************************************");
System.out.println();System.out.println();
do{
	switch(question){

		case 1:System.out.println("Q1. What is the capital of Australia?");
		System.out.println();
		System.out.println("a)Baghdad  b)Canberra  c)Washington  d)Moscow");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans1=s.next();

		if(ans1.equals("b") || ans1.equals("B"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.20,000");
		System.out.println();
		moneywon=20000;
		question++;
		}
		else {
		System.out.println();	
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;

		case 2:System.out.println("Q2. Which city is cleanest city of India?");
		System.out.println();
		System.out.println("a)Bhopal  b)Ahmedabad  c)Ujjain  d)Indore");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans2=s.next();

		if(ans2.equals("d")|| ans2.equals("D"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.40,000");
		System.out.println();
		moneywon=40000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;

		case 3:System.out.println("Q3. What does ATM stads for?");
		System.out.println();
		System.out.println("a)Automatic Teller Machine b)Automated Teller Machine c)Auto Teller Machine d)Anytime Teller Machine");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans3=s.next();

		if(ans3.equals("b") || ans3.equals("B"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.80,000");
		System.out.println();
		moneywon=80000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;
		
		case 4:System.out.println("Q4. The language of Lakshwadeep,UT of India is?");
		System.out.println();
		System.out.println("a)Tamil  b)Hindi  c)Malyalam  d)Telugu");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans4=s.next();

		if(ans4.equals("c") || ans4.equals("C"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.1,60,000");
		System.out.println();
		moneywon=160000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;

		case 5:System.out.println("Q5. September 27 is celebrated every year as?");
		System.out.println();
		System.out.println("a)Teacher's Day  b)National Integration Day  c)World Tourism Day  d)International Literacy Day");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans5=s.next();

		if(ans5.equals("c") || ans5.equals("C"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.3,20,000");
		System.out.println();
		moneywon=320000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;
		
		case 6:System.out.println("Q6. Who is the author of 'Meghdoot'?");
		System.out.println();
		System.out.println("a)Vishakadatta  b)Valmiki  c)Banabhatta  d)Kalidas");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans6=s.next();

		if(ans6.equals("d") || ans6.equals("D"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.6,40,000");
		System.out.println();
		moneywon=640000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;

		case 7:System.out.println("Q7. 'Good Friday' is observed to commemorate the event of?");
		System.out.println();
		System.out.println("a)birth of Jesus Christ  b)birth of St. Peter  c)crucification of Jesus Christ  d)rebirth of Jesus Christ");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans7=s.next();

		if(ans7.equals("c") || ans7.equals("C"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.12,50,000");
		System.out.println();
		moneywon=1250000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;
		
		case 8:System.out.println("Q8. Pongal is festival of which state?");
		System.out.println();
		System.out.println("a)Karnataka  b)Kerala  c)Tamil Nadu  d)Andhra Pradesh");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans8=s.next();

		if(ans8.equals("c") || ans8.equals("C"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.25,00,000");
		System.out.println();
		moneywon=2500000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;	
		
		case 9:System.out.println("Q9. Ghototkach in Mahabharat was the son of?");
		System.out.println();
		System.out.println("a)Duryodhana  b)Arjuna  c)Yudhishthir  d)Bhima");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans9=s.next();

		if(ans9.equals("d") || ans9.equals("D"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.50,00,000");
		System.out.println();
		moneywon=5000000;
		question++;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;
		
		case 10:System.out.println("Q10. Van Mahotsav was started by?");
		System.out.println();
		System.out.println("a)Maharshi Karve  b)K.M. Munshi  c)Bal Gangadhar Tilak  d)Sanjay Gandhi");
		System.out.println();
		System.out.print("Enter the character of your choice:");
		String ans10=s.next();

		if(ans10.equals("b") || ans10.equals("B"))
		{
		System.out.println();
		System.out.println("Congrats!! Your answer is correct");
		System.out.println("Congrats!! You won Rs.1,00,00,000 !!");
		System.out.println();
		moneywon=10000000;
		question=0;
		}
		else {
		System.out.println();
		System.out.println("Your answer is incorrect");
		System.out.println();
		question=0;
		}
		break;
		
		default:
		System.out.println("Incorrect Choice");
		break;
		}
}while(question!=0);

if(moneywon<40000){
	System.out.println("Sorry you LOST the game BUT");
	System.out.println("You get Rs. 0");
	}

else if(moneywon>=40000 && moneywon<320000){
	System.out.println("Sorry you LOST the game BUT");
	System.out.println("You get Rs. 40,000");
}
else if(moneywon>=320000 && moneywon<10000000){
	System.out.println("Sorry you LOST the game BUT");
	System.out.println("You get Rs. 3,20,000");
}
else{
	System.out.println("Congatulations!! you WON the game");
	System.out.println("You have become a Crorepati!!!");
	}
}
}
