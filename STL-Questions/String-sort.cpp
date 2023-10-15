/*
PROBLEM-------------------------------



Nishant is very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if two strings have a common part, then string with longer length should come first. Eg bat ,batman are 2 strings have common part as bat - then sorted order should have - batman, bat.

Input Format:
N(integer) followed by N strings.

Constraints:
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman



Sample Output
apple
batman
bat


*/

#include <bits/stdc++.h>
using namespace std;
bool compare(string a,string b)
{
	if(a.size()<=b.size() && b.substr(0,a.size())==a) return a.length()>b.length();
	else if(b.size()<=a.size() && a.substr(0,b.size())==b) return a.length()>b.length();
	else{
	    return a<b;
	}

}

int main() {
int n;
cin>>n;
string* s=new string[n];

//
for(int i=0;i<n;i++)
{
	cin>>s[i];
}
sort(s,s+n,compare);
for(int i=0;i<n;i++)
{
	cout<<s[i]<<endl;
}
	return 0;
}