// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
// Problem:
// Given a number N and a bit number K, check if Kth index bit of N is set or not. A bit is called set
// if it is 1. Position of set bit '1' should be indexed starting with 0 from LSB side in binary
// representation of the number.
// Note: Index is starting from 0.
// Example 1:

// Input: N = 4, K = 0
// Output: No
// Explanation: Binary representation of 4 is 100,
// in which 0th index bit from LSB is not set.
// So, return false.

// Example 2:

// Input: N = 4, K = 2
// Output: Yes
// Explanation: Binary representation of 4 is 100,
// in which 2nd index bit from LSB is set.
// So, return true.

// Example 3:

// Input: N = 500, K = 3
// Output: No
// Explanation: Binary representation of 500 is
// 111110100, in which 3rd index bit from LSB is not set.
// So, return false.

// Expected Time Complexity: O(1).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 109
// 0 ≤ K ≤ floor(log2(N) + 1)

#include <iostream>
using namespace std;
bool checkKthBit(int n, int k)
{
    // Approach 1:
    //  int num = pow(2,k);
    //  return (n&num);

    // Approach 2:
    return (n >> k) & 1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << checkKthBit(n, k);
    return 0;
}