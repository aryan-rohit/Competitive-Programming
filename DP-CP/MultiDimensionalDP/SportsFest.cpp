// Problem Name: Sports Fest
// Problem Difficulty: None
// Problem Constraints: 1 <= Number of days <= 10^5
// Problem Description:
// Prateek Bhaiya decided to organize a sports fest for students of Coding Blocks and he came to know that Cricket, Football and Hockey are popular in the same order. So, he laid down the following rules for the fest :<br>
// <ul>
// <li>Only one match can be played in a single day.</li>
// <li>Cricket can be played daily.</li>
// <li>Football can't be played on two consecutive days.</li>
// <li>There must be a gap of at least two days between two hockey matches.</li>
// </ul>
//  Since Bhaiya is busy enjoying his Maggi, he wants you to write a program that can calculate the number of ways the fest can be organised, given the number of days the fest is scheduled to be organised over.

// Input Format: Single integer representing the duration of fest in number of days.
// Sample Input: 2
// Output Format: Print a single integer, the total number of ways the fest can be organised in. As the number of ways can be large, print the answer modulo 10<sup>9</sup>+7.
// Sample Output: 7



// =====Solution=====
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

ll dpC[100010],dpF[100010],dpH[100010],n;

int main(){
//	freopen("input4.txt","r",stdin);
//	freopen("output4.txt","w",stdout);
	ios::sync_with_stdio(0);
	
	cin>>n;
	
	// base cases
	dpC[1] = dpF[1] = dpH[1] = 1;
	dpH[2] = 2;
	
	for(int i=1;i<=n;i++){
		if(i-1 > 0){
			dpC[i] = (dpC[i-1] + dpF[i-1] + dpH[i-1]) % mod; // recurrence for cricket
			dpF[i] = (dpC[i-1] + dpH[i-1]) % mod; // recurrence for football
		}
		if(i-2 > 0){
			dpH[i] = (2*dpC[i-2] + dpF[i-2]) % mod; // recurrence for hockey
		}
	}
	
	cout<<(dpC[n] + dpF[n] + dpH[n]) % mod;
	
	return 0;
}
