// https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1
// Problem:
// Given two numbers M and N. The task is to find the position of the rightmost different bit in the
// binary representation of numbers. return -1 if no difference

// Example 1:

// Input: M = 11, N = 9
// Output: 2
// Explanation: Binary representation of the given
// numbers are: 1011 and 1001,
// 2nd bit from right is different.

// Example 2:

// Input: M = 52, N = 4
// Output: 5
// Explanation: Binary representation of the given
// numbers are: 110100 and 0100,
// 5th-bit from right is different.

// Expected Time Complexity: O(max(log m, log n)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= M <= 109
// 0 <= N <= 109

#include <iostream>
using namespace std;
int posOfRightMostDiffBit(int m, int n)
{
    int a = m ^ n;
    int count = 0;
    while (a > 0)
    {
        count++;
        if ((a & 1) == 1)
            return count;
        a = a >> 1;
    }
    return -1;
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << posOfRightMostDiffBit(m, n);
    return 0;
}