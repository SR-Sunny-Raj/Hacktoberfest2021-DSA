import java.util.Scanner;

public class pattern {
    static class Node {
        int data;
        Node next, prev;

        Node(int data) {
            this.data = data;
            next = prev = null;
        }
    }

    static class DoublyLinkedList {
        Node head, tail;

        void insert(int data) {
            Node toAdd = new Node(data);
            if (head == null) {
                head = toAdd;
                tail = head;
            } else {
                tail.next = toAdd;
                toAdd.prev = tail;
                tail = tail.next;
            }
        }

        void deleteTail() {
            if (tail == null) {
                System.err.println("List is empty.");
                return;
            }
            tail = tail.prev;
            tail.next = null;
        }

        void printList() {
            Node temp = head;
            while (temp.next != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.prev;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int n = sc.nextInt();
        sc.close();
        DoublyLinkedList list = new DoublyLinkedList();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                System.out.print("  ");
            }
            list.insert(n - i);
            list.printList();
            System.out.println();
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("  ");
            }
            list.deleteTail();
            list.printList();
            System.out.println();
        }

    }

}