// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Problem:
// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example 1:
// Input:
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.

// Example 2:
// Input:
// N = 3
// arr[] = {0 1 0}
// Output:
// 0 0 1
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 10^6
// 0 <= A[i] <= 2

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
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
        arr[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1;
    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] + " ";
    }
}