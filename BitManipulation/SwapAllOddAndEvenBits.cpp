// https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1
// Problem:
// Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the
// given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit
// is swapped with an adjacent bit on the right side(even position bits are highlighted in the binary
// representation of 23), and every odd position bit is swapped with an adjacent on the left side.

// Example 1:

// Input: N = 23
// Output: 43
// Explanation:
// Binary representation of the given number
// is 00010111 after swapping
// 00101011 = 43 in decimal.

// Example 2:

// Input: N = 2
// Output: 1
// Explanation:
// Binary representation of the given number
// is 10 after swapping 01 = 1 in decimal.

// Expected Time Complexity: O(1).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 109

#include <iostream>
using namespace std;
unsigned int swapBits(unsigned int n)
{
    int mask1 = 0xAAAAAAAA; // preserve even
    int mask2 = 0x55555555; // preserve odd

    return ((n & mask1) >> 1) | ((n & mask2) << 1);
}
int main()
{
    unsigned int n;
    cin >> n;
    cout << swapBits(n);
    return 0;
}