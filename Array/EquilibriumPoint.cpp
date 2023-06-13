// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
// Problem:
// Given an array A of n positive numbers. The task is to find the first Equilibrium Point in an array.
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the
// sum of elements after it.

// Note: Retun the index of Equilibrium point. (1-based index)

// Example 1:
// Input:
// n = 5
// A[] = {1,3,5,2,2}
// Output: 3
// Explanation:
// equilibrium point is at position 3
// as elements before it (1+3) =
// elements after it (2+2).

// Example 2:
// Input:
// n = 1
// A[] = {1}
// Output: 1
// Explanation:
// Since its the only element hence
// its the only equilibrium point.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 106
// 1 <= A[i] <= 108

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int total = 0;
    int left = 0;

    for (int i = 0; i < n; i++)
        total += arr[i];

    for (int i = 0; i < n; i++)
    {
        if (left == total - arr[i]){
            cout<<i+1;
            return 0;
        }
        else
        {
            total -= arr[i];
            left += arr[i];
        }
    }
    cout << -1;
    return 0;
}