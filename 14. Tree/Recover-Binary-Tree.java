class Solution {


  TreeNode prev = null;
  TreeNode a = null;
  TreeNode b = null;

  public void recoverTree(TreeNode root) {

    inorder(root);
    int temp = a.val;
    a.val = b.val;
    b.val = temp;

  }

  private void inorder(TreeNode root) {

    if (root == null) {
      return;
    }
    inorder(root.left);
    if (prev != null && prev.val > root.val) {
      if (a == null) {
        a = prev;
      }
      b = root;
    }
    prev = root;
    inorder(root.right);

  }

  public class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
      this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }
}
