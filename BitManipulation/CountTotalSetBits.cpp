// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
// Problem:
// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

// Example 1:

// Input: N = 4
// Output: 5
// Explanation:
// For numbers from 1 to 4.
// For 1: 0 0 1 = 1 set bits
// For 2: 0 1 0 = 1 set bits
// For 3: 0 1 1 = 2 set bits
// For 4: 1 0 0 = 1 set bits
// Therefore, the total set bits is 5.

// Example 2:

// Input: N = 17
// Output: 35
// Explanation: From numbers 1 to 17(both inclusive),
// the total number of set bits is 35.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 108

#include <iostream>
#include<cmath>
using namespace std;
int countSetBits(int n)
{
    if (n <= 1)
        return n;
    int bit = log2(n);
    int sum = pow(2, bit - 1) * bit + (n - pow(2, bit) + 1) + countSetBits(n - pow(2, bit));
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n);
    return 0;
}