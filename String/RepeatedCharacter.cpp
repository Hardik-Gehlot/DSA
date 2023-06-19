// https://practice.geeksforgeeks.org/problems/repeated-character2058/1
// Problem:
// Given a string consisting of lowercase english alphabets. Find the repeated character present first
// in the string.

// Example 1:
// Input:
// S = "geeksforgeeks"
// Output: g
// Explanation: g, e, k and s are the repeating
// characters. Out of these, g occurs first. 

// Example 2:
// Input: 
// S = "abcde"
// Output: -1
// Explanation: No repeating character present.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=|S|<=105

#include<iostream>
#include<string>
using namespace std;
char firstRep (string s)
{
    int freq[26]={0};
    for(char ch:s){
        freq[ch-'a']++;
    }
    for(char ch:s){
        if(freq[ch-'a']>1) return ch;
    }
    return '#';
}
int main(){
    string s;
    cin>>s;
    cout << firstRep(s);
    return 0;
}