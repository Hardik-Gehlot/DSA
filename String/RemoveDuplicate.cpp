// https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1
// Problem:
// Given a string without spaces, the task is to remove duplicates from it.

// Note: The original order of characters must be kept the same. 

// Example 1:
// Input: S = "zvvo"
// Output: "zvo"
// Explanation: Only keep the first
// occurrence

// Example 2:
// Input: S = "gfg"
// Output: gf
// Explanation: Only keep the first
// occurrence
// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(constant)

// Constraints:
// 1 <= |S| <= 105
// S conatins lowercase english alphabets

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int freq[26]={0};
    for(int i=0; i<s.length(); i++){
        if(freq[s[i]-'a']==0){
            freq[s[i]-'a']++;
        }else{
            s.erase(i,1);
            i--;
        }
    }
    cout<<s;
    return 0;
}