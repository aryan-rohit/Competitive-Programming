// Problem Name: Divisible Patterns
// Problem Difficulty: 
// Problem Constraints: 1 <= len(T) , len(P) <= 10000
// Problem Description:
// You are given a text **T** and a pattern **P**.<br>
// Let the set **S** be such that it contains all the starting positions of occurences of pattern P in T. (1 - indexed). <br>
// For example if T = aaaa and  P = a than S = {1,2,3,4}. <br>
// If T=abab and P = ab than S = {1,3}.<br>
// You have to find out the number of ways to choose some numbers from the set S such that the product of chosen numbers is divisible by all the numbers from 1 to 9 modulo 10^9+7. 

// Input Format: The first line consists of pattern P.
// The second line consists of text T.
// Sample Input: a
// aaaaaaa
// Output Format: The number of ways modulo 10^9 + 7.
// Sample Output: 4


//samajh to aaya nhi

// =====Solution=====
/*input
a
aaaaaaa
*/
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
ll z[300005];
void compute_z(string s) // compute z value for each character
{
	ll l=0,r=0;
	ll n = s.length();
	F(i,1,n-1)
	{
		if(i > r)
		{
			l = i , r = i;
			while(r < n && s[r-l] == s[r])
				r++;
			z[i] = r-l;
			r--;
		}
		else
		{
			ll k = i-l;
			if(z[k] < r-i+1)
			{
				z[i] = z[k];
			}
			else
			{
				l = i;
				while(r < n && s[r-l] == s[r])
					r++;
				z[i] = r-l;
				r--;
			}
		}
	}
}
string pattern,text;
vector <ll> pos;
void compute_occurences()
{
	string s = pattern + "$" + text;
	compute_z(s);
	ll n = s.length();
	F(i,0,n-1)
	{
		if(z[i] == pattern.length())
		{
			//debug(i);
			pos.pb(i - pattern.length());
		}
	}
}
ll dp[10005][4][4][3][3];
ll f(ll i,ll two,ll three,ll five,ll seven)
{
	//cout<<i<<" "<<two<<endl;
	if(i==pos.size())
	{
		if(two>=3 && three>=2 && five>=1 && seven>=1)
		{
			//debug(i);
			return 1;
		}
		return 0;
	}
	if(dp[i][two][three][five][seven] != -1)
		return dp[i][two][three][five][seven];
	ll num = pos[i];
	//debug(num);
	ll t1=0,t2=0,t3=0,t4=0;
	while(num%2==0 && num && t1<=3)
	{
		t1++;
		num /= 2;
	}
	while(num%3==0 && num && t2<=2) 
	{
		t2++;
		num /= 3;
	}
	while(num%5==0 && num && t3<=1)
	{
		t3++;
		num /= 5;
	}
	while(num%7==0 && num && t4<=1)
	{
		t4++;
		num /= 7;
	}
	// if we take current number
	ll a = f(i+1,min(3ll,two+t1),min(2ll,three+t2),min(1ll,five+t3),min(1ll,seven+t4));
	ll b = f(i+1,two,three,five,seven);
	return dp[i][two][three][five][seven] = (a+b)%mod;
}
int main() 
{
	std::ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cin>>pattern>>text;
	compute_occurences();
	cout<<f(0,0,0,0,0)<<endl;
	return 0;
}