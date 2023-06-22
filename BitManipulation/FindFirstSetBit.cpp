// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1
// Given an integer N. The task is to return the position of first set bit found from the right side in
// the binary representation of the number.
// Note: If there is no set bit in the integer N, then return 0 from the function.

// Example 1:
// Input: N = 18
// Output: 2
// Explanation: Binary representation of
// 18 is 010010,the first set bit from the
// right side is at position 2.

// Example 2:
// Input: N = 12
// Output: 3
// Explanation: Binary representation
// of  12 is 1100, the first set bit
// from the right side is at position 3.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= N <= 108`

#include <iostream>
using namespace std;
unsigned int getFirstSetBit(int n)
{
    if (n == 0)
        return 0;
    int count = 0;
    while (n > 0)
    {
        count++;
        if ((n & 1) == 1)
            return count;
        n = n >> 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    cout<<getFirstSetBit(n);
    return 0;
}