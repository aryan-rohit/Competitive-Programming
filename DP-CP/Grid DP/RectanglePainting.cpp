// Problem Name: Rectangle Painting
// Problem Difficulty: None
// Problem Constraints: N <= 50
// Problem Description:
// There is a square grid of size n×n. Some cells are colored in black, all others are colored in white. In one operation you can select some rectangle and color all its cells in white. It costs max(h,w) to color a rectangle of size h×w. You are to make all cells white for minimum total cost.

// Input Format: The first line contains a single integer n (1≤n≤50) — the size of the square grid.

// Each of the next n lines contains a string of length n, consisting of characters '.' and '#'. The j-th character of the i-th line is '#' if the cell with coordinates (i,j) is black, otherwise it is white.


// Sample Input: 3
// ###
// #.#
// ###

// Output Format: Print a single integer — the minimum total cost to paint all cells in white.
// Sample Output: 3



// =====Solution=====
#include<bits/stdc++.h>

using namespace std;

using namespace std;

char p[60][60];
int n, D[52][52][52][52];
int main() {
    int i, j, k;    
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s", p[i] + 1);
    }
    for (int dx = 1; dx <= n; dx++) {
        for (int dy = 1; dy <= n; dy++) {
            for (int bx = 1; bx + dx - 1 <= n; bx++) {
                for (int by = 1; by + dy - 1 <= n; by++) {
                    int ex = bx + dx - 1, ey = by + dy - 1;
                    if (dx == 1 && dy == 1) {
                        D[bx][by][ex][ey] = (p[bx][by] == '#');
                        continue;
                    }
                    D[bx][by][ex][ey] = max(dx, dy);
                    for (i = bx; i < ex; i++) {
                        D[bx][by][ex][ey] = min(D[bx][by][ex][ey], D[bx][by][i][ey] + D[i + 1][by][ex][ey]);
                    }
                    for (i = by; i < ey; i++) {
                        D[bx][by][ex][ey] = min(D[bx][by][ex][ey], D[bx][by][ex][i] + D[bx][i + 1][ex][ey]);
                    }
                }
            }
        }
    }
    cout<<D[1][1][n][n];
}