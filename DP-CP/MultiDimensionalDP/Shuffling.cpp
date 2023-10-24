// Problem Name: SHUFFLING
// Problem Difficulty: 
// Problem Constraints: 1≤T≤1,000 

// 1≤A,B,C≤1e9

// A+B=C

// Problem Description:
// Saurabh tried to solve the Big Famous Unsolvable A+B=C. Of course he did it , but he was wondering
// in how many ways is it possible to shuffle the bits of A and the bits of B such that their sum after shuffling is equal to C? Let's denote the integers obtained by shuffling the bits of A and B by As and Bs respectively; two ways (As1,Bs1) and (As2,Bs2) are considered distinct if As1≠As2 or Bs1≠Bs2.

// It is allowed to add any number (possibly zero) of leading zeroes, i.e. bits 0, to A and any number of leading zeroes to B before shuffling the bits.

// Input Format: The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.

// The first and only line of each test case contains three space-separated integers A, B and C.
// Sample Input: 2
// 1 2 3
// 369 428 797
// Output Format: For each test case, print a single line containing one integer — the number of ways to shuffle the bits.
// Sample Output: 2
// 56



// =====Solution=====
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[40+1][40+1][40+1][2];
ll give(ll x){ //counting set bit
    ll cnt=0;
    while(x){
        if(x&1){
            cnt++;
        }
        x/=2;
    }
    return cnt;
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,l,m,n;
        ll a,b,c;
        cin>>a>>b>>c;
        string s;//getting bits of number  C
        while(c){
            if(c&1){
                s+='1';
            }
            else{
                s+='0';
            }
            c/=2;
        }
        n=s.size();
        a=give(a);
        b=give(b);
        memset(dp,0,sizeof(dp));
        if(s[0]=='1'){  
            dp[0][1][0][0]=1;    //i,a,b,carry
            dp[0][0][1][0]=1;
        }
        else{
            dp[0][0][0][0]=1;
            dp[0][1][1][1]=1;
        }
        for(i=1;i<n;i++){
            for(ll x=0;x<=a;x++){
                for(ll y=0;y<=b;y++){
                    if(s[i]=='1'){
                        if(x>=1){
                            dp[i][x][y][0]+=dp[i-1][x-1][y][0];
                        }
                        if(y>=1){
                            dp[i][x][y][0]+=dp[i-1][x][y-1][0];
                        }
                        dp[i][x][y][0]+=dp[i-1][x][y][1];
                        if(x>=1&&y>=1){
                            dp[i][x][y][1]+=dp[i-1][x-1][y-1][1];
                        }

                    }
                    else{
                        dp[i][x][y][0]+=dp[i-1][x][y][0];
                        if(x>=1&&y>=1){
                            dp[i][x][y][1]+=dp[i-1][x-1][y-1][0];
                        }
                        if(x>=1){
                            dp[i][x][y][1]+=dp[i-1][x-1][y][1];
                        }
                        if(y>=1){
                            dp[i][x][y][1]+=dp[i-1][x][y-1][1];
                        }
                    }
                }
            }
        }
        cout<<dp[n-1][a][b][0]<<'\n';
    }
}
