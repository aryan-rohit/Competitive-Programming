// Problem Name: Class Photograph
// Problem Difficulty: 
// Problem Constraints: 1<=b,g<=1000
// 1 ≤ n1,n2 ≤ 20
// Problem Description:
// There are "b" boys and "g" girls in a class. Today is the day of their class photograph. The photographer 
// loves having different arrangements for a photograph. He decides that the photo would look awesome 
// if there are atmost n1 adjacent boys and atmost adjacent n2 girls lined up together. if there are more than n1 boys, 
// or more than n2 girls standing together(successively one after another), then the photograph will not 
// look awesome. 

// So, find the number of ways in which the photographer can arrange b boys and g girls so that the photograph looks awesome.

// Input Format:  One line containing  four integers - b , g , n1 , n2 .
// Sample Input: 1 2 5 1
// Output Format: Output a single i.e the no.of arrangements modulo <b>10^9 + 7</b> 
// Sample Output: 1



// =====Solution=====
#include<bits/stdc++.h>
using namespace std;
 
typedef int ll;
 
ll m = pow(10,9) + 7;
 
ll a,b,n1,n2;
 
ll dp[1005][1005][25][2];
 
// 0 - Diya 1 - Candle
ll func(ll d,ll c, ll n,ll x)
{
	if (d==0 && c==0) return 1;
	if (dp[d][c][n][x]!=-1) return dp[d][c][n][x];
	ll ans = 0;
	if (d>0)
	{
		if (x==0 && n<n1) ans = ( ans + func(d-1,c,n+1,0) )%m ;
		if (x==1) ans = ( ans + func(d-1,c,1,0) )%m;
	}
	if (c>0)
	{
		if (x==1 && n<n2) ans = ( ans + func(d,c-1,n+1,1)  )%m;
		if (x==0) ans = ( ans + func(d,c-1,1,1) )%m;
	}
	return dp[d][c][n][x] = ans;
}
 
int main()
{
	scanf("%d %d %d %d",&a,&b,&n1,&n2);
	memset(dp,-1,sizeof(dp));
	printf("%d",func(a,b,0,0));
	return 0;
}  