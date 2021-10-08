package AJava;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.regex.*;

public class FormChecker {
    public static void main(String[] args)
    {
        String[] s1={"CSE","MCE","ECE","BSC","LLB"};
        String[] s2={"1","2","3","4","5","6","7","8"};
        String[] date={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
        String[] month={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        String[] year={"2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020","2021"};
        JFrame frame=new JFrame();
        frame.setSize(500,700);
        frame.setResizable(false);
        JLabel l1=new JLabel("Student Registration form");
        JLabel l2=new JLabel("Name");
        JLabel l3=new JLabel("Age");
        JLabel l4=new JLabel("Gender");
        JLabel l5=new JLabel("Date Of Birth");
        JLabel l6=new JLabel("Address");
        JLabel l7=new JLabel("Roll No");
        JLabel l8=new JLabel("Branch");
        JLabel l9=new JLabel("Semester");
        JLabel l10=new JLabel("Contact");
        JLabel l11=new JLabel("Email");
        TextField t1=new TextField();
        TextField t2=new TextField();
        TextField t3=new TextField();
        TextField t4=new TextField();
        TextField t5=new TextField();
        TextField t6=new TextField();
        JRadioButton b1=new JRadioButton("Male");
        JRadioButton b2=new JRadioButton("Female");

        ButtonGroup G = new ButtonGroup();
        G.add(b1);
        G.add(b2);


        JComboBox j1=new JComboBox(s1);
        JComboBox j2=new JComboBox(s2);
        JComboBox JDate=new JComboBox(date);
        JComboBox JMonth=new JComboBox(month);
        JComboBox JYear=new JComboBox(year);

        j1.setSelectedIndex(-1);
        j2.setSelectedIndex(-1);
        JDate.setSelectedIndex(-1);
        JMonth.setSelectedIndex(-1);
        JYear.setSelectedIndex(-1);

        JButton b=new JButton("Submit");


        frame.add(l1);
        frame.add(l2);
        frame.add(t1);
        frame.add(l3);
        frame.add(t2);
        frame.add(l4);
        frame.add(b1);
        frame.add(b2);
        frame.add(l5);
        frame.add(JDate);
        frame.add(JMonth);
        frame.add(JYear);
        frame.add(l6);
        frame.add(t3);
        frame.add(l7);
        frame.add(t4);
        frame.add(l8);
        frame.add(j1);
        frame.add(l9);
        frame.add(j2);
        frame.add(l10);
        frame.add(t5);
        frame.add(l11);
        frame.add(t6);
        frame.add(b);

        frame.setLayout(null);
        l1.setBounds(150,10,800,50);
        l2.setBounds(100,70,50,30);
        t1.setBounds(200,70,200,30);
        l3.setBounds(100,130,50,30);
        t2.setBounds(200,130,200,30);
        l4.setBounds(100,200,100,30);
        b1.setBounds(200,200,80,30);
        b2.setBounds(300,200,80,30);
        l5.setBounds(40,250,100,30);
        JDate.setBounds(150,250,100,30);
        JMonth.setBounds(260,250,100,30);
        JYear.setBounds(370,250,100,30);
        l6.setBounds(100,300,100,30);
        t3.setBounds(200,300,200,30);
        l7.setBounds(100,350,100,30);
        t4.setBounds(200,350,200,30);
        l8.setBounds(100,400,100,30);
        j1.setBounds(200,400,100,30);
        l9.setBounds(100,450,100,30);
        j2.setBounds(200,450,100,30);
        l10.setBounds(100,500,100,30);
        t5.setBounds(200,500,200,30);
        l11.setBounds(100,550,100,30);
        t6.setBounds(200,550,200,30);
        b.setBounds(150,600,200,30);

        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(t1.getText().length()==0||t2.getText().length()==0||t3.getText().length()==0||t4.getText().length()==0||t5.getText().length()==0||t6.getText().length()==0||G.getSelection().equals("null")||JDate.getSelectedItem().equals(null)||JYear.getSelectedItem().equals(null)||JMonth.getSelectedItem().equals("null")||j1.getSelectedItem().equals(null)||j2.getSelectedItem().equals(null))
                {
                    JOptionPane.showMessageDialog(frame,"Please Fill all the details","Alert",JOptionPane.WARNING_MESSAGE);
                }else if(!Pattern.matches("[0-9]*$",t2.getText()))
                {
                    JOptionPane.showMessageDialog(frame,"Age should be numeric","Age",JOptionPane.WARNING_MESSAGE);
                }else if(!Pattern.matches("[0-9]*$",t5.getText()))
                {
                    JOptionPane.showMessageDialog(frame,"Contact Number should be numeric","Contact Number",JOptionPane.WARNING_MESSAGE);
                }else if(!Pattern.matches("^[a-zA-z0-9]+[@]{1}+[a-zA-z0-9]+[.]{1}+[a-zA-z0-9]+$",t6.getText().trim()))
                {
                    JOptionPane.showMessageDialog(frame,"Invalid Email","Contact Number",JOptionPane.WARNING_MESSAGE);
                }
            }
        });


        frame.setVisible(true);
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
    }
}
