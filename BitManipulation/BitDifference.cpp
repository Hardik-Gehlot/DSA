// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1
// Problem:
// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

// Example 1:

// Input: A = 10, B = 20
// Output: 4
// Explanation:
// A  = 01010
// B  = 10100
// As we can see, the bits of A that need
// to be flipped are 01010. If we flip
// these bits, we get 10100, which is B.

// Example 2:

// Input: A = 20, B = 25
// Output: 3
// Explanation:
// A  = 10100
// B  = 11001
// As we can see, the bits of A that need
// to be flipped are 10100. If we flip
// these bits, we get 11001, which is B.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ A, B ≤ 106

#include <iostream>
using namespace std;
int countBitsFlip(int a, int b)
{
    int n = a ^ b;
    int count = 0;
    while (n)
    {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << countBitsFlip(a, b);
    return 0;
}