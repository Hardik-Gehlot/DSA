// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// Problem:
// Given an array of positive integers. Find the length of the longest sub-sequence such that elements
// in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Example 1:
// Input:
// N = 7
// a[] = {2,6,1,9,4,5,3}
// Output:
// 6
// Explanation:
// The consecutive numbers here
// are 1, 2, 3, 4, 5, 6. These 6
// numbers form the longest consecutive
// subsquence.

// Example 2:
// Input:
// N = 7
// a[] = {1,9,3,10,4,20,2}
// Output:
// 4
// Explanation:
// 1, 2, 3, 4 is the longest
// consecutive subsequence.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// 0 <= a[i] <= 105

#include <iostream>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
{
    int freq[100000] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int count = 0;
    int m = 0;
    for (int i = 0; i < 100000; i++)
    {
        if (freq[i] != 0)
        {
            count++;
            m = max(m, count);
        }
        else
        {
            count = 0;
        }
    }
    return m;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findLongestConseqSubseq(arr,n);
    return 0;
}