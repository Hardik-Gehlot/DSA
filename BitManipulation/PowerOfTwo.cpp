// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

// Example 1:

// Input: N = 1
// Output: YES
// Explanation:1 is equal to 2
// raised to 0 (20 = 1).

// Example 2:

// Input: N = 98
// Output: NO
// Explanation: 98 cannot be obtained
// by any power of 2.

// Expected Time Complexity:O(log N).
// Expected Auxiliary Space:O(1).

// Constraints:
// 0 ≤N ≤1018

#include <iostream>
using namespace std;
bool isPowerofTwo(long long n)
{
    int count = 0;
    while (n)
    {
        count += (n & 1);
        n = n >> 1;
    }
    return count == 1;
}
int main()
{
    long long n;
    cin >> n;
    cout << isPowerofTwo(n);
    return 0;
}