// Problem Name: Job for Bounties II
// Problem Difficulty: None
// Problem Constraints: 1 <= N <= 100
// 1 <= T,duration[i],reward[i],deadline[i] <= 1000
// Problem Description:
// Mike is given <b><i>N</i></b> jobs and each job <b><i>i</i></b> is characterized by <b><i>duration[i]</i></b> (time taken to complete <b><i>i<sup>th</sup></i></b> job), <b><i>reward[i]</i></b> (bounties he will get on finishing <b><i>i<sup>th</sup></i></b> job) and <b><i>deadline[i]</i></b> (the time upto which <b><i>i<sup>th</sup></i></b> job must be completed if it is to be done). He has <b><i>T</i></b> time and can do at most one job at a time. Now, he has to choose jobs maximizing the number of bounties he can get after <b><i>T</i></b> time units.

// Input Format: The first line contains two integers, <b><i>T</i></b> and <b><i>n</i></b>, separated by space.<br>
// The next line contains <b><i>N</i></b> integers, separated by spaces, <b><i>i<sup>th</sup></i></b> integer representing <b><i>reward[i]</i></b>.<br>
// The next line contains <b><i>N</i></b> integers, separated by spaces, <b><i>i<sup>th</sup></i></b> integer representing <b><i>duration[i]</b></i>.<br>
// The next line contains <b><i>N</i></b> integers, separated by spaces, <b><i>i<sup>th</sup></i></b> integer representing <b><i>deadline[i]</i></b>.<br>
// Sample Input: 20 5
// 4 3 2 5 4
// 7 6 4 6 6
// 9 13 12 13 20
// Output Format: Print maximum number of bounties Mike can get after <b><i>T</i></b> time units.
// Sample Output: 13



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

ll T,n,reward[110],deadline[110],duration[110],dp[1010][110];

int main(){
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>T>>n;
	for(int i=1;i<=n;i++)
		cin>>reward[i];
	for(int i=1;i<=n;i++)
		cin>>duration[i];
	for(int i=1;i<=n;i++)
		cin>>deadline[i];
	
	for(int i=0;i<=T;i++)
		dp[i][0] = 0;
	for(int j=1;j<=n;j++)
		dp[0][j] = 0;
		
	ll ans = 0;
	for(int i=1;i<=T;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);//case where the job is not done
			if(duration[j] <= i && deadline[j] >= i){//condition for chosing jth job
				dp[i][j] = max(dp[i][j], reward[j]+dp[i-duration[j]][j-1]);//case where the jth job is chosen to be done
				ans = max(ans,dp[i][j]);
			}
		}
	}
	cout<<ans;
	
	return 0;
}
