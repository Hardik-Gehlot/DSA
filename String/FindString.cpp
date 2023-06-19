// https://practice.geeksforgeeks.org/problems/implement-strstr/1
// Problem:
// The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the
// string s. The function returns and integer denoting the first occurrence of the string x
// in s (0 based indexing).

// Note: You are not allowed to use inbuilt function.

// Example 1:
// Input:
// s = GeeksForGeeks, x = Fr
// Output: -1
// Explanation: Fr is not present in the
// string GeeksForGeeks as substring.

// Example 2:
// Input:
// s = GeeksForGeeks, x = For
// Output: 5
// Explanation: For is present as substring
// in GeeksForGeeks from index 5 (0 based
// indexing).

// Expected Time Complexity: O(|s|*|x|)
// Expected Auxiliary Space: O(1)
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,x;
    cin>>s>>x;
    int m = x.size();
    int n = s.size();
    if(m>=n) cout<< (s==x)?0:-1;
    int left=0;
    int right=m-1;
    while(left<n-m){
        string temp = s.substr(left,m);
        if(temp==x) cout<< left;
        else left++;
    }
    cout<< -1;
    return 0;
}