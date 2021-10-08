package AJava;


// import statement
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AddSubjectChecker
{
    JFrame frameObj;

    // constructor
    AddSubjectChecker()
    {
        // creating a frame object
        frameObj = new JFrame();
        String[] s1={"CSE","MCE","ECE","BSC","LLB"};
        String[] s2={"1","2","3","4","5","6","7","8"};
        // creating the buttons
        JLabel l= new JLabel("Add Subject");
        JLabel l1= new JLabel("Subject Name");
        JTextField t1=new JTextField();
        JLabel l2= new JLabel("Subject Code");
        JTextField t2=new JTextField();
        JLabel l3= new JLabel("Branch");
        JComboBox c=new JComboBox(s1);
        JLabel l4= new JLabel("Semester");
        JComboBox c1=new JComboBox(s2);

        JButton b2 = new JButton("Add Subject");

        c.setSelectedIndex(-1);
        c1.setSelectedIndex(-1);

        // adding the buttons to frame
        frameObj.add(l);
        frameObj.add(l1);
        frameObj.add(t1);
        frameObj.add(l2);
        frameObj.add(t2); frameObj.add(l3);  frameObj.add(c);  frameObj.add(l4);
        frameObj.add(c1);
        frameObj.add(b2);


        frameObj.setLayout(null);

        l.setBounds(100,10,100,30);
        l1.setBounds(10,50,100,30);
        t1.setBounds(130,50,150,30);
        l2.setBounds(10,100,100,30);
        t2.setBounds(130,100,150,30);
        l3.setBounds(10,150,50,30);
        c.setBounds(130,150,100,30);
        l4.setBounds(10,200,100,30);
        c1.setBounds(130,200,50,30);
        b2.setBounds(100,250,120,30);

        b2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(t1.getText().length()==0||t2.getText().length()==0|| c.getSelectedItem() == null || c1.getSelectedItem() == null)
                {
                    JOptionPane.showMessageDialog(frameObj,"Fill all the details","Alert",JOptionPane.WARNING_MESSAGE);
                }else
                {
                    JOptionPane.showMessageDialog(frameObj,t1.getText()+" "+t2.getText()+" "+c.getSelectedItem()+" "+c1.getSelectedItem());
                }
            }
        });






        frameObj.setSize(300, 400);
        frameObj.setVisible(true);
        frameObj.setDefaultCloseOperation(frameObj.EXIT_ON_CLOSE);
    }
    // main method
    public static void main(String args[])
    {
        new AddSubjectChecker();
    }
}