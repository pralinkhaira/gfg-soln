//{ Driver Code Starts
import java.io.*;
import java.util.*;
class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int matrix[][] = new int[n][n];
            
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                  matrix[i][j] =sc.nextInt();
            }
            Solution ob = new Solution();
            System.out.println(ob.determinantOfMatrix(matrix, n));
        }
    }
}
// } Driver Code Ends

class Solution
{
    // Function for finding determinant of matrix.
    static int determinantOfMatrix(int matrix[][], int n)
    {
        // Initialize the determinant value.
        int det = 0;

        // Base case: If the matrix is of order 1, return its only element.
        if (n == 1) {
            return matrix[0][0];
        }
        // Base case: If the matrix is of order 2, return the determinant using the formula.
        else if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }

        // For matrices of order greater than 2, use cofactor expansion.
        for (int i = 0; i < n; i++) {
            // Create a submatrix by excluding the current row and column.
            int[][] b = new int[n - 1][n - 1];
            int l = 0, m = 0;

            // Fill in the values for the submatrix.
            for (int j = 1; j < n; j++) {
                m = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i) {
                        continue; // Skip the current column.
                    }
                    b[l][m] = matrix[j][k];
                    m++;
                }
                l++;
            }

            // Calculate the cofactor by multiplying the element with the determinant of the submatrix.
            int coFactor = matrix[0][i] * determinantOfMatrix(b, n - 1);

            // Add or subtract the cofactor based on the position in the matrix.
            if (i % 2 == 0) {
                det += coFactor;
            } else {
                det -= coFactor;
            }
        }

        // Return the determinant of the original matrix.
        return det;
    }
}
