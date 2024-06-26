// Problem Name: Flood Fill
// Problem Difficulty: None
// Problem Constraints: 
// Problem Description:
// You are given a line of n colored squares in a row, numbered from 1 to n from left to right. The i-th square initially has the color ci.

// Let's say, that two squares i and j belong to the same connected component if ci=cj, and ci=ck for all k satisfying i<k<j. In other words, all squares on the segment from i to j should have the same color.

// For example, the line [3,3,3] has 1 connected component, while the line [5,2,4,4] has 3 connected components.

// The game "flood fill" is played on the given line as follows:

// At the start of the game you pick any starting square (this is not counted as a turn).

// Then, in each game turn, change the color of the connected component containing the starting square to any other color.

// Find the minimum number of turns needed for the entire line to be changed into a single color.



// Input Format: The first line contains a single integer n (1≤n≤5000) — the number of squares.

// The second line contains integers c1,c2,…,cn (1≤ci≤5000) — the initial colors of the squares.


// Sample Input: 8
// 4 5 2 2 1 3 5 5

// Output Format: Print a single integer — the minimum number of the turns needed.


// Sample Output: 4



// =====Solution=====
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<ll, null_type, less<ll>, rb_tree_tag,
//         tree_order_statistics_node_update>
//         new_data_set;

const ll N = 5005;

ll dp[N][N];

int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// ll t;
	// cin>>t;
	// while(t--)
	{
		ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		vector<ll> v(n);
		for (i = 0; i < n; i++) {
			cin >> v[i];
		}
		v.resize(unique(v.begin(), v.end()) - v.begin());
		n = v.size();
		for (j = 0; j < n; j++) {
			for (i = j; i >= 0; i--) {
				dp[i][j] = 1e9;
				if (i == j) {
					dp[i][j] = 0;
					continue;
				}
				if (v[i] == v[j] && j > i + 1) {
					dp[i][j] = 1 + dp[i + 1][j - 1];
				}
				else {
					dp[i][j] = min({dp[i][j], dp[i + 1][j] + 1, dp[i][j - 1] + 1});
				}
			}
		}
		cout << dp[0][n - 1];
	}
}