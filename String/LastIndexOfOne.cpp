// https://practice.geeksforgeeks.org/problems/last-index-of-15847/1
// Problem:
// Given a string S consisting only '0's and '1's,  find the last index of the '1' present in it.

// Example 1:
// Input:
// S = 00001
// Output:
// 4
// Explanation:
// Last index of  1 in given string is 4.

 

// Example 2:
// Input:
// 0
// Output:
// -1
// Explanation:
// Since, 1 is not present, so output is -1. 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1'){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}