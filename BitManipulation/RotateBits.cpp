// https://practice.geeksforgeeks.org/problems/rotate-bits4524/1
// Problem:
// Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and print the results in decimal values after each of the rotation.
// Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000.....001100.

// Example 1:

// Input:
// N = 28, D = 2
// Output:
// 112
// 7
// Explanation: 28 in Binary is:
// 000...011100
// Rotating left by 2 positions, it becomes
// 00...1110000 = 112 (in decimal).
// Rotating right by 2 positions, it becomes
// 000...000111 = 7 (in decimal).

// â€‹Example 2:

// Input:
// N = 29, D = 2
// Output:
// 116
// 16391
// Explanation: 29 in Binary is:
// 000...011101
// Rotating left by 2 positions, it becomes
// 00...1110100 = 116 (in decimal).
// Rotating right by 2 positions, it becomes
// 010...000111 = 16391 (in decimal).

// Expected Time Complexity: O(1).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <  216
// 1 <= D <= 105

#include <iostream>
#include <vector>
using namespace std;
vector<int> rotate(int n, int d)
{
    d = d % 16;
    int l = ((n << d) | (n >> (16 - d))) & 65535;
    int r = ((n >> d) | (n << (16 - d))) & 65535;
    return {l, r};
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> ans = rotate(n, d);
    for (int x : ans)
    {
        cout << x << endl;
    }
    return 0;
}