import java.util.*;
class LinkedList {
    static Node head;
    static class Node {
        int data;
        Node next,prev;
        Node(int d) {
            data = d;
            next = prev=null;
        }
    }
    static class bnode{
        int data;
        bnode left,right;
        bnode(int d){
            data=d;
            left=right=null;
        }
    }
    public static LinkedList insert(LinkedList list, int data) {
        LinkedList.Node new_node = new LinkedList.Node(data);
        new_node.next = null;
        if (list.head == null) {
            list.head = new_node;
        } else {
            LinkedList.Node last = list.head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = new_node;
        }
        return list;
    }
    public static void printlist(LinkedList list) {
        LinkedList.Node temp = list.head;
        System.out.println("Linked list:");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    bnode convert(){
    int n=count(head);
    return sortedbst(n);
    }
    bnode sortedbst(int n){
    if (n<=0)
    return null;
    bnode left=sortedbst(n/2);
    bnode root=new bnode(head.data);
    root.left=left;
    head=head.next;
    root.right=sortedbst(n-n/2-1);
    return root;
    }
    void preorder(bnode n) {
        if (n == null) {
            return;
        }
        System.out.print(n.data + " ");
        preorder(n.left);
        preorder(n.right);
    }
    void inorder(bnode n) {
        if (n == null) {
            return;
        }
        inorder(n.left);
        System.out.print(n.data + " ");
        inorder(n.right);
    }
    void postorder(bnode n) {
        if (n == null) {
            return;
        }
        postorder(n.left);
        postorder(n.right);
        System.out.print(n.data + " ");
    }
     int count(Node head) {
        Node temp = head;
        int c = 0;
        while (temp != null) {
            c++;
            temp = temp.next;
        }
        return c;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList ll = new LinkedList();
        ll = insert(ll, 2);
        ll = insert(ll, 5);
        ll = insert(ll, 6);
        ll = insert(ll, 8);
        ll = insert(ll, 1);
        ll = insert(ll, 3);
        ll = insert(ll,9);
        printlist(ll);
        bnode r=ll.convert();
        System.out.println("The traversal of the tree are:");
        System.out.println("Preorder Traversal:");
        ll.preorder(r);
        System.out.println();
        System.out.println("Inorder Traversal:");
        ll.inorder(r);
        System.out.println();
        System.out.println("Postorder Traversal:");
        ll.postorder(r);
}
}
