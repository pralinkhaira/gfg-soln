//{ Driver Code Starts
// Initial Template for java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            int n = Integer.parseInt(S[0]);
            int m = Integer.parseInt(S[1]);
            int k = Integer.parseInt(S[2]);
            int mat[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                String S1[] = read.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    mat[i][j] = Integer.parseInt(S1[j]);
                }
            }
            Solution ob = new Solution();
            int ans[][] = ob.rotateMatrix(k, mat);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }
}

// } Driver Code Ends


// User function template for java

class Solution {
    // Function to rotate the given matrix by K columns
    int[][] rotateMatrix(int k, int mat[][]) {
        // Calculate the number of rows (n) and columns (m) from the matrix
        int n = mat.length;
        int m = mat[0].length;

        // Create a new matrix to store the rotated matrix
        int ans[][] = new int[n][m];

        // Reduce k to a value within the range of m to avoid unnecessary rotations...
        k %= m;

        // Iterate through each element of the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Calculate the new position for each element after rotation
                ans[i][(j - k + m) % m] = mat[i][j];
            }
        }

        // Return the rotated matrix
        return ans;
    }
}