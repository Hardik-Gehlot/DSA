// https://practice.geeksforgeeks.org/problems/check-frequencies4211/1
// Problem:
// Given a string s which contains only lower alphabetic characters, check if it is possible to remove
// at most one character from this string in such a way that frequency of each distinct character
// becomes same in the string.

// Example 1:
// Input:
// s = xyyz
// Output: 1
// Explanation: Removing one 'y' will make
// frequency of each letter 1.

// Example 2:
// Input:
// s = xxxxyyzz
// Output: 0
// Explanation: Frequency can not be made same
// same by removing just 1 character.

// Expected Time Complexity: O(N) where N is length of str
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= str.length() <= 104

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
bool sameFreq(string s)
{
    unordered_map<char, int> mp1, mp2;
    set<pair<int, int>> st;

    for (auto i : s)
        mp1[i]++;

    for (auto i : mp1)
        mp2[i.second] += 1;

    for (auto i : mp2)
        st.insert({i.first, i.second});

    if (st.size() == 1)
        return 1;
    if (st.size() == 2)
    {
        int diff = 0, cnt = 0;

        for (auto i : st)
        {
            if (i.first == 1 and i.second == 1)
                return 1;
            if (i.second > 1 and cnt == 1)
                return 0; // both character frequency has difference greater than 1 so cant delete atmost one character
            diff = i.first - diff;
            cnt++;
        }

        if (abs(diff) == 1)
            return 1;
    }
    return 0;
}
int main()
{
    string s;
    cin >> s;
    cout<<sameFreq(s);
    return 0;
}