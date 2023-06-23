// https://leetcode.com/problems/optimal-partition-of-string/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency
// Given a string s, partition the string into one or more substrings such that the characters in each
// substring are unique. That is, no letter appears in a single substring more than once.

// Return the minimum number of substrings in such a partition.

// Note that each character should belong to exactly one substring in a partition.

// Example 1:

// Input: s = "abacaba"
// Output: 4
// Explanation:
// Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
// It can be shown that 4 is the minimum number of substrings needed.

// Example 2:

// Input: s = "ssssss"
// Output: 6
// Explanation:
// The only valid partition is ("s","s","s","s","s","s").

// Constraints:
//     1 <= s.length <= 105
//     s consists of only English lowercase letters.

#include <iostream>
#include <string>
#include<vector>
using namespace std;
int partitionString(string s)
{
    vector<int> lastSeen(26, -1);
    int count = 1, substringStart = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (lastSeen[s[i] - 'a'] >= substringStart)
        {
            count++;
            substringStart = i;
        }
        lastSeen[s[i] - 'a'] = i;
    }
    return count;
}
int main()
{
    string s;
    cin >> s;
    cout<<partitionString(s);
    return 0;
}