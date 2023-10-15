//jai Shree ram
/*AUTHOR-ARYAN KUMAR*/
#include <bits/stdc++.h>
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pll pair<ll, ll>
#define vvl vector<vector<ll>>
using namespace std;
using ll = long long;
const int32_t MOD = 1e9 + 7;
// sort(nums.begin(),nums.end(),[&](int a,int b){
//             return map[a]!=map[b]?map[a]<map[b]:a>b;
//         });
bool cmp(pair<int,int>a,pair<int,int>b){
if(a.first!=b.first)return a.first>b.first;
return a.second<b.second;
}
bool cmp2(pair<int,int>a,pair<int,int>b){
if(a.second==b.second)return a.first<b.first;
return a.second>b.second;
}

void solve(){
   int n;
   cin>>n;
   vector<vector<int>>v;
   int mini=INT_MAX;
   vector<int>ans;
   for(int i=0;i<n;i++){
       int m;
       cin>>m;
       vector<int>temp(m);
       for(int j=0;j<n;j++){
           cin>>temp[j];
       }
       sort(temp.begin(),temp.end());
       mini=min(mini,temp[0]);
       ans.push_back(temp[1]);
       v.push_back(temp);
   }
   int sum=0;
   for(int i=1;i<ans.size();i++){
       sum+=ans[i];
   }
   sum+=mini;
   cout<<sum<<endl;
}
signed main()
{
    IOS;
    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
    return 0;
}