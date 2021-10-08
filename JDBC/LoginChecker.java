package AJava;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Objects;

public class LoginChecker {
    public static void main(String[] args)
    {
        String[] cat={"Student","Teacher"};
        JFrame jf=new JFrame("Login");
        jf.setLayout(new GridLayout(4,2));
        JLabel l=new JLabel("Username");
        JTextField jt=new JTextField();
        JLabel l2=new JLabel("Password");
        JTextField jt2=new JTextField();
        JLabel l3=new JLabel("Category");
        JButton b=new JButton("Submit");
        JButton b1=new JButton("Reset");
        JComboBox j1=new JComboBox(cat);
        j1.setSelectedIndex(-1);
        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean check=false;
                for(int i=0;i<jt2.getText().length();i++)
                {
                    if(Character.isDigit(jt2.getText().charAt(i)))
                    {
                        check=true;
                        break;
                    }
                }
                if(jt.getText().length()==0||jt2.getText().length()==0||j1.getSelectedItem()==null)
                {
                    JOptionPane.showMessageDialog(jf,"Fill all the details","Alert",JOptionPane.WARNING_MESSAGE);
                }else if(!check||jt2.getText().length()<8)
                {
                    JOptionPane.showMessageDialog(jf,"Your password should contain 1 digit and 8 characters long","Wrong Password",JOptionPane.WARNING_MESSAGE);
                }
                System.out.println(j1.getSelectedItem()+" "+jt.getText()+" "+jt2.getText());
                if(jt.getText().equals("Student") && jt2.getText().equals( "Student1") &&j1.getSelectedItem().equals("Student"))
                {
                    JOptionPane.showMessageDialog(jf,"Successfully Login");
                }else
                {
                    JOptionPane.showMessageDialog(jf,"Login failed");
                }
            }
        });
//b1.addActionListener(new login());
        jf.add(l);
        jf.add(jt);
        jf.add(l2);
        jf.add(jt2);
        jf.add(l3);
        jf.add(j1);
        jf.add(b);
        jf.add(b1);
        jf.setSize(300,300);
        jf.setVisible(true);
        jf.setDefaultCloseOperation(jf.EXIT_ON_CLOSE);

    }

}
