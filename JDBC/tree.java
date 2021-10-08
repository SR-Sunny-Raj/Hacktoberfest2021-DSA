package AJava;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;

public class tree {
    public static void main(String[] args)
    {
        JFrame frame=new JFrame("Tree");
        JTree tree;
        DefaultMutableTreeNode root=new DefaultMutableTreeNode("Rakhi jha");
        DefaultMutableTreeNode rl=new DefaultMutableTreeNode("Personal");
        DefaultMutableTreeNode rr=new DefaultMutableTreeNode("Academic");
        DefaultMutableTreeNode rll=new DefaultMutableTreeNode("Rakhi jha");
        DefaultMutableTreeNode rlr=new DefaultMutableTreeNode("1103");
        DefaultMutableTreeNode rrl=new DefaultMutableTreeNode("9.3 CGPA");
        DefaultMutableTreeNode rrr=new DefaultMutableTreeNode("9.6 CGPA");
        root.add(rl);
        root.add(rr);
        rl.add(rll);
        rl.add(rlr);
        rr.add(rrl);
        rr.add(rrr);
        tree=new JTree(root);
        frame.add(tree);

        frame.setSize(200,200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
