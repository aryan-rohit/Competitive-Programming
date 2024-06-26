// Problem Name: Colorful Knapsack
// Problem Difficulty: None
// Problem Constraints: 1 ≤ M ≤ 100
// M ≤ N ≤ 100
// 1 ≤ W[i] ≤ 100
// 1 ≤ C[i] ≤ M
// 1 ≤ X ≤ 10000
// Problem Description:
// You are given <b><i>N</i></b> stones, labeled from 1 to <b><i>N</i></b>. The i-th stone has the weight <b><i>W[i]</i></b>. There are <b><i>M</i></b> colors, labeled by integers from 1 to <b><i>M</i></b>. The i-th stone has the color <b><i>C[i]</i></b> (of course, an integer between 1 to <b><i>M</i></b>, inclusive).
// You want to fill a Knapsack with these stones. The Knapsack can hold a total weight of <b><i>X</i></b>. You want to select exactly <b><i>M</i></b> stones; one of each color. The sum of the weights of the stones must not exceed <b><i>X</i></b>. Since you paid a premium for a Knapsack with capacity <b><i>X</i></b> (as opposed to a Knapsack with a lower capacity), you want to fill the Knapsack as much as possible.
// Write a program that takes all the above values as input and calculates the best way to fill the Knapsack - that is, the way that minimizes the unused capacity. Output this unused capacity. See the explanation of the sample test cases for clarity.

// Input Format: The first line contains three integers, N, M and X, separated by single space. The next line contains N integers, W[1], W[2], W[3] ... W[N], separated by single space. The next line contains N integers C[1], C[2], C[3] ... C[N], separated by single space.
// Sample Input: 9 3 10
// 1 3 5 1 3 5 1 3 5
// 1 1 1 2 2 2 3 3 3
// Output Format: An optimal way of filling the Knapsack minimizes unused capacity. There may be several optimal ways of filling the Knapsack. Output the unused capacity of the Knapsack (a single integer on a line by itself) for an optimal way. If there is no way to fill the Knapsack, output -1.

// Sample Output: 1



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

ll clr[110],wt[110],n,m,dp[110][10010];  //dp[color][Sum]
vector<ll> col[110];//vector to store weights of stones of color i
//clr=colour
//wt=weight

ll cknap(ll clr,ll x){
	if(x < 0)
		return INT_MAX;
	if(clr == m+1)
		return x; //left storage of knapsack
	if(dp[clr][x] != -1)
		return dp[clr][x];
	
	ll ans = INT_MAX;
	for(ll i=0;i<col[clr].size();i++){
		ans = min(ans,cknap(clr+1,x-col[clr][i]));
	}
	return dp[clr][x] = ans;
}
int main(){
//	freopen("input4.txt","r",stdin);
//	freopen("output4.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	int x;
	
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		cin>>wt[i];
	for(int i=1;i<=n;i++)
		cin>>clr[i];
		
	for(int i=1;i<=n;i++){
		col[clr[i]].push_back(wt[i]);
	}
	
	ll ans = cknap(1,x);
	if(ans == INT_MAX)
		ans = -1;
	
	cout<<ans;
	
	return 0;
}