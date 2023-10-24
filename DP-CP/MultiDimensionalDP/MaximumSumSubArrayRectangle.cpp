// Problem Name: Maximum Sum Subarray
// Problem Difficulty: 
// Problem Constraints: 1 <= R, C <= 100
// Problem Description:
// Find the maximum sum subarray in the given 2D array.

// Input Format: First line of every test case consists of 2 integers <b>R</b> and <b>C</b> , denoting number of rows and columns.<br />
// Second line consists of <b>R*C</b> spaced integers denoting number of elements in array.
// Sample Input: 4 5
// 1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
// Output Format: Print the maximum possible sum of any rectangle which can be formed in that 2D matrix.
// Sample Output: 29



// =====Solution=====
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)
 
#define ll int

#define s(x) scanf("%d",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%d\n",x)
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

ll maxsum(INT_MIN),maxlef(-1),maxryt(-1),maxup(-1),maxdn(-1),cursum(0);

void init(){
  maxsum=INT_MIN;
  maxlef=-1;
  maxryt=-1;
  maxup=-1;
  maxdn=-1;
  cursum=0;
}

// Function to compute the maximum sum subarray in the passed vector using Kadane's algorithm
// lf and rt are just passed to compute the maxlef and maxryt.
void solve(vector<ll> &kadane, ll lf, ll rt){
  ll n = kadane.size();
  if(n==0)return;
  ll mxsum=kadane[0];
  ll cursum=kadane[0];
  ll stlf=0;
  ll mxlf=0;
  ll mxrt=0;

  for(ll i=1;i<n;i++){
    if(cursum<0){
      cursum=kadane[i];
      stlf=i;
    }else{
      cursum+=kadane[i];
    }

    if(cursum>mxsum){
      mxsum=cursum;
      mxlf=stlf;
      mxrt=i;
    }
  }
  if(mxsum>maxsum){
    maxsum=mxsum;
    maxlef=lf;
    maxryt=rt;
    maxup=mxlf;
    maxdn=mxrt;
  }
}

// O((c*r)^2)
int main()
{
  // freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    init();
    ll r,c;
    s2(r,c);
    vector<vector<ll>> mat;
    mat.resize(r);
    for(ll i=0;i<r;i++){
      mat[i].resize(c);
      for(ll j=0;j<c;j++){
        cin>>mat[i][j];
      }
    }

    vector<ll> kadane;   
    for(ll lf=0;lf<c;lf++){
      kadane.clear();
      kadane.resize(r,0);
      for(ll rt=lf;rt<c;rt++){
        for(ll i=0;i<r;i++){
          kadane[i]+=mat[i][rt];
        }
        solve(kadane,lf,rt);
      }
    }
    cout<<maxsum<<endl;
  }
}
