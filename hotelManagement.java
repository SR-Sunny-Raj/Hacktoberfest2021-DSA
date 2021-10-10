// created by Tanay-Dwivedi


import java.util.Scanner;
import java.util.*;
public class hotel_AP{
		public static void main(String [] args)
		{
			customers [] customer = new customers[10];
			customer[0] = new customers();
			customer[0].customerData();
			admin admin1=new admin();
			admin1.adminmenu();
		}
}
class customers{
		int tableNo;
		String name;
		int phoneNo;

		void customerData()
		{
			Scanner sc = new Scanner(System.in);
			System.out.print("Entere no.    :");
			tableNo = sc.nextInt();
			System.out.print("Entermer name : ");
			name = sc.next();
			System.out.print("Entere no.    :");
			phoneNo = sc.nextInt();
		}
}
class admin{

		String userName;
		String passWord;
		String username;
		String cpassword;

		admin()
		{
			userName="admin";
			passWord="system";
		}

		boolean checkPassword()
		{


			Scanner sc=new Scanner(System.in);
			int couter=0;
			do{
			System.out.print("Enter name  :");
			username=sc.next();
			System.out.print("Enterword :");
			cpassword=sc.next();
			boolean flag_check_user;
			boolean flag_check_password;
			flag_check_user=username.equals(userName);
			flag_check_password=cpassword.equals(passWord);
			go:{
				if (flag_check_user==true)  
			        {
				if (flag_check_password==true){
				System.out.println("Logines....");
				return(true);
				}else{
					System.out.println("___________________Sorry agian___________________");
				++couter;
				if (couter==3)
				{
					break;  
				}
					}

			}else{
				System.out.println("___________________SorryTry agian___________________");
				++couter;
				if (couter==3)
				{
					break;
				}
			}

		  }
		}while(couter!=3);
			return(false);
		}
		void reserPassword()
			{
				Scanner sc = new Scanner(System.in);
				String psw=passWord;
				System.out.print("Enterent password : ");
				cpassword=sc.nextLine();
					boolean flag_check_password=cpassword.equals(psw);
					if(flag_check_password==true)
					{				
					System.out.print("Enterpassword : ");
					passWord=sc.next();
					System.out.print("Enterpassword agian : ");
					String ps=sc.next();
					if(passWord.equals(ps))
					{
						passWord=ps;
						System.out.println("Resetwowrs.....");
					}
					else
					{
						System.out.print("passwordmatch : ");
					}
					}
					else{
					System.out.println("Passwordmatch....");
					passWord=psw;
					}
					{


			}	
			}

		void adminmenu()
		{
			admin admin1=new admin();
			Scanner sc=new Scanner(System.in);
			int ch;
			ch=1;
			menu show_menu = new menu();	
			boolean flag=false;
			boolean flag1=false;
			boolean flag2;
			do{
			flag=show_menu.list();
			if (flag==true)
			{
			flag1=admin1.checkPassword();
			if(flag1==true)
			{
			System.out.println("____________________Admin____________________");
			System.out.println("1.Add");
			System.out.println("2.Remove");
			System.out.println("3.Editfile");
			System.out.println("4.Resetword");
			System.out.println("5.Exit		System.out.print("Enter choise : ");
			ch=sc.nextInt();
			switch(ch)
			{
				case 1:
					show_menu.additem();
				break;

				case 2:
					show_menu.removeitem();
				break;

				case 3:
					show_menu.editprofile();
				break;

				case 4:
					admin1.reserPassword();
				break;

				case 5:
				break;

				default:
				break;
			}

			}

		}
		}while(ch!=5);

}		
}

class menu{

		int ch;
		static int cbill;
		admin admin1=new admin();
		ArrayList main_menu=new ArrayList();
		ArrayList list_southIndian=new ArrayList();
		ArrayList prize_southIndian=new ArrayList();
		ArrayList list_gujarati=new ArrayList();
		ArrayList prize_gujarati=new ArrayList();
		ArrayList list_panjabi=new ArrayList();
		ArrayList prize_panjabi=new ArrayList();
		ArrayList list_chainies=new ArrayList();
		ArrayList prize_chainies=new ArrayList();
		ArrayList list_tea=new ArrayList();
		ArrayList prize_tea=new ArrayList();
		ArrayList list_icecream=new ArrayList();
		ArrayList prize_icecream=new ArrayList();
		ArrayList list_local=new ArrayList();
		ArrayList prize_local=new ArrayList();
		Scanner sc= new Scanner(System.in);
		String hotelName="AP HOTEL";
		menu()
		{
			main_menu.add("1.Southan");
			main_menu.add("2.Gujarati		main_menu.add("3.chainies		main_menu.add("4.panjabi		main_menu.add("5.tea		main_menu.add("6.icecrime		main_menu.add("7.Localutch");
			main_menu.add("8.exit		
			list_southIndian.add("Vadaar");
			prize_southIndian.add(100);
			list_southIndian.add("Idli Sambar");
			prize_southIndian.add(150);
			list_southIndian.add("Idli);
			prize_southIndian.add(120);
			list_southIndian.add("Dahi");
			prize_southIndian.add(170);
			list_southIndian.add("Upma		prize_southIndian.add(100);
			list_southIndian.add("Batata);
			prize_southIndian.add(120);
			list_southIndian.add("Kachori		prize_southIndian.add(130);
			list_southIndian.add("Vada");
			prize_southIndian.add(130);
			list_southIndian.add("Sada");
			prize_southIndian.add(120);
			list_southIndian.add("Butter");
			prize_southIndian.add(100);

			list_gujarati.add("Roti/Puri		prize_gujarati.add(10);
			list_gujarati.add("Rice/Dal		prize_gujarati.add(40);
			list_gujarati.add("Alui/Leelu Shak");
			prize_gujarati.add(30);
			list_gujarati.add("Papad/Goor		prize_gujarati.add(10);
			list_gujarati.add("Onion/Tomato		prize_gujarati.add(10);
			list_gujarati.add("Makkhan/Khichdi		prize_gujarati.add(40);
			list_gujarati.add("Dhokla		prize_gujarati.add(50);
			list_gujarati.add("Dahi");
			prize_gujarati.add(60);
			list_gujarati.add("Bajriotla/Makai na rotla");
			prize_gujarati.add(20);
			list_gujarati.add("tamatahak");
			prize_gujarati.add(50);

			list_chainies.add("Prawns");
			prize_chainies.add(130);
			list_chainies.add("Chineseage");
			prize_chainies.add(120);
			list_chainies.add("Woron");
			prize_chainies.add(170);
			list_chainies.add("Cantonese Mein (Lg)");
			prize_chainies.add(130);
			list_chainies.add("halksls");
			prize_chainies.add(160);
			list_chainies.add("Beef Mein");
			prize_chainies.add(140);
			list_chainies.add("Mushroom Mein");
			prize_chainies.add(170);
			list_chainies.add("Shrimp Mein");
			prize_chainies.add(130);
			list_chainies.add("BeefTomato Chow Mein (Lg)");
			prize_chainies.add(200);
			list_chainies.add("Houseial Chow Mein (Lg)");
			prize_chainies.add(300);

			list_panjabi.add("Sarsonaag Aur Makki Ki Roti");
			prize_panjabi.add(200);
			list_panjabi.add("Choleure");
			prize_panjabi.add(60);
			list_panjabi.add("Masalana");
			prize_panjabi.add(50);
			list_panjabi.add("Dalani");
			prize_panjabi.add(100);
			list_panjabi.add("Machchlitsari");
			prize_panjabi.add(300);
			list_panjabi.add("Dhaba);
			prize_panjabi.add(70);
			list_panjabi.add("Rajma		prize_panjabi.add(80);
			list_panjabi.add("Lassiala");
			prize_panjabi.add(30);
			list_panjabi.add("Alootsari");
			prize_panjabi.add(150);
			list_panjabi.add("Subjio");
			prize_panjabi.add(150);

			list_tea.add("White);
			prize_tea.add(40);
			list_tea.add("Green);
			prize_tea.add(50);
			list_tea.add("Oolong);
			prize_tea.add(60);
			list_tea.add("Black);
			prize_tea.add(70);
			list_tea.add("Pu-erh);
			prize_tea.add(80);
			list_tea.add("Tisanes);
			prize_tea.add(80);

			list_icecream.add("Baconcream");
			prize_icecream.add(70);
			list_icecream.add("BeerCream");
			prize_icecream.add(100);
			list_icecream.add("Blackut ice cream");
			prize_icecream.add(120);
			list_icecream.add("Blue");
			prize_icecream.add(150);
			list_icecream.add("Cherrycream");
			prize_icecream.add(100);
			list_icecream.add("Chocolate cookie dough ice cream");
			prize_icecream.add(100);
			list_icecream.add("Chocolatecream");
			prize_icecream.add(120);

			list_local.add("Dabeli		prize_local.add(30);
			list_local.add("pani");
			prize_local.add(30);
			list_local.add("chatpati		prize_local.add(30);
		}
		boolean list()
		{
		System.out.println("\n\n~*~*~*~*~*~*~*~*~*~*"+hotelName+"~*~*~*~*~*~*~*~*~*~*\n\nSystem.oSystem.out.println("_____________________W_L_O_E_________________________	System.out.println("______________________E_C_M__________________________\n\n	System.out.println("....................main..Menu.......................\n\n");

		go:{do

		{
		displayMainMenu(main_menu);
		System.out.print("_Enter your choise : ");
		ch  = sc.nextInt();

		switch(ch){
			case 1:
				displayMenu(list_southIndian,prize_southIndian);
			break;

			case 2:
				displayMenu(list_gujarati,prize_gujarati);
			break;

			case 3:
				displayMenu(list_panjabi,prize_panjabi);
			break;

			case 4:
				displayMenu(list_chainies,prize_chainies);
			break;

			case 5:
				displayMenu(list_tea,prize_tea);
			break;
			case 6:
				displayMenu(list_icecream,prize_icecream);
			break;
			case 7:
				displayMenu(list_local,prize_local);
			break;

			case 10:
			System.out.println("Checking....");
			return(true);

			case 8:
				System.out.println("Exit");
			break;	


			default:
				System.out.println("ine.....plz agian");
			break;
		}
	   }while(8!=ch);
		return(false);
	}
	}




			void displayMenu(ArrayList list,ArrayList prize)
			{
				int i=1;
				boolean flag=true;
				Scanner sc = new Scanner(System.in);
				Iterator itr=list.iterator();
				Iterator itr1=prize.iterator();
				int j;
				do{
   				while(itr.hasNext())
				{  
  				System.out.println(" "+i+" "+itr.next()+"............................."+itr1.next()+"/-"+"...");
				i++;
				}
				j=i;
				if(flag=true){
				System.out.println("  "+j+". back<<");
				flag=false;
					}
				System.out.print("Enter choise : ");
				ch=sc.nextInt();
				if(ch<j){
				cbill+=prize.get(ch-1);
				}
				else
				{
					System.out.println("unavaible choise..........try again");
				}
				System.out.println("Current bill : "+cbill);
				}while(ch!=j);
			}
			void displayMainMenu(ArrayList list)
			{
				int i=1;
				Iterator itr1=list.iterator();
   				while(itr1.hasNext())
				{  
  				System.out.println("    "+i+"."+itr1.next());
				i++;
				}
			}
			void editprofile(){
						Scanner sc = new Scanner(System.in);
						System.out.println("_____________Edit profilr_____________");
						System.out.println("1.change hotel name");
						System.out.print("Enter your choise : ");
						ch=sc.nextInt();
						switch(ch)
						{	
							case 1:
								System.out.print("Enter new name of hotel : ");
								hotelName=sc.next();
						}
					}
		void removeitem()
		{


			Scanner sc = new Scanner(System.in);
			boolean flag0,flag1;
			String Item;
			int prize;
			int ch;
			displayMainMenu(main_menu);
			System.out.print("Which catogeory : ");
			ch=sc.nextInt();
			System.out.print("Enter intem name to be remove : ");
			Item=sc.next();
			switch(ch)
			{

				case 1:
					int i,j;
					boolean flag;
			      		for(i=0;i<list_southIndian.size();i++)
					{
						flag=list_southIndian.get(i).equals(Item);
						if(flag==true)
						{
							list_southIndian.remove(i);
							prize_southIndian.remove(i);
						}

					}	
				break;

				case 2:
			      		for(i=0;i<list_gujarati.size();i++)
					{
						flag=list_gujarati.get(i).equals(Item);
						if(flag==true)
						{
							list_gujarati.remove(i);
							prize_gujarati.remove(i);
						}

					}
				break;

				case 3:


			      		for(i=0;i<list_chainies.size();i++)
					{
						flag=list_chainies.get(i).equals(Item);
						if(flag==true)
						{
							list_chainies.remove(i);
							prize_chainies.remove(i);
						}

					}
				break;

				case 4:


			      		for(i=0;i<list_panjabi.size();i++)
					{
						flag=list_panjabi.get(i).equals(Item);
						if(flag==true)
						{
							list_panjabi.remove(i);
							prize_panjabi.remove(i);
						}

					}
				break;
				case 5:


			      		for(i=0;i<list_tea.size();i++)
					{
						flag=list_tea.get(i).equals(Item);
						if(flag==true)
						{
							list_tea.remove(i);
							list_tea.remove(i);
						}

					}

				break;

				case 6:

			      		for(i=0;i<list_icecream.size();i++)
					{
						flag=list_icecream.get(i).equals(Item);
						if(flag==true)
						{
							list_icecream.remove(i);
							prize_icecream.remove(i);
						}

					}
				break;
				case 7:
					for(i=0;i<list_local.size();i++)
					{
						flag=list_local.get(i).equals(Item);
						if(flag==true)
						{
							list_local.remove(i);
							prize_local.remove(i);
						}

					}
				break;
				default:
					System.out.println("_______Invalid choise_______");
				break;	
			}
		}	
		void additem()
		{
			Scanner sc = new Scanner(System.in);
			boolean flag;
			String Item;
			int prize;
			int ch;
			System.out.print("Enter intem name to be Add : ");
			Item=sc.next();
			System.out.print("Enter Prize of Item : ");
			prize=sc.nextInt();
			System.out.println("__________catageory____________");
			System.out.println("1.South Indian");
			System.out.println("2.Gujarati");
			System.out.println("3.chainies");
			System.out.println("4.panjabi");
			System.out.println("5.tea");
			System.out.println("6.icecrime");
			System.out.println("7.Local of kutch");
			System.out.print("Which catogeory : ");
			ch=sc.nextInt();
			switch(ch)
			{

				case 1:
					list_southIndian.add(Item);
					prize_southIndian.add(prize);
				break;

				case 2:
					list_gujarati.add(Item);
					prize_gujarati.add(prize);
				break;

				case 3:
					list_chainies.add(Item);
					prize_chainies.add(prize);
				break;

				case 4:
					list_panjabi.add(Item);
					prize_panjabi.add(prize);
				break;

				case 5:
					list_icecream.add(Item);
					prize_icecream.add(prize);
				break;

				case 6:
					list_local.add(Item);
					prize_local.add(prize);
				break;
				default:
					System.out.println("_______Invalid choise1_______");
				break;	
			}
		}
}
