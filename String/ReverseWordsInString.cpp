// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
// Problem:
// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

// Example 1:

// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole
// string(not individual words), the input
// string becomes
// much.very.program.this.like.i

// Example 2:

// Input:
// S = pqr.mno
// Output: mno.pqr
// Explanation: After reversing the whole
// string , the input string becomes
// mno.pqr

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)


// Constraints:
// 1 <= |S| <= 105

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans = "";
    string temp = "";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='.'){
            ans += temp;
            temp = "";
            ans += '.';
        }else{
            temp = s[i]+temp;
        }
    }
    if(temp.length()>0){
        ans += temp;
    }
    cout<< ans;
    return 0;
}