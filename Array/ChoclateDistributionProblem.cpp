// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Problem:
// Given an array A[ ] of positive integers of size N, where each value represents the number of
// chocolates in a packet. Each packet can have a variable number of chocolates. There are M students,
// the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of
// chocolates given to a student is minimum.

// Example 1:
// Input:
// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between 
// maximum chocolates and minimum chocolates 
// is 9 - 3 = 6 by choosing following M packets :
// {3, 4, 9, 7, 9}.

// Example 2:
// Input:
// N = 7, M = 3
// A = {7, 3, 2, 4, 9, 12, 56}
// Output: 2
// Explanation: The minimum difference between
// maximum chocolates and minimum chocolates
// is 4 - 2 = 2 by choosing following M packets :
// {3, 2, 4}.

// Expected Time Complexity: O(N*Log(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ N ≤ 105
// 1 ≤ Ai ≤ 109
// 1 ≤ M ≤ N


#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin >> n;
    vector<int> arr;
    int a;
    for(int i =0; i<n; i++){
        cin>>a;
        arr.push_back(a);
    }
    cin>>m;
    sort(arr.begin(), arr.end());
    int start = 0, end = m - 1;
    int ans = arr[end] - arr[start];
    int temp;
    while (end < n)
    {
        temp = arr[end++] - arr[start++];
        ans = min(ans, temp);
    }
    cout<< ans;
    return 0;
}