// https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
// Problem:
// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another
// string 'a' by exactly 2 places.

// Example 1:
// Input:
// a = amazon
// b = azonam
// Output: 1
// Explanation: amazon can be rotated anti
// clockwise by two places, which will make
// it as azonam.

// Example 2:
// Input:
// a = geeksforgeeks
// b = geeksgeeksfor
// Output: 0
// Explanation: If we rotate geeksforgeeks by
// two place in any direction , we won't get
// geeksgeeksfor.

// Expected Time Complexity: O(N).
// Expected Auxilary Complexity: O(N).
// Challenge: Try doing it in O(1) space complexity.

// Constraints:
// 1 ≤ length of a, b ≤ 105

#include<iostream>
#include<string>
using namespace std;
int main(){
    string str1,str2;
    cin>>str1>>str2;
    string anti = "",clk="";
    int n = str1.size();
    for(int i=2;i<n;i++){
        anti = anti + str1[i];
    }
    anti = anti + str1[0] + str1[1];
    clk = clk + str1[n-2]+str1[n-1];
    for(int i=0;i<n-2;i++){
        clk = clk+str1[i];
    }
    cout<< (clk == str2 || anti == str2);
    return 0;
}