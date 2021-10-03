import java.util.*;
class TreeNode<T>{
    T data;
    ArrayList<TreeNode<T>> children;
    TreeNode(T data){
        this.data = data;
        children = new ArrayList<>();
    }
}
public class Main
{
	public static void main(String[] args) {
	    TreeNode<Integer> root = new TreeNode<>(2);
	    TreeNode<Integer> node1 = new TreeNode<>(3);
	    TreeNode<Integer> node2 = new TreeNode<>(4);
	    TreeNode<Integer> node3 = new TreeNode<>(5);
	    TreeNode<Integer> node4 = new TreeNode<>(6);
	    TreeNode<Integer> node5 = new TreeNode<>(7);
	    root.children.add(node1);
	    root.children.add(node2);
	    root.children.add(node3);
	    node2.children.add(node4);
	    node2.children.add(node5);
	    print(root);
	    System.out.println(maxDepth(root));
	}
	public static void print(TreeNode<Integer> root){
	    String s = root.data + ":";
	    for(int i = 0; i < root.children.size(); i++){
	        s += root.children.get(i).data + " ";
	    }
	   System.out.println(s);
	   for(int i = 0; i < root.children.size(); i++){
	        print(root.children.get(i));
	    }
	}
	public static int maxDepth(TreeNode<Integer> root){
	    if(root == null) return 0;
	    else if(root.children.isEmpty()) return 1;
	    else{
	        int maxDepth = 0;
	        for(TreeNode<Integer> node : root.children) {
	            int currDepth = maxDepth(node);
	            if(currDepth > maxDepth){
	                maxDepth = currDepth;
	            }
	        }
	        return maxDepth + 1;
	    }
	}
}
