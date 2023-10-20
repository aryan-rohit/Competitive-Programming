// Problem Name: Box Stacking Problem
// Problem Difficulty: 
// Problem Constraints: 1 <= T <= 100
// 1 <= N <= 100
// 1 <= l,w,h <= 1000000
// Problem Description:
// Given a set of <b>N</b> types of rectangular 3-D boxes, where the <b>i<sup>th</sup></b> box has height <b>h</b>, width <b>w</b> and length <b>l</b>. Create a stack of boxes which is as tall as possible. However, you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. Your task is to write a program to find the maximum Height by any possible arrangements of the boxes.


// Input Format: The first line contains an integer <b>T</b> denoting the no of test cases. <br />
// For every test case: <br />
// <ul>
// <li>First line contains an integer <b>N</b> denoting the total no of boxes available. </li>
// <li> Second line contains <b>3*N</b> space separated values denoting the height, width and length of the <b>N</b> boxes.
// Sample Input: 2
// 4
// 4 6 7 1 2 3 4 5 6 10 12 32
// 3

// 1 2 3 4 5 6 3 4 1
// Output Format: For every test case, print the maximum height possible with the given boxes.
// Sample Output: 60
// 15

#include<bits/stdc++.h>
using namespace std;
int dp[105][3];
struct box{
    int l,w,h;
    box(int l,int w,int h){
        this->l=l;
        this->w=w;
        this->h=h;
    }
};
// struct box {
//   int l, w, h;

//   box() : l(0), w(0), h(0) {}
//   box(int l, int w, int h) : l(l), w(w), h(h) {}
// };
int solve(vector<box>&v,int prev,int ori){
    if(dp[prev][ori]!=-1){
        return dp[prev][ori];
    }
    int res=0;
    int pl,pw,ph;
    if(ori==0){
        pl=v[prev].l;
        pw=v[prev].w;
        ph=v[prev].h;
    }
    else if(ori==1){
        pl=v[prev].w;
        pw=v[prev].h;
        ph=v[prev].l;
    }
    else{
        pl=v[prev].h;
        pw=v[prev].l;
        ph=v[prev].w;
    }
    for(int i=1;i<v.size();i++){
        if((v[i].l<pl && v[i].w <pw) || (v[i].w<pl && v[i].l <pw) ){
            res=max(res,v[i].h+solve(v,i,0));
        }
        if((v[i].h<pl && v[i].w <pw) || (v[i].w<pl && v[i].h <pw) ){
            res=max(res,v[i].l+solve(v,i,1));
        }
        if((v[i].l<pl && v[i].h <pw) || (v[i].h<pl && v[i].l <pw) ){
            res=max(res,v[i].w+solve(v,i,2));
        }
    }
    return dp[prev][ori]=res;
}

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        vector<box>v(n+1,{0,0,0});
        v[0]=box(1e7,1e7,1e7);
        for(int i=1;i<=n;i++){
            cin>>v[i].l>>v[i].w>>v[i].h;
        }
        cout<<solve(v,0,0);
    }
    return 0;
}