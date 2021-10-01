import java.util.*;
class Node{
    int data;
    Node left,right;
    Node(int d){
        data=d;
        left=right=null;
    }
}
class Binary {
    static Node r;
    Node convert(int a[], int s, int e) {
        if (s > e) {
            return null;
        }
        int m = (s + e) / 2;
        Node root = new Node(a[m]);
        root.left = convert(a, s, m - 1);
        root.right = convert(a, m + 1, e);
        return root;
    }
    void preorder(Node n) {
        if (n == null) {
            return;
        }
        System.out.print(n.data + " ");
        preorder(n.left);
        preorder(n.right);
    }
    void inorder(Node n) {
        if (n == null) {
            return;
        }
        inorder(n.left);
        System.out.print(n.data + " ");
        inorder(n.right);
    }
    void postorder(Node n) {
        if (n == null) {
            return;
        }
        postorder(n.left);
        postorder(n.right);
        System.out.print(n.data + " ");
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Binary ob = new Binary();
        System.out.println("Enter the size of array:");
        int n = sc.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the elements of the Sorted array:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Array elements are:");
        for (int i = 0; i < n; i++) {
            System.out.println(a[i] + " ");
        }
        r = ob.convert(a, 0, n - 1);
        System.out.println("The traversal of the tree are:");
        System.out.println("Preorder Traversal:");
        ob.preorder(r);
        System.out.println();
        System.out.println("Inorder Traversal:");
        ob.inorder(r);
        System.out.println();
        System.out.println("Postorder Traversal:");
        ob.postorder(r);
    }
}
