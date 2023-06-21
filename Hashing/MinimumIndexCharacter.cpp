// https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1
// Problem:
// Given a string str and another string patt. Find the minimum index of the character in str that is
// also present in patt.

// Example 1:
// Input:
// str = geeksforgeeks
// patt = set
// Output: 1
// Explanation: e is the character which is
// present in given str "geeksforgeeks"
// and is also presen in patt "set". Minimum
// index of e is 1.

// Example 2:
// Input:
// str = adcffaet
// patt = onkl
// Output: -1
// Explanation: There are none of the
// characters which is common in patt
// and str.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Number of distinct characters).

// Constraints:
// 1 ≤ |str|,|patt| ≤ 105
// 'a' <= stri, patti <= 'z'

#include <iostream>
#include <string>
using namespace std;
int minIndexChar(string str, string patt)
{
    bool freq[26] = {false};
    for (char c : patt)
    {
        freq[c - 'a'] = true;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (freq[str[i] - 'a'])
            return i;
    }
    return -1;
}
int main()
{
    string str,patt;
    cin >> str>>patt;
    cout << minIndexChar(str,patt);
    return 0;
}