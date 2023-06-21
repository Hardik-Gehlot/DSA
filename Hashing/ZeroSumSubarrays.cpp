// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
// Problem:
// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

// Example 1:
// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are
// [0], [0], [0], [0], [0,0], and [0,0].

// Example 2:
// Input:
// n = 10
// arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
// Output: 4
// Explanation: The 4 subarrays are [-1 -3 4]
// [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

// Expected Time Complexity: O(n*log(n))
// Expected Auxilliary Space: O(n)

// Constraints:
// 1 <= n <= 10^6
// -10^9 <= arr[ i ] <= 10^9

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n)
{
    unordered_map<long long int, int> map;
    long long int ans = 0;
    long long int prefix[n + 1];
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    for (int i = 0; i <= n; i++)
    {
        map[prefix[i]]++;
    }
    for (auto it : map)
    {
        int val = it.second;
        ans += (val * (val - 1)) / 2;   // nCr since r=2 therefore ncr is n*(n-1) / 2
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << findSubarray(v,n);
    return 0;
}