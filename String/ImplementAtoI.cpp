// https://practice.geeksforgeeks.org/problems/implement-atoi/1
// Problem:
// Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

// Note: You are not allowed to use inbuilt function.

// Example 1:
// Input:
// str = 123
// Output: 123

// Example 2:
// Input:
// str = 21a
// Output: -1
// Explanation: Output is -1 as all
// characters are not digit only.

// Expected Time Complexity: O(|S|), |S| = length of string str.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ length of S ≤ 10

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans = 0;
    int mul = 1;
    int i=0;
    if(s[0]=='-'){
        mul=-1;
        i=1;
    }
    while(i<s.size()){
        if(s[i]<48 || s[i]>57) return -1;
        ans = ans*10 + (s[i]-48);
        i++;
    }
    cout<< ans*mul;
    return 0;
}