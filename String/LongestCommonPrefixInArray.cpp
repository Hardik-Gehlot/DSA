// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
// Given an array of N strings, find the longest common prefix among all strings present in the array.

// Example 1:
// Input:
// N = 4
// arr[] = {geeksforgeeks, geeks, geek,
//          geezer}
// Output: gee
// Explanation: "gee" is the longest common
// prefix in all the given strings.

// Example 2:
// Input: 
// N = 2
// arr[] = {hello, world}
// Output: -1
// Explanation: There's no common prefix
// in the given strings.

// Expected Time Complexity: O(N*min(|arri|)).
// Expected Auxiliary Space: O(min(|arri|)) for result.

// Constraints:
// 1 ≤ N ≤ 103
// 1 ≤ |arri| ≤ 103

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    if(n==1) cout<< arr[0];
    string com = arr[0];
    for(int i=1;i<n && com.size()>=1;i++){
        string s = arr[i];
        string temp="";
        for(int j=0;j<s.size();j++){
            if(s[j]!=com[j]){
                temp = com.substr(0,j);
                break;
            }
            temp = temp+s[j];
        }
        com = temp;
    }
    if(com.size()>0) cout<<com;
    else cout<<"-1";
    return 0;
}