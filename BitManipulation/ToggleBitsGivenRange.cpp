// https://practice.geeksforgeeks.org/problems/toggle-bits-given-range0952/1
// Problem:
// Given a non-negative number N and two values L and R. The problem is to toggle the bits in the range
// L to R in the binary representation of N, i.e, to toggle bits from the rightmost Lth bit to the
// rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0. Print N after the bits
// are toggled.

// Example 1:
// Input:
// N = 17 , L = 2 , R = 3
// Output:
// 23
// Explanation:
// (17)10 = (10001)2.  After toggling all
// the bits from 2nd to 3rd position we get
// (10111)2 = (23)10

// Example 2:
// Input:
// N = 50 , L = 2 , R = 5
// Output:
// 44
// Explanation:
// (50)10 = (110010)2.  After toggling all
// the bits from 2nd to 5th position we get
// (101100)2 = (44)10

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

#include <iostream>
#include<cmath>
using namespace std;
int toggleBits(int N, int L, int R)
{
    int mask = pow(2, R - L + 1) - 1;
    mask = mask << (L - 1);
    return N ^ mask;
}
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    cout << toggleBits(n, l, r);
    return 0;
}