package hashMapDemo;

public class GetHashValue {

	public static void main(String[] args) {
		
		System.out.println(getHash("Python"));
		System.out.println(getHash("Java"));
		System.out.println(getHash("Cpp"));
		System.out.println(getHash("C"));
		
		// Python   Java  Cpp  JavaScript C
	}
	
	public static int getHash(String s) {
		int hash = 0;
		for (int i = 0; i < s.length(); i++) {
			hash += s.charAt(i);
		}
		return hash;
	} 
}
