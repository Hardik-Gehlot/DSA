// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Problem:
// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each
// block is 1, compute how much water can be trapped between the blocks during the rainy season.

// Example 1:
// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10
// Explanation:

//      |
// |    |
// |  | |
// |  | |
// bars{3 0 0 2 0 4}
// totalwaterTrapped = 3+3+1+3=10

// Example 2:
// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above
// block of height 4 is 3 units and above
// block of height 0 is 7 units. So, the
// total unit of water trapped is 10 units.

// Example 3:
// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 3 < N < 106
// 0 < Ai < 108

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
        int left[n];
    int right[n];
    int l = 0;
    int r = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        l = max(l , arr[i]);
        left[i]= l;
    }
    for (int i = n-1; i>=0; i--)
    {
        r = max(r, arr[i]);
        right[i] = r;
    }
    for(int i=0; i<n; i++)
        sum += min(left[i],right[i])-arr[i];
    cout << sum;
    
    return 0;
}