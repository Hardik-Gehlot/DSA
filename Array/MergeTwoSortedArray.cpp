// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// Problem:
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space. Modify arr1 so that it contains the
// first N elements and modify arr2 so that it contains the last M elements.

// Example 1:
// Input: 
// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 0 1 2 3 5 6 7 8 9.

// Example 2:
// Input: 
// n = 2, arr1[] = [10 12] 
// m = 3, arr2[] = [5 18 20]
// Output: 
// arr1[] = [5 10]
// arr2[] = [12 18 20]
// Explanation:
// After merging two sorted arrays 
// we get 5 10 12 18 20.

// Expected Time Complexity:  O((n+m) log(n+m))
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= n, m <= 105
// 0 <= arr1i, arr2i <= 107

#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for(int i =0; i<n; i++){
        cin>>arr1[i];
    }
    for(int i =0; i<m; i++){
        cin>>arr2[i];
    }
    int i = 0, j = 0;
    int sum = n + m;
    long res[sum];
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            res[k++] = arr1[i++];
        else
            res[k++] = arr2[j++];
    }
    while (i < n)
    {
        res[k++] = arr1[i++];
    }
    while (j < m)
    {
        res[k++] = arr2[j++];
    }
    for (int a = 0; a < n; a++)
    {
        arr1[a] = res[a];
    }
    for (int a = 0; a < m; a++)
    {
        arr2[a] = res[a + n];
    }
    for(int i =0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    for(int i =0; i<m; i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}