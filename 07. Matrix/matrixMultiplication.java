import java.util.*;
public class matrixMultiplication {
	private static final int MODULUS = (int)1e9 + 7;
    public static void main(String[] args) {

    	int[][] b = { {2,3,1,6},
    			{4,0,0,2},
    			{4,2,0,1},
    			{0,3,5,2}
    	};
    	int[][] c = { {3,0,4,3},
    			{1,2,0,2},
    			{0,3,1,4},
    			{5,1,3,2}
    	};
    	int[][]a = multiply(b,c);

    	for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++)
                System.out.print( a[i][j] + " ");
            System.out.println();
        }
    }
    public static int[][] multiply(int[][] A, int[][] B) {
        int m = A.length, n = A[0].length, nB = B[0].length;
        int[][] result = new int[m][nB];

        List[] indexA = new List[m];
        for(int i = 0; i < m; i++) {
            List<Integer> numsA = new ArrayList<>();
            for(int j = 0; j < n; j++) {
                if(A[i][j] != 0){
                    numsA.add(j); 
                    numsA.add(A[i][j]);
                }
            }
            indexA[i] = numsA;
        }

        for(int i = 0; i < m; i++) {
            List<Integer> numsA = indexA[i];
            for(int p = 0; p < numsA.size() - 1; p += 2) {
                int colA = numsA.get(p);
                int valA = numsA.get(p + 1);
                for(int j = 0; j < nB; j ++) {
                    int valB = B[colA][j];
                    result[i][j] += valA * valB;
                }
            }
        }

        return result;   
    }
 }