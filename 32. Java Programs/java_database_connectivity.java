package <enter_database_package>;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

class TestDatabase28 
{
    public static void main(String args[]) 
    {
        Connection con = null;
        Statement st = null;
        ResultSet rs = null;

        try 
        {
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            System.out.println("Driver Loaded");

            con = DriverManager.getConnection("jdbc:odbc:db28");
            System.out.println("Connected");

            st = con.createStatement();

            String query = "Select * from emp";

            rs = st.executeQuery(query);

            while (rs.next()) 
            {
                System.out.print(rs.getString(1) + "\t");
                System.out.print(rs.getString(2) + "\t");
                System.out.print(rs.getString(3) + "\t");
                System.out.println(rs.getString(4));
            }
            con.close();
        } 
        catch (ClassNotFoundException e) 
        {
            System.out.println(e);
        } 
        catch (SQLException e)
        {
            System.out.println(e);
        }
    }
}
