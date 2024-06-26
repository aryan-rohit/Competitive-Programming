// Problem Name: 0-N Knapsack
// Problem Difficulty: None
// Problem Constraints: 1 <= n,cap <= 1000
// 1 <= wt[i] <= cap
// 1 <= val[i] <= 100000
// Problem Description:


// You've heard of 0-1 knapsack. Below is the problem statement for the same.<br><br>
// Given weights and values of n items, put these items in a knapsack of capacity <b><i>cap</i></b> to get the maximum total value in the knapsack. In other words, given two integer arrays <b><i>val[0..n-1]</i></b> and <b><i>wt[0..n-1]</i></b> which represent values and weights associated with n items respectively. Also given an integer <b><i>cap</i></b> which represents knapsack capacity, find out the maximum value subset of <b><i>val[]</i></b> such that sum of the weights of this subset is smaller than or equal to <b><i>cap</i></b>. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).<br>
// There is a little twist for 0-N knapsack. You can pick an element more than once. Now you have to find maximum value multi subset of <b><i>val[]</i></b> such that sum of the weights of this subset is smaller than or equal to <b><i>cap</i></b>.<br>

// Note: Maximum value subset means the sunset with maximum sum of all the values in subset.


// Input Format: The first line contains two integers, representing <b><i>n</i></b>(size of <b><i>val[]</i></b>) and <b><i>cap</i></b> respectively. The subsequent line contains <b><i>n</i></b> integers representing the <b><i>wt[]</i></b> array. The next line, again, contains <b><i>n</i></b> integers representing the <b><i>val[]</i></b> array.
// Sample Input: 5 11
// 3 2 4 5 1
// 4 3 5 6 1
// Output Format: Print a single integer, the answer to the problem.
// Sample Output: 16



// =====Solution=====
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

ll dp[1010][1010],n,cap,wt[1010],val[1010];
int main(){
//	freopen("input2.txt","r",stdin);
//	freopen("output2.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>n>>cap;
	for(int i=1;i<=n;i++)
		cin>>wt[i];
	for(int i=1;i<=n;i++)
		cin>>val[i];
	
	for(int i=0;i<=cap;i++)
		dp[i][0] = 0;
	for(int j=1;j<=n;j++)
		dp[0][j] = 0;
	
	for(int i=1;i<=cap;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = dp[i][j-1];
			if(wt[j] <= i)
				dp[i][j] = max(dp[i][j], val[j]+dp[i-wt[j]][j]);
		}
	}
	cout<<dp[cap][n];
	
	return 0;
}
