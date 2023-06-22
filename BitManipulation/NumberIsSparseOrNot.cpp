// https://practice.geeksforgeeks.org/problems/number-is-sparse-or-not-1587115620/1
// Problem:
// Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.

// Example 1:

// Input: N = 2
// Output: 1
// Explanation: Binary Representation of 2 is 10,
// which is not having consecutive set bits.
// So, it is sparse number.

// Example 2:

// Input: N = 3
// Output: 0
// Explanation: Binary Representation of 3 is 11,
// which is having consecutive set bits in it.
// So, it is not a sparse number.

// Expected Time Complexity: O(1).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106

#include <iostream>
using namespace std;
bool isSparse(int n)
{
    while (n > 0)
    {
        if ((n)&1 == 1 && ((n >> 1) & 1) == 1)
        {
            return false;
        }
        // n = n>>1; is same as n=n/2;
        n = n / 2;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    cout << isSparse(n);
    return 0;
}