// Problem Name: Little Vipul and his Queries
// Problem Difficulty: 
// Problem Constraints: 1 ≤ N ≤ 100
// 1 ≤ Q ≤ 10^4
// 0 ≤ X , Y ≤ 100
// No single row can have more than 200 balls.
// Problem Description:
// Vipul has a set of red and blue balls  arranged in a line, like this: <br />
// Line 1: R<br />
// Line 2: B R B <br />
// Line 3: R B <br />
// Now little Vipul has one question in mind. Given <b>X</b> Red balls and <b>Y</b> Blue balls , how many lines can hi reciprocate completely?

// Input Format: First line of the input contains a single integer <b>N</b>. <b>N</b> denoting the number of rows in Vipul's arrangement of balls. <br />
// Each of next <b>N</b> lines contains a string consisting of two types of characters: <b>R</b> and <b>B</b> where <b>R</b> denotes red colored balls and <b>B</b> denotes blue color balls. <br />
// Next line contain a single integer <b>Q</b>, denoting the number of queries that Vipul wishes to find answers for. <br />
// Each of the next <b>Q</b> line contains two space separated integers, <b>X</b> and <b>Y</b> denoting count of red and blue balls respectively. <br />
// Sample Input: 3
// RRBB
// BB
// R
// 1
// 2 3	
// Output Format: For each query of type <b>X</b> <b>Y</b>, you need to print the maximum number of rows that can be mimicked by Vipul if he was to get <b>X</b> red balls and <b>Y</b> blue balls.
// Sample Output: 2



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

ll dp[101][101][101]={0};

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  //s(t);
  while(t--){
    ll n;
    s(n);
    ll rd[201]={0};
    ll bl[201]={0};

    F(i,1,n){
      string str;
      cin>>str;
      for(char ch:str){
        if(ch=='R')rd[i]++;
        else bl[i]++;
      }
    }

    

    for(ll i=1;i<=n;i++){
      for(ll x=0;x<=100;x++){
        for(ll y=0;y<=100;y++){
          if(i==1){
            if(x>=rd[i] and y>=bl[i])dp[i][x][y]=1;
          }else{
            dp[i][x][y]=dp[i-1][x][y];
            if(x>=rd[i] and y>=bl[i])dp[i][x][y]=max(dp[i][x][y],1+dp[i-1][x-rd[i]][y-bl[i]]);
          }
        }
      }
    }

    ll q;
    s(q);
    while(q--){
      ll x,y;
      cin>>x>>y;
      cout<<dp[n][x][y]<<endl;
    }
  }
}