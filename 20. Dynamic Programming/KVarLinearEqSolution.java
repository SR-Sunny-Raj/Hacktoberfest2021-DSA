/* 
 Problem Statement: 
 Given a linear equation of k variables,count total number of possible solutions to it.
 
  
 Input:  coeff = {1, 2, 3}, rhs = 4
 
 Output: The total number of solutions is 4
 
 Above input represents the equation x + 2y + 3z = 4.
	 
	( x = 1, y = 0, z = 1 )
	( x = 0, y = 2, z = 0 )
	( x = 2, y = 1, z = 0 )
	( x = 4, y = 0, z = 0 ) 
	
*/

public class KVarLinearEqSolution
{
    // Function to count the total number of possible solutions to a
    // linear equation of `k` variables
    public static int count(int[] coeff, int k, int rhs)
    {
        // if rhs become 0, a solution is found
        if (rhs == 0) {
            return 1;
        }
 
        // return 0 if rhs becomes negative or no coefficient is left
        if (rhs < 0 || k < 0) {
            return 0;
        }
 
        // Case 1. Include current coefficient `coeff[k]` in solution and
        // recur with remaining value `rhs-coeff[k]`
        int include = count(coeff, k, rhs - coeff[k]);
 
        // Case 2. Exclude current coefficient `coeff[k]` from solution and
        // recur for remaining coefficients `k-1`
        int exclude = count(coeff, k - 1, rhs);
 
        // return total ways by including or excluding the current coefficient
        return include + exclude;
    }
 
	// Driver code
    public static void main (String[] args)
    {
		
        // `k` coefficients of the given equation
        
        int[] coeff = { 1, 2, 3 };
        int k = coeff.length;
 
        int rhs = 4;
 
        System.out.println("The total number of solutions is " +
            count(coeff, k - 1, rhs));
    }
}
