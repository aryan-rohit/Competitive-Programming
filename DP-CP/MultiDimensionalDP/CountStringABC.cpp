// Problem Name: Count of strings that can be formed using a, b and c under given constraints
// Problem Difficulty: 
// Problem Constraints: 1 <= n < 5*10^5
// Problem Description:
// A beautiful string is one that can be formed using a, b and c  with at-most one ‘b’ and two ‘c’s allowed.

// Given a length n, count the number of beautiful strings of length n.

// Input Format: First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.
// Sample Input: 1
// 3

// Output Format: Output t lines each line describing the answer.
// Sample Output: 19



// =====Solution=====
#include <bits/stdc++.h>
using namespace std;

int countStrUtil(int dp[][2][3], int n, int bCount = 1, int cCount = 2)
{
    // Base cases
    if (bCount < 0 || cCount < 0)
        return 0;
    if (n == 0)
        return 1;
    if (bCount == 0 && cCount == 0)
        return 1;

    // if we had saw this combination previously
    if (dp[n][bCount][cCount] != -1)
        return dp[n][bCount][cCount];

    int res = countStrUtil(dp, n - 1, bCount, cCount);
    res += countStrUtil(dp, n - 1, bCount - 1, cCount);
    res += countStrUtil(dp, n - 1, bCount, cCount - 1);

    return (dp[n][bCount][cCount] = res);
}


int countStr(int n)
{
    int dp[n + 1][2][3];
    memset(dp, -1, sizeof(dp));
    return countStrUtil(dp, n);
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        cout << countStr(n) << endl;
    }

    return 0;
}