/*

Problem Name: Unlock
Problem Difficulty: 2
Problem Constraints: 1 <= n <= 10^5 1<= K <= 10^9
Problem Description:
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format: First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.
Sample Input: 5 2
3 4 1 2 5
Output Format: The final permutation of the numbers with every number separated by a space with other number.
Sample Output: 5 4 3 2 1

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    int pos[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pos[arr[i]]=i;
    }
    int m=0;
    while(m<n &&k>0){
        if(arr[m]!=n-m){
            int temp=pos[n-m];
            int temp2=arr[m];
            swap(arr[m],arr[pos[n-m]]);
            // swap(pos[n-m],pos[arr[m]]);
            pos[n-m]=m;
            pos[temp2]=temp;
            k--;
            m++;
        }
        else{
            m++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    return 0;
}