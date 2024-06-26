// Problem Name: Mixtures
// Problem Difficulty: None
// Problem Constraints: 1 <= n <= 100
// Problem Description:
// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.<br>
// You can find the original problem <a href="www.spoj.com/problems/MIXTURES/">here</a>.


// Input Format: The first line of each input file will contain n, the number of mixtures. The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.
// Sample Input: 3
// 40 60 20
// Output Format: Output the minimum amount of smoke.
// Sample Output: 2400



// =====Solution=====


//Functional Algorithm 
#include<bits/stdc++.h>
using namespace std;

long long n,i,j,a[110],dp[110][110],temp,k,l,sum[110][110];

int main(){
//	freopen("input5.txt","r",stdin);
//	freopen("output5.txt","w",stdout);
//	ios::sync_wth_stdio(0);
	
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=0;i<n;i++){
		sum[i][i]=temp = a[i];
		for(j=i+1;j<n;j++){
			temp += a[j];
			sum[i][j] = temp%100;
		}
	}
	for(i=0;i<n;i++)
		dp[i][i] = 0;
	for(j=1;j<n;j++){   //length of array 
		for(i=0;i<n-j;i++){   //limiting length so that it does not go out of 2D array box
			dp[i][i+j] = INT_MAX;
			for(k=i;k<i+j;k++){
				dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+sum[i][k]*sum[k+1][i+j]);
			}
		}
	}
	cout<<dp[0][n-1]<<"\n";

	return 0;
}