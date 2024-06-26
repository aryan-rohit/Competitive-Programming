// Problem Name: Wildcard Pattern Matching
// Problem Difficulty: None
// Problem Constraints: Size(str)*Size(pattern) < 100000000
// Problem Description:
// Given a text <b>'str'</b> and a wildcard pattern <b>'pattern'</b>,
// The wildcard pattern can include the characters <b>‘?’</b> and <b>‘ * ’</b>. <br />
// <b>‘?’</b> – matches any single character <br />
// <b>‘*’ </b>  – Matches any sequence of characters (including the empty sequence) <br />
// Find out if the given text matches the pattern.

// Input Format: Each testcase contains two strings.
// First line contains the text string and the second line contains the pattern.
// Sample Input: aa
// a*a

// Output Format: Print <b>1</b> if the string matches the pattern, else  print <b>0</b>.
// Sample Output: 1



// =====Solution=====
#include <bits/stdc++.h>
using namespace std;

bool wildcard(const string &text,const string &pattern){
    int r = text.size();
    int c = pattern.size();

    vector<vector<bool>>dp(r+1,vector<bool>(c+1));   //dp[i][j] denotes if the text till i and pattern till j match
    
    // for(int i=0;i<=r;i++){
    //     dp[i][0] = dp[0][i] = false  ;
    // }

    dp[0][0] = true ; //Base case - Strings of 0 length always match

    //If first character of pattern is * then mark (0,1) as true since * can be mapped with empty sequence as well
    if(pattern[0] == '*'){
        dp[0][1] = true ;
    }
    for(int i=0;i<pattern.size() and pattern[i]=='*';i++){
        dp[i][1] = true ; 
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(text[i-1] == pattern[j-1]){
                //If current character of each string matches then mark this as however its previous state was
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '?'){
                //Since ? can be mapped with all characters , do the same for this as well
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*'){
                //Since * can be mapped with all strings , mark current state as OR of both previous states
                dp[i][j] = dp[i-1][j] || dp[i][j-1] ; 
            }
            else {
                //Since no matching took place , mark this cell as false
                dp[i][j] = false ;
            }
        }
    }

    /*
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            cout << dp[i][j] << " "; 
        }
        cout << endl ;
    }
    */


    return dp[r][c];
}

int main() {
    string a,b;
    cin >> a >> b;

    if(a==b){
        cout<<1;
        return 0;
    }

    //Remove consecutive * from the pattern string
    for(int i=0;i+1<b.size();i++){
        if(b[i] == '*' && b[i+1] == '*'){
            b.erase(i,1);
            i--;
        }
    }

   // cout << "b = "<< b <<endl;

    cout << wildcard(a,b);

    return 0;
}