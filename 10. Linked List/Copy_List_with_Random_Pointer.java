//138. Copy List with Random Pointer

public class Copy_List_with_Random_Pointer {
    public class Node {
        int val;
        Node next;
        Node random;

        Node() {
        }

        Node(int val) {
            this.val = val;
        }

        Node(int val, Node next) {
            this.val = val;
            this.next = next;
        }
    }

    public Node copyRandomList(Node head) {
        if(head == null)return null;
        Copynodes(head);
        SetRandom(head);
        return extractLL(head);
    }
    public void Copynodes(Node head){
        Node curr = head;
        
        while(curr != null){
            Node forw = curr.next;
            Node copy = new Node(curr.val);
            curr.next = copy;
            copy.next = forw;
            curr = forw;
        }
    }
    public void SetRandom(Node head){
        Node curr = head;
        while(curr != null){
            if(curr.random != null)
            curr.next.random = curr.random.next;
            curr = curr.next.next;
        }
    }
    public Node extractLL(Node head){
        Node dummy = new Node(-1);
        Node curr = head;
        Node copy = dummy;
        
        while(curr != null){
            copy.next = curr.next;
            copy = copy.next;
            curr.next = curr.next.next;
            curr = curr.next;
        }
        return dummy.next;
    }
}
