// Problem Name: Money Change 
// Problem Difficulty: None
// Problem Constraints: 1 <= T <= 10
// 1 <= n <= 500
// 1 <= S[i] <= 1000
// 1 <= N <= 1000000
// Problem Description:










// Given a big amount <b>N</b> and the array of denominations <b>S</b>. Assuming infinite supply of each of S = {S1,S2....Sm} denominations, find the number of ways to make change for <b>N</b> cents.

// Input Format: 

// First line contains an integer <b>T</b> denoting the total number of test cases.<br />
// For every test case, there are three lines. <br />
// First line will contain an integer 'M' denoting the size of array. <br />
// The second line contains M space-separated integers A1, A2, ..., Am denoting the elements of the array. <br /> The third line contains an integer 'N' denoting the cents. <br />
// Sample Input: 2
// 3
// 1 2 3
// 4
// 4
// 2 5 3 6
// 10
// Output Format: Print number of possible ways to make change for N cents in a new line.
// Since answers can be large, print answer % (1000000000 + 7).
// Sample Output: 4
// 5



// =====Solution=====
#include <iostream>
#define ll long long int
using namespace std;
#define mod 1000000007
ll CoinChangeBottomUp(int *coins, int value, int n) {
    ll *dp = new ll[value+1];
    dp[0] = 1;
    for(int i=0;i<=value;i++) {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=value;j++) {
            if (coins[i] <= j)
                dp[j] = ((dp[j]%mod)+ (dp[j-coins[i]]%mod))%mod;
        }
    }
    int temp=dp[value];
    delete [] dp;
    return temp;
}

// int minCoinChangeTopDown(int *coins, int value, int n, int *dp) {
//     if(value<0) {
//         return INT_MAX;
//     }
//     if(value==0) {
//         dp[0] = 0;
//         return 0;
//     }
//     if(dp[value]!=0) {
//         return dp[value];
//     }
//     int currentVal = INT_MAX;
//     for(int i=0;i<n;i++) {
//         currentVal = min(currentVal, minCoinChangeTopDown(coins, value-coins[i], n, dp));
//     }

//     dp[value] = (currentVal==INT_MAX)?-1:1+currentVal;
//     return dp[value];
// }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--) {
    int n,s;
    cin>>n;
    int *coins = new int[n];
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }
    cin>>s;
    // int *dp = new int[5005];
    cout<<CoinChangeBottomUp(coins, s, n)<<endl;
    //delete [] dp;
}
return 0;
}
