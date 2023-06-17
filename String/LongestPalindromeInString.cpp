// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// Problem:
// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

// Example 1:
// Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".

// Example 2:
// Input: 
// S = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the 
// longest palindromes with same length.
// The result is the one with the least
// starting index.

// Expected Time Complexity: O(|S|2).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 103

#include<iostream>
#include<string>
using namespace std;
int main(){
    string S;
    cin>>S;
    int n = S.size();
        int start=0,end=0;
        int maxl=1;
        //for odd length
        for(int i=0;i<n;i++){
            int l = i,r=i;
            while(l>=0 && r<n){
                if(S[l]!=S[r]) break;
                l--;
                r++;
            }
            int len = r-l-1;
            if(len>maxl){
                maxl=len;
                start = l+1;
                end = r-1;
            }
        }
        //for even length
        for(int i=0;i<n;i++){
            int l=i,r=i+1;
            while(l>=0 && r<n){
                if(S[l]!=S[r]) break;
                l--;
                r++;
            }
            int len = r-l-1;
            if(len>maxl){
                maxl=len;
                start = l+1;
                end = r-1;
            }
        }
        cout<< S.substr(start,maxl);
    
    return 0;
}