// Problem Name: Buying Fruits
// Problem Difficulty: None
// Problem Constraints: 1 ≤ T ≤ 10 
// 1 ≤ N ≤ 10^5
// Cost of each fruit(apples/mangoes/oranges) per kg does not exceed 10^4
// Problem Description:
// Prateek went to purchase fruits mainly apples, mangoes and oranges. There are N different fruit sellers in a line. Each fruit seller sells all three fruit items, but at different prices. Prateek, obsessed by his nature to spend optimally, decided not to purchase same fruit from adjacent shops. Also, Prateek will purchase exactly one type of fruit item (only 1kg) from one shop. Prateek wishes to spend minimum money buying fruits using this strategy. Help Prateek determine the minimum money he will spend. If  he becomes happy, he may offer you discount on your favorite course in Coding Blocks ;). All the best!

// Input Format: First line indicates number of test cases <b>T</b>. Each test case in its first line contains <b>N</b> denoting the number of fruit sellers in Fruit Market. Then each of next <b>N</b> lines contains three space separated integers denoting cost of apples, mangoes and oranges per kg with that particular fruit seller.
// Sample Input: 1
// 3
// 1 50 50
// 50 50 50
// 1 50 50
// Output Format: For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.
// Sample Output: 52



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

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
      ll n;
      s(n);
      vector<ll>ar[n];
      F(i,0,n-1){
        ar[i]=vector<ll>(3,0);
        F(j,0,2){
          cin>>ar[i][j];
        }
      }
        
     // dp[i][j] indicates the minimum cost of shopping if the jth fruit is purchased 
     // from shop i (considering only till ith shop).
      ll dp[n][3]={0};
      dp[0][0]=ar[0][0]; dp[0][1]=ar[0][1]; dp[0][2]=ar[0][2];
      F(i,1,n-1){
        
        // If you are purchasing apples from ith shop, you can only purchase mangoes
        // or oranges from the previous shop. Choose the one which gives minimum cost.
        dp[i][0]=ar[i][0]+min(dp[i-1][1],dp[i-1][2]);
        
        // Similar as the above case.
        dp[i][1]=ar[i][1]+min(dp[i-1][0],dp[i-1][2]);
        
        // Similar as the above case.
        dp[i][2]=ar[i][2]+min(dp[i-1][0],dp[i-1][1]);
      }
      
      // Now since we have considered all n shops, print the one which gives the minimum
      // cost.
      cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<endl;
  }
}
