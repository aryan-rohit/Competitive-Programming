// Problem Name: Vipul and his love for strings
// Problem Difficulty: 
// Problem Constraints: 1 ≤ n, m ≤ 1000
// 1 ≤ k ≤ 10
// Problem Description:
// Given two strings <b>s</b> and <b>t</b> whose sizes are <b>n</b> and <b>m</b> respectively.Given another integer <b>k</b>. Vipul wants to choose <b>k</b> disjoint non-empty substrings of string <b>s</b> such that these strings appear as disjoint substrings of string <b>t</b> and in the same order as they do in string <b>s</b>. Vipul is also interested in that their length is maximum possible among all variants.<br />
// Formally, Vipul wants to find a sequence of <b>k</b> non-empty strings p<sub>1</sub>, p<sub>2</sub>, p<sub>3</sub>, ..., p<sub>k</sub> satisfying following conditions:
// <ul>
// <li><b>s</b> can be represented as concatenation a<sub>1</sub>p<sub>1</sub>a<sub>2</sub>p<sub>2</sub>... a<sub>k</sub>p<sub>k</sub>a<sub>k+1</sub>, where a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>k+1</sub> is a sequence of arbitrary strings (some of them may be possibly empty)</li>
// <li><b>t</b> can be represented as concatenation b<sub>1</sub>p<sub>1</sub>b<sub>2</sub>p<sub>2</sub>... b<sub>k</sub>p<sub>k</sub>b<sub>k+1</sub>, where b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>k+1</sub> is a sequence of arbitrary strings (some of them may be possibly empty)</li>
// <li>sum of the lengths of strings in sequence is maximum possible</li>
// </ul>
// Please help Vipul finding at least the sum of the lengths of the strings in a desired sequence.

// Input Format: First line contains three integers <b>n</b>, <b>m</b>, <b>k</b> are given — the length of the string <b>s</b> and the length of the string <b>t</b> respectively.
// <br />The second line of the input contains string <b>s</b>, consisting of lowercase English letters.
// <br />The third line of the input contains string <b>t</b>, consisting of lowercase English letters.
// Sample Input: 9 12 4
// bbaaababb
// abbbabbaaaba
// Output Format: Print the sum of the lengths of the strings in a desired sequence. <br />
// <b>It is guaranteed</b>, that at least one desired sequence exists.
// Sample Output: 7




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

ll dp[1005][1005][15][2];
ll n,m;
string str1,str2;

ll solve(ll i,ll j,ll k,ll flag){
  if(k<0)return INT_MIN;
  if((i>=n or j>=m) and k==0)return 0;
  if((i>=n or j>=m) and k!=0)return INT_MIN;

  if(dp[i][j][k][flag] != -1)return dp[i][j][k][flag];

  ll ans = max(solve(i,j+1,k,0),solve(i+1,j,k,0));

  if(str1[i]==str2[j]){
    if(flag) ans=max(ans,1+solve(i+1,j+1,k,1));

    ans=max(ans,1+solve(i+1,j+1,k-1,1));
  }
  dp[i][j][k][flag]=ans;
  return ans;
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll k;
    memset(dp,-1,sizeof(dp));
    s3(n,m,k);
    cin>>str1>>str2;
    cout<<solve(0,0,k,0)<<endl;
  }
}