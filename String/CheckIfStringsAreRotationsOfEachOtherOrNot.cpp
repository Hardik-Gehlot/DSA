// https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
// Problem:
// Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1.
// The characters in the strings are in lowercase.

// Example 1:
// Input:
// geeksforgeeks
// forgeeksgeeks
// Output: 
// 1
// Explanation: s1 is geeksforgeeks, s2 is
// forgeeksgeeks. Clearly, s2 is a rotated
// version of s1 as s2 can be obtained by
// left-rotating s1 by 5 units.


// Example 2:
// Input:
// mightandmagic
// andmagicmigth
// Output: 
// 0
// Explanation: Here with any amount of
// rotation s2 can't be obtained by s1. 

// Expected Time Complexity: O(N).
// Expected Space Complexity: O(N).
// Note: N = |s1|.

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    // if(s1.size() != s2.size()) return false;
        // int pivot = -1;
        // int j=0;
        // for(int i=0;i<s1.size();i++){
        //     if(s1[i]==s2[0]){
        //         pivot = i;
        //         break;
        //     }
        // }
        // for(int i=pivot;i<s1.size();i++){
        //     if(s1[i]!=s2[j]) return false;
        //     j++;
        // }
        // for(int i=0;i<pivot;i++){
        //     if(s1[i]!=s2[j]) return false;
        //     j++;
        // }
        // return true;
        if(s1.size()!=s2.size()) {cout<< false;return 0;}
        
        string con=s1+s1;
        
        if(con.find(s2) != string::npos){
            cout<< true;
            return 0;
        }
        cout<< false;
    
    return 0;
}