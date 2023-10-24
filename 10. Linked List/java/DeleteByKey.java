
public class DeleteByKey {
	
	Node head;
	
	 static class Node{
		
		 int data;
		 Node next;
		 
		 Node(int d){
			 data = d;
			 next = null;
		 }
	}
	 
	 public static LinkedList insert(LinkedList list , int data) {
		 
		 Node new_node = new Node(data);
		 new_node.next = null;
		 
		 if(list.head == null) {
			 list.head = new_node;
		 }else {
			 Node last = list.head;
			 while(last.next != null) {
				 last = last.next;
			 }
			 last.next = new_node;
		 }
		 return list;
	 }
	 
	 public static void printList(LinkedList)

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
