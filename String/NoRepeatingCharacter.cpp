// https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
// Problem:
// Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in
// S. If there is no non-repeating character, return '$'.

// Example 1:
// Input:
// S = hello
// Output: h
// Explanation: In the given string, the
// first character which is non-repeating
// is h, as it appears first and there is
// no other 'h' in the string.

// Example 2:
// Input:
// S = zxvczbtxyzvy
// Output: c
// Explanation: In the given string, 'c' is
// the character which is non-repeating. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Number of distinct characters).
// Note: N = |S|

// Constraints:
// 1 <= N <= 103

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int freq[26]={0};
    for(char c:s) freq[c-'a']++;
    for(char c:s)
        if(freq[c-'a']==1){
            cout<< c;
            return 0;
        }
    cout << '$';
    return 0;
}