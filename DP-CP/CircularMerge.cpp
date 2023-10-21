// Problem Name: Circular Merging
// Problem Difficulty: None
// Problem Constraints: 2 ≤ N ≤ 400 
// 1 ≤ ai ≤ 10^9 for each valid i
// Problem Description:
// N integers A1,A2,…,AN are placed in a circle in such a way that for each valid i, Ai and Ai+1 are adjacent, and A1 and AN are also adjacent.

// We want to repeat the following operation exactly N−1 times (until only one number remains):

// :- Select two adjacent numbers. Let's denote them by a and b.
// :- Score a+b penalty points.
// :- Erase both a and b from the circle and insert a+b in the space between them.

// What is the minimum number of penalty points we can score?

// Input Format: The first line contains a single integer N.
// The second line contains N space-separated integers a1,a2,…,aN.
// Sample Input: 
// 3
// 10 10 1
// Output Format: Print a single line containing one integer — the minimum number of penalty points.
// Sample Output: 32



//wrong code....but quite similar
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[401][401];

ll solve(int i, int j, int n, vector<ll> &a) {
  if (i == j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  ll ans = 1e18;
  for (int k = i; k < j; k++) {
    ans = min(ans, solve(i, k, n, a) + solve(k + 1, j, n, a) + a[i] + a[j]);
  }
  return dp[i][j] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(1, n, n, a) << endl;
  return 0;
}
