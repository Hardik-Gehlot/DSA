// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
// Given a string S, find the length of the longest substring with all distinct characters. 

// Example 1:
// Input:
// S = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest 
// substring with all distinct characters.

// Example 2:
// Input: 
// S = "aaa"
// Output: 1
// Explanation: "a" is the longest substring 
// with all distinct characters.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(K), where K is Constant.


// Constraints:
// 1<=|S|<=105

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map <char,int> m;
    int ans = 0,l = 0,r = 0,n = s.size();
    while(r < n){
        if(m[s[r]]) m[s[l++]]--;
        else m[s[r++]]++;
        ans = max(ans,r-l);
    }
    cout<< ans;
    return 0;
}