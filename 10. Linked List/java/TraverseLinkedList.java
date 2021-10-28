class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class TraverseLinkedList {

    // Iterative
    public static void iterativePrintList(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.println(curr.data + "");
            curr = curr.next;
        }
    }

    // Recursive
    static void recursivePrintList(Node head) {
        if (head == null) {
            return;
        }
        System.out.println(head.data + "");
        recursivePrintList(head.next);
    }

    public static void main(String[] args) {
        Node head = new Node(10);
        head.next = new Node(20);
        head.next.next = new Node(30);
        head.next.next.next = new Node(50);
        recursivePrintList(head);
        iterativePrintList(head);
    }
}
