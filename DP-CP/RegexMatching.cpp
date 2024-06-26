// Problem Name: Regex Matching
// Problem Difficulty: 
// Problem Constraints: Size(str)*Size(pattern) < 100000000
// Problem Description:
// Implement regular expression matching with support for <b>' . '</b> and <b>' * '</b>.
// <ol>
// <li> <b>' . '</b> Matches any single character. </li>
// <li><b>' * '</b> Matches zero or more of the preceding element. </li>
// </ol>
// <b>NOTE: The matching should cover the entire input string (not partial).</b>

// Input Format: Every test file will consist of two strings. First string represents <b>'str'</b>. Second string represents <b>'pattern'</b>.
// Sample Input: aa
// a*a

// Output Format: Print <b>1</b> if the string matches the pattern, else  print <b>0</b>.
// Sample Output: 1



// =====Solution=====

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

bool isMatch(string str,string pat){
	str='.'+str;
	pat='.'+pat;
	if(str==pat)return true;
	ll n = str.size();
	ll m = pat.size();
	vector<vector<bool>> dp(n,vector<bool>(m,false));
	dp[0][0]=true;
	for(ll j=1;j<m;j+=2){
		if(j+1<m and pat[j+1]=='*'){
			dp[0][j+1]=true;
		}else break;
	}

	for(ll i=1;i<n;i++){
		for(ll j=1;j<m;j++){
			if(j<m-1 and pat[j+1]=='*')j++;
			if(pat[j]=='.')dp[i][j]=dp[i-1][j-1];
			else if(pat[j]=='*'){
				dp[i][j]=dp[i][j-2] or ((str[i]==pat[j-1] or pat[j-1]=='.') and dp[i-1][j]);
			}else{
				dp[i][j] = (str[i]==pat[j]) and dp[i-1][j-1];
			}
		}
	}
	return dp[n-1][m-1];
}



int main()
{
	// freopen("input.txt","r",stdin);
 	// freopen("output.txt","w",stdout);
	ll t=1;
	//s(t);
	while(t--){
		string str,pat;
		cin>>str>>pat;
		cout<<isMatch(str,pat)<<endl;
	}
}