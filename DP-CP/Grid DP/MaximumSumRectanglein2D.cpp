// Problem Name: Maximum sum rectangle in a 2D matrix
// Problem Difficulty: 3
// Problem Constraints: 1 <= T <= 10<br>
// 1 <= n,m <= 10<br>
// 0 <= A[i] <= 1000

// Problem Description:
// You are given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, the maximum sum 2D subarray is highlighted with small rectangle and sum of this 2D subarray is 29.

// ![Imgur](https://i.imgur.com/Dz5pI6x.png)

// Input Format: The first line consists of number of test cases T. For each test case,  consists two integers n and m as dimension of 2D array and next n lines contain m space separated integers .

// Sample Input: 1
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6

// Output Format: Print the maximum subarray sum.

// Sample Output: 29



// =====Solution=====
// import java.util.*;
// import java.lang.*;
// import java.io.*;

// /**
// * Given a 2D array, find the maximum sum subarray in it
// */
// class code
// {
// 	public static void main (String[] args) throws java.lang.Exception
// 	{
// 		Scanner input = new Scanner(System.in);

// 		int t;
// 		t = input.nextInt();
// 		for(int i=0;i<t;i++)
// 		{
// 			int n,m;
// 			n = input.nextInt();
// 			m = input.nextInt();
// 			int a[][] = new int[n][m];
// 			for(int j=0;j<n;j++)
// 			{
// 				for(int k=0;k<m;k++)
// 				{
// 					a[j][k]=input.nextInt();
// 				}
// 			} 
// 			findMaxSubMatrix(a);
// 		}

// 		// findMaxSubMatrix(new int[][] {
// 		// 					{1, 2, -1, -4, -20},
// 		// 					{-8, -3, 4, 2, 1},
// 		// 					{3, 8, 10, 1, 3},
// 		// 					{-4, -1, 1, 7, -6}
// 		// 					});
// 	}
	
// 	/**
// 	* To find maxSum in 1d array
// 	* 
// 	* return {maxSum, left, right}
// 	*/
// 	public static int[] kadane(int[] a) {
// 		//result[0] == maxSum, result[1] == start, result[2] == end;
// 		int[] result = new int[]{Integer.MIN_VALUE, 0, -1};
// 		int currentSum = 0;
// 		int localStart = 0;
	
// 		for (int i = 0; i < a.length; i++) {
// 			currentSum += a[i];
// 			if (currentSum < 0) {
// 				currentSum = 0;
// 				localStart = i + 1;
// 			} else if (currentSum > result[0]) {
// 				result[0] = currentSum;
// 				result[1] = localStart;
// 				result[2] = i;
// 			}
// 		}
		
// 		//all numbers in a are negative
// 		if (result[2] == -1) {
// 			result[0] = 0;
// 			for (int i = 0; i < a.length; i++) {
// 				if (a[i] > result[0]) {
// 					result[0] = a[i];
// 					result[1] = i;
// 					result[2] = i;
// 				}
// 			}
// 		}
		
// 		return result;
// 	}

// 	/**
// 	* To find and print maxSum, (left, top),(right, bottom)
// 	*/
// 	public static void findMaxSubMatrix(int[][] a) {
// 		int cols = a[0].length;
// 		int rows = a.length;
// 		int[] currentResult;
// 		int maxSum = Integer.MIN_VALUE;
// 		int left = 0;
// 		int top = 0;
// 		int right = 0;
// 		int bottom = 0;
		
// 		for (int leftCol = 0; leftCol < cols; leftCol++) {
// 			int[] tmp = new int[rows];
	
// 			for (int rightCol = leftCol; rightCol < cols; rightCol++) {
		
// 				for (int i = 0; i < rows; i++) {
// 					tmp[i] += a[i][rightCol];
// 				}
// 				currentResult = kadane(tmp);
// 				if (currentResult[0] > maxSum) {
// 					maxSum = currentResult[0];
// 					left = leftCol;
// 					top = currentResult[1];
// 					right = rightCol;
// 					bottom = currentResult[2];
// 				}
// 			}
// 		}
// 		System.out.println(maxSum);
// 	// 		System.out.println("MaxSum: " + maxSum + 
// 	// 							", range: [(" + left + ", " + top + 
// 	// 							")(" + right + ", " + bottom + ")]");
// 	// }
// }
// }
