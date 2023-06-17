// https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
// Problem:
// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
// For Example:
// ab: Number of insertions required is 1. bab or aba
// aa: Number of insertions required is 0. aa
// abcd: Number of insertions required is 3. dcbabcd


// Example 1:
// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked
// with bold characters in dcbabcd

// Example 2:
// Input: str = "aa"
// Output: 0
// Explanation:"aa" is already a palindrome.

// Expected Time Complexity: O(N2), N = |str|
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ |str| ≤ 103
// str contains only lower case alphabets.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int lcs(  string s1 , string s2){
    int n = s1.size() ; 
    int m = s2.size();
    vector<vector<int>>dp( n+1 , vector<int>( m+1 , 0));
    for( int i =1 ; i<=n ; i++){
        for( int j =1 ; j<=m ; j++){
            if( s1[i-1]== s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(  dp[i-1][j] , dp[i][j-1] );
            }
        }
    }
    return dp[n][m];
}
    
 int lps( string s){
    string t = s;
    reverse(t.begin()  , t.end());
    return lcs( s ,t);
 }
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int lcs =lps( s);
    cout<< n- lcs;
    return 0;
}