// Problem Name: Maximum Xor Permutation
// Problem Difficulty: 
// Problem Constraints: 1 ≤ T ≤ 250
// Problem Description:
// A bitwise XOR takes two bit patterns of equal length and performs the logical exclusive OR operation on each pair of corresponding bits. The result in each position is 1 if both bits are different (only one of them is 1 and the other is 0), but will be 0 if both bits are the same (both are 0 or both are 1). For example, the bitwise XOR of the patterns 0101 and 1100 is 1001.

// In this problem, you are given 3 binary strings of lengths 10 digits such that all digits are either 0 or 1. You can swap any two digits in the same string infinitely, but you cannot swap two digits from two different strings.

// Your task is to rearrange digits in the given strings in a way such that the bitwise XOR of the strings after rearranging their digits is as largest as possible. Can you?

// Input Format: The first line contains an integer T specifying the number of test cases.

// Each test case consists of 3 lines each of which contains a binary string of length 10 digits such that all digits are either 0 or 1.


// Sample Input: 2
// 0000101011
// 0001010101
// 0010010000
// 1000000010
// 0001000100
// 1001000000
// Output Format: For each test, print a single line containing a binary string of length 10 representing the largest value of bitwise XOR that can be optioned by rearranging digits in each string.

// A binary string x is larger than a binary string y if after converting both strings to the decimal representation, the decimal value of string x is larger than the decimal value of string y. For example, string "1100" is larger than string "0101" because its decimal value 12, while the decimal value of string "0101" is 5.


// Sample Output: 1111111111
// 1111110000



// =====Solution=====
// null

//dp(i,x1,x2,x3) 
//ans till ith index and we have x1,x2,x3 set bits left