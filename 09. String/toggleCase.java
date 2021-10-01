/* Refer question here
https://www.pepcoding.com/resources/online-java-foundation/string,-string-builder-and-arraylist/toggle-case-official/ojquestion

1. You are given a string that contains only lowercase and uppercase alphabets. 
2. You have to toggle the case of every character of the given string.

Sample Input:
pepCODinG
Sample Output:
PEPcodINg
*/

import java.io.*;
import java.util.*;
public class toggleCase {

	public static String toggleCase(String str){
		//write your code here
		String toggled="";
		for(int i=0;i<str.length();i++){
		    char letter=str.charAt(i);
		    if(Character.isUpperCase(letter)){
		        letter=Character.toLowerCase(letter);
		    }
		    else{
		        letter=Character.toUpperCase(letter);
		    }
		    toggled=toggled+letter;
		}

		return toggled;
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(toggleCase(str));
	}

}

