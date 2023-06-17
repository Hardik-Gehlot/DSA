// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
// Given two strings a and b consisting of lowercase characters. The task is to check whether two given
// strings are an anagram of each other or not. An anagram of a string is another string that contains
// the same characters, only the order of characters can be different. For example, act and tac are an
// anagram of each other.

// Note:-
//     If the strings are anagrams you have to return True or else return False
//     |s| represents the length of string s.

// Example 1:
// Input:a = geeksforgeeks, b = forgeeksgeeks
// Output: YES
// Explanation: Both the string have same characters with
//         same frequency. So, both are anagrams.

// Example 2:
// Input:a = allergy, b = allergic
// Output: NO
// Explanation: Characters in both the strings are 
//         not same, so they are not anagrams.
// Expected Time Complexity:O(|a|+|b|).
// Expected Auxiliary Space: O(Number of distinct characters).

// Constraints:
// 1 ≤ |a|,|b| ≤ 10^5


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    // int m = a.size();
    // int n= b.size();
    // if(m!=n) cout<< false;
    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());
    // for(int i =0;i<m;i++){
    //     if(a[i]!=b[i]) return false;
    // }
    // cout<< true;
    
    vector<int>freq(26,0);
    
    if(a.length()!=b.length()){
        cout<< false;
    }
    
    for(int i=0;i<a.length();i++){
        freq[a[i]-'a']++;
        freq[b[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            cout<< false;
        }
    }
    cout<< true;
    return 0;
}