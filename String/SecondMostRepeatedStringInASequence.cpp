// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1
// Problem:
// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string
// in the given sequence.

// Note: No two strings are the second most repeated, there will be always a single string.

// Example 1:
// Input:
// N = 6
// arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
// Output: bbb
// Explanation: "bbb" is the second most 
// occurring string with frequency 2.

// Example 2:
// Input: 
// N = 6
// arr[] = {geek, for, geek, for, geek, aaa}
// Output: for
// Explanation: "for" is the second most
// occurring string with frequency 2.

// Expected Time Complexity: O(N*max(|Si|).
// Expected Auxiliary Space: O(N*max(|Si|).

// Constraints:
// 1<=N<=103

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
string secFrequent (string arr[], int n){
    unordered_map<string, int> mp;
    int fMax = -1e6;
    int sMax = -1e6;
    
    for(int i=0; i<n; i++) 
        mp[arr[i]]++;
    
    for(auto it : mp) {
        
        if(it.second > fMax) {
            sMax = fMax;
            fMax = it.second;
        }
        
        else if(it.second > sMax && it.second != fMax) {
            sMax = it.second;
        }
    }
    if(mp.size() == 1){
        return "";
    }
    for(auto i : mp){
        if(i.second == sMax){
            return i.first;
        }
    }
    return "";
}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<secFrequent(arr,n);
    return 0;
}