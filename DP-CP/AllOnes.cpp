// Problem Name: All Ones
// Problem Difficulty: 
// Problem Constraints: 1 <= n,m <= 1000
// Problem Description:
// Given a matrix <b><i>M</i></b> consisiting of only 1s and 0s, you should print the side of largest square sub matrix containing all 1s.

// Input Format: First line contains two integers, <b><i>n</i></b> and <b><i>m</i></b>, representing number of rows and columns of the matrix respectively followed by <b><i>n</i></b> lines, <b><i>i<sup>th</sup></i></b> line of which contains <b><i>m</i></b> integers where <b><i>j<sup>th</sup></i></b> integers represents <b><i>M[i][j]</i></b>.
// Sample Input: 4 4
// 1 0 1 0 
// 0 1 0 1
// 1 0 1 1
// 0 1 1 1 
// Output Format: Print a single integer, the answer to the problem.
// Sample Output: 2



// =====Solution=====
/*
===========
Approach 1
==============
*/
#include<bits/stdc++.h>
using namespace std;

int maxSquare(vector<vector<int>> &a){
    int n=a.size(),m=a[0].size();
    int dp[n][m];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                dp[i][j]=0;
                continue;
            }
            if(i==0 || j==0){
                dp[i][j]=1;
                ans=max(ans,dp[i][j]);
                continue;
            }
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main() {

    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    cout<<maxSquare(a)<<endl;

    return 0;


//approach 1 is good 
// Approach 2

// #include<bits/stdc++.h>
// #define mod 1000000007
// #define pp pair<ll,ll>
// #define mp make_pair
// #define ll long long
// #define pb push_back
// #define ff first
// #define ss second
// using namespace std;

// int dp[1010][1010],mat[1010][1010],cumr[1010][1010],cumc[1010][1010],n,m; // 

// int main(){
// //	freopen("input1.txt","r",stdin);
// //	freopen("output1.txt","w",stdout);
// 	ios::sync_with_stdio(0);

// 	cin>>n>>m;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++)
// 			cin>>mat[i][j];
// 	}
// 	dp[1][1] = mat[1][1] ? 1 : 0;
// 	cumr[1][1] = mat[1][1] ? 1 : 0;
// 	cumc[1][1] = mat[1][1] ? 1 : 0;
		
// 	for(int j=2;j<=m;j++){
// 		dp[1][j] = mat[1][j] ? 1 : 0;
// 		cumr[1][j] = mat[1][j] ? 1+cumr[1][j-1] : 0;
// 		cumc[1][j] = mat[1][j] ? 1 : 0;
// 	}
// 	for(int i=2;i<=n;i++){
// 		dp[i][1] = mat[i][1] ? 1 : 0;
// 		cumc[i][1] = mat[i][1] ? 1+cumc[i-1][1] : 0;
// 		cumr[i][1] = mat[i][1] ? 1 : 0;
// 	}
// 	for(int i=2;i<=n;i++){
// 		for(int j=2;j<=m;j++){
// 			cumr[i][j] = mat[i][j] ? 1+cumr[i][j-1] : 0;
// 			cumc[i][j] = mat[i][j] ? 1+cumc[i-1][j] : 0;
// 		}
// 	}
	
// 	int ans = 0;	
// 	for(int i=2;i<=n;i++){
// 		for(int j=2;j<=m;j++){
// 			dp[i][j] = mat[i][j] ? 1+min(dp[i-1][j-1],min(cumr[i][j-1],cumc[i-1][j])) : 0;
// 			ans = max(ans,dp[i][j]);
// 		}
// 	}
// 	cout<<ans<<"\n";
	
// 	return 0;
// }