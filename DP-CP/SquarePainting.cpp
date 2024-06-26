// Problem Name: SQUARE PAINTING
// Problem Difficulty: 
// Problem Constraints: 1 ≤ k ≤ n ≤ 2000
// Problem Description:
// Apaar likes to paint his heart out. He made a famous painting software letspaint. The working screen of letspaint is square-shaped consisting of n rows and n columns of square cells. The rows are numbered from 1 to n, from top to bottom, and the columns are numbered from 1 to n, from left to right. The position of a cell at row r and column c is represented as (r,c). There are only two colors for the cells in letspaint — black and white.

// There is a tool named eraser in letspaint. The eraser has an integer size k (1≤k≤n). To use the eraser, Apaar needs to click on a cell (i,j) where 1≤i,j≤n−k+1. When a cell (i,j) is clicked, all of the cells (i′,j′) where i≤i′≤i+k−1 and j≤j′≤j+k−1 become white. In other words, a square with side equal to k cells and top left corner at (i,j) is colored white.

// A white line is a row or a column without any black cells.

// Apaar has worked with letspaint for some time, so some of the cells (possibly zero or all) are currently black. He wants to know the maximum number of white lines after using the eraser exactly once. Help him find the answer to his question.





// Input Format: The first line contains two integers n and k (1≤k≤n≤2000) — the number of rows and columns, and the size of the eraser.

// The next n lines contain n characters each without spaces. The j-th character in the i-th line represents the cell at (i,j). Each character is given as either 'B' representing a black cell, or 'W' representing a white cell.
// Sample Input: 5 3
// BWBBB
// BWBBB
// BBBBB
// BBBBB
// WBBBW

// Output Format: Print one integer: the maximum number of white lines after using the eraser exactly once.


// Sample Output: 2



// =====Solution=====
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
 
 
const int N=2005;
int a[N][N],h[N][N],v[N][N],row[N],col[N];
 
int giver(int l,int r){
    if(r<l) return 0;
    return row[r]-row[l-1];
}
 
int givec(int l,int r){
    if(r<l) return 0;
    return col[r]-col[l-1];
}
 
int giveh(int rr,int l,int r){
    if(r<l) return 0;
    return v[rr][r]-v[rr][l-1];
}
 
int givev(int cc,int l,int r){
    if(r<l) return 0;
    return h[r][cc]-h[l-1][cc];
}
 
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n>>k;
        string s[n];
        for(i=0;i<n;i++){
            cin>>s[i];
            for(j=0;j<n;j++){
                a[i+1][j+1]=(s[i][j]=='W'?1:0);
            }        
        }
        for(i=1;i<=n;i++){
            cnt=0;
            for(j=1;j<=n;j++){
                cnt+=a[i][j];
            }        
            row[i]=(cnt==n);
            row[i]+=row[i-1];
        }
        for(i=1;i<=n;i++){
            cnt=0;
            for(j=1;j<=n;j++){
                cnt+=a[j][i];
            }        
            col[i]=(cnt==n);
            col[i]+=col[i-1];
        }
        for(i=1;i<=n;i++){
            int bl=0;
            for(j=1;j<=n;j++){
                bl+=(a[i][j]==0);
            }        
            cnt=0;
            for(j=1;j<=k;j++){
                cnt+=(a[i][j]==0);          
            }
            h[i][1]=(cnt==bl);
            for(j=k+1;j<=n;j++){
                cnt+=(a[i][j]==0);
                cnt-=(a[i][j-k]==0);
                h[i][j-k+1]=(cnt==bl);
            }
        }
        for(j=1;j<=n;j++){
            int bl=0;
            for(i=1;i<=n;i++){
                bl+=(a[i][j]==0);
            }      
            cnt=0;
            for(i=1;i<=k;i++){
                cnt+=(a[i][j]==0);          
            }
            v[1][j]=(cnt==bl);
            for(i=k+1;i<=n;i++){
                cnt+=(a[i][j]==0);
                cnt-=(a[i-k][j]==0);
                v[i-k+1][j]=(cnt==bl);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                v[i][j]+=v[i][j-1];
            }        
        }
        for(j=1;j<=n;j++){
            for(i=1;i<=n;i++){
                h[i][j]+=h[i-1][j];
            }        
        }
        for(i=1;i+k-1<=n;i++){
            for(j=1;j+k-1<=n;j++){
                int temp=0;
                int st=1,en=i-1;
                temp+=giver(st,en);
                st=i+k;en=n;
                temp+=giver(st,en);
                st=1;en=j-1;
                temp+=givec(st,en);
                st=j+k;en=n;
                temp+=givec(st,en);
 
                temp+=givev(j,i,i+k-1);
                temp+=giveh(i,j,j+k-1);
 
                ans=max(ans,temp);
            }        
        }
        cout<<ans;
    }
}