// Problem Name: Vivek Loves Array Game
// Problem Difficulty: None
// Problem Constraints: 1 <= T <= 10
// 1 <= N <= 17000
// 0 <= A[i] <= 10^9
// Problem Description:
// Vivek loves to play with array . One day Vivek just came up with a new array game which was introduced to him by his friend Ujjwal. The rules of the game are as follows:

//     Initially, there is an array, A , containing 'N' integers.

//     In each move, Vivek must divide the array into  two non-empty contiguous parts such that the sum of the elements in the left part is equal  to the sum of the elements in the right part. If Vivek can make such a move, he gets '1' point; otherwise, the game ends.

//     After each successful move, Vivek have to discards either the left part or the right part and continues playing by using 
// the remaining partition as array 'A'.

// Vivek loves this game and wants your help getting the best score possible. Given  'A', can you find and print the maximum number of points he can score?

// Input Format: First line of input contains an integer T denoting number of test cases.
// Each further Test case contains first line an integer 'N' , the size of array 'A'.
// After that 'N' space separated integers denoting the elements of array.
// Sample Input: 3
// 3
// 3 3 3
// 4
// 2 2 2 2
// 7
// 4 1 0 1 1 0 1
// Output Format: For each test case, print Vivek's maximum possible score on a new line.
// Sample Output: 0
// 2
// 3


#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pre;
map<pair<int,int>,int> my;
int maxScore(vector<int> &a,int l,int r){
    if(l==r)return 0LL;
    if(l>r)return 0LL;
    int totalSum=pre[r]-(l?pre[l-1]:0);
    int ind;
    if(totalSum%2)return 0LL;
    int sum=0;
    bool flag=false;
    for(int j=l;j<=r;j++){
        sum+=a[j];
        if(sum==(totalSum/2)){
            ind=j;
            flag=true;
            break;
        }
    }
    if(!flag)return 0;

    return 1+max(maxScore(a,l,ind),maxScore(a,ind+1,r));
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);cout.tie(0);
    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        pre.clear();
        pre.resize(n);
        my.clear();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(i==0)pre[i]=a[i];
            else pre[i]=pre[i-1]+a[i];
        }

        printf("%lld\n",maxScore(a,0,n-1));
    }
    return 0;
}