// https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1
// Problem:
// Given a number N. Find the length of the longest consecutive 1s in its binary representation.

// Example 1:

// Input: N = 14
// Output: 3
// Explanation:
// Binary representation of 14 is
// 1110, in which 111 is the longest
// consecutive set bits of length is 3.

// Example 2:

// Input: N = 222
// Output: 4
// Explanation:
// Binary representation of 222 is
// 11011110, in which 1111 is the
// longest consecutive set bits of length 4.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106

#include <iostream>
using namespace std;
int maxConsecutiveOnes(int n)
{
    int count = 0;
    int maxCount = 0;
    while (n > 0)
    {
        if ((n & 1) == 1)
        {
            count++;
            maxCount = max(count, maxCount);
        }
        else
            count = 0;
        n = n >> 1;
    }
    return maxCount;
}
int main()
{
    int n;
    cin >> n;
    cout << maxConsecutiveOnes(n);
    return 0;
}