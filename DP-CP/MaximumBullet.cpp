// Problem Name: Maximum Bullet
// Problem Difficulty: None
// Problem Constraints: 1 ≤ N ≤ 5000 <br>
// 0 ≤ A,B ≤ 5000 <br>
// N <= A+B <br>
// 0 ≤ Ai ≤ 10^9
// Problem Description:
// Kaleen Bhaiya is impressed with Guddu and Bablu so he decides to give them some bullets for their guns. He gives N boxes of bullets (Numbered from 1 to N) to guddu and N boxes of bullets(Numbered from 1 to N) to Bablu.

// Now Kaleen Bhaiya puts some conditions:

// - Guddu can take maximum A boxes of bullets from his set of boxes and Bablu can take maximum B boxes of bullets from his set of boxes.
// - Only one of them can take box with same number i.e if Guddu takes box 1 from his set then Bablu can't take box 1 from his set.
// - They have to start from box 1 and go till box N.
// - They cannot skip any box and they cannot go back.

// Guddu and Bablu are brothers so they decides to take the maximum amount of bullets and will divide them afterwards but Guddu is weak in studies and Bablu bhaiya needs to help Golu for college elections so they asked you for help and in return they will give you a Katta for free.

// Input Format: First line will contain N, A, B.
// The second line contains N integers. The ith integer represents number of bullets in ith box given to Guddu.
// The third line also contains N integers. The ith integer represents number of bullets in ith box given to Bablu.
// Sample Input: 5 3 4
// 8 2 5 3 7
// 8 3 4 6 2
// Output Format: Print a single integer representing the maximum bullets they can get.

// Sample Output: 29



// =====Solution=====
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int             long long int
#define ld              long double
#define lop(i, a, b)    for (int i = a; i < b; i++)
#define rlop(i, b, a)   for (int i = b-1; i >= a; i--)
#define F               first
#define S               second
#define pb              push_back
#define si              set <int>
#define vi              vector <int>
#define pii             pair <int, int>
#define vpi             vector <pii>
#define vpp             vector <pair<int, pii>>
#define mii             map <int, int>
#define mpi             map <pii, int>
#define spi             set <pii>
#define endl            "\n" 
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define mset(a, b, c)   lop (i, 0, c) a[i] = b
#define print1(a, n)    lop (i, 0, n) cout << a[i] << " "; cout << endl

inline int power(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

// typedef tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> Set;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
template<class T, class T2> inline int chkmax(T &x, const T2 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T2> inline int chkmin(T &x, const T2 &y) { return x > y ? x = y, 1 : 0; }
const int MAXN = 5042;

int n, a, b;
int A[MAXN], B[MAXN];

void read()
{
     cin >> n >> a >> b;
     for(int i = 0; i < n; i++) cin >> A[i];
     for(int i = 0; i < n; i++) cin >> B[i];
}

int dp[MAXN][MAXN];

int rec(int i, int cnt_a)
{
     int cnt_b = i - cnt_a;
     if(i == n) return 0;

     int &memo = dp[i][cnt_a]; 
     if(memo != -1) return memo;

     memo = 0;
     if(cnt_a < a) chkmax(memo, A[i] + rec(i + 1, cnt_a + 1));
     if(cnt_b < b) chkmax(memo, B[i] + rec(i + 1, cnt_a));

     return memo;
}

void solve()
{
     memset(dp, -1, sizeof(dp));
     cout << rec(0, 0) << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input4.txt",  "r",  stdin);
    freopen("output4.txt", "w", stdout);
#endif
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     read();
     solve();
     return 0;
}