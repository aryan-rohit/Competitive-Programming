// Problem Name: Magical String 2
// Problem Difficulty: 
// Problem Constraints: 1 <= n <= 1000
// 1 <= a1,a2...a26 <= 1000 (for 26 lowercase numbers)
// Problem Description:
// Secret ravens from Winterfell started flying as the great war was coming. 
// The Starks wrote the message using only 26 lowercase letters ('a'- 'z') on pieces of paper and attached them to ravens.
// However the messages were intercepted in between by Lannisters who killed all the ravens.
// Each letter from a to z had a certain number associated with it.
// Now the lannisters wanted to cut the string of message in such a way that each letter shouldn't appear in the string of length greater than the number associated with it.
// For example if the string is "aabca" and numbers associated with a b and c are 1 2 3 then 'a' cannot appear in a string of length more than 1 similarly 'b' in 2 and 'c' in 3.
// One possible way to cut this string is a | a | b | c | a or a | a | bc | a.
// Now the Lannisters asked you a question since they were weak at math. :p
// what are the minimum number of strings after cutting them satisfying the required constraints??

// Input Format: first line consists of number n
// second line consists of string of length n
// third line consists of 26 integers denoting number associated with each character where first number corresponds to a and so on.
// Sample Input: input sample 1
// 3
// aab
// 2 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

// input sample 2
// 5
// aabab
// 2 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


// Output Format: print the number of strings after the optimal cutting.
// Sample Output: output sample 1
// 2

// output sample 2
// 3



// =====Solution=====
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll,ll>
#define PI 3.14159265358979323846264338327950288
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
ll n,arr[30],mincutdp[1005];
string s;
bool isvalid(ll st,ll en)
{
	F(i,st,en)
	{
		if(arr[s[i]-'a'] < (en-st+1))
			return 0;
	}
	return 1;
}
ll mincut(ll cur) // recursive top down approach
{
	if(mincutdp[cur]!=-1)
		return mincutdp[cur];
	if(cur == 0)
		return mincutdp[cur] = 0;
	ll ans = INF;
	RF(i,cur,1)
	{
		if(!isvalid(i,cur)) // for minimum number of cuts try all possible valid substrings and take minimum of them
		{
			ans = min(ans,1 + mincut(i));
			break;
		}
	}
	if(ans == INF)
		return mincutdp[cur] = 1;
	return mincutdp[cur] = ans;
}
ll dp2[1005];
int main() 
{
	std::ios::sync_with_stdio(false);
	//memset(mincutdp,-1,sizeof(mincutdp));
	cin>>n>>s;
	s = "*" + s;
	F(i,0,25)
		cin>>arr[i];
	//cout<<mincut(n)<<endl;
	dp2[0] = 0; // bottom up dp
	F(i,1,n)
	{
		dp2[i] = 1;
		RF(j,i,1)
		{
			if(!isvalid(j,i))
			{
				dp2[i] = 1 + dp2[j]; // break if first invalid found coz rest will be invalid too
				break;
			}
		}
	}
	cout<<dp2[n]<<endl;
	return 0;
}