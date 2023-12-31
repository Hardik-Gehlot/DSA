// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous
// subarray of size K.

// Example 1:

// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output:
// 3 3 4 5 5 5 6
// Explanation:
// 1st contiguous subarray = {1 2 3} Max = 3
// 2nd contiguous subarray = {2 3 1} Max = 3
// 3rd contiguous subarray = {3 1 4} Max = 4
// 4th contiguous subarray = {1 4 5} Max = 5
// 5th contiguous subarray = {4 5 2} Max = 5
// 6th contiguous subarray = {5 2 3} Max = 5
// 7th contiguous subarray = {2 3 6} Max = 6

// Example 2:

// Input:
// N = 10, K = 4
// arr[] = 8 5 10 7 9 4 15 12 90 13
// Output:
// 10 10 10 15 15 90 90
// Explanation:
// 1st contiguous subarray = {8 5 10 7}, Max = 10
// 2nd contiguous subarray = {5 10 7 9}, Max = 10
// 3rd contiguous subarray = {10 7 9 4}, Max = 10
// 4th contiguous subarray = {7 9 4 15}, Max = 15
// 5th contiguous subarray = {9 4 15 12},
// Max = 15
// 6th contiguous subarray = {4 15 12 90},
// Max = 90
// 7th contiguous subarray = {15 12 90 13},
// Max = 90

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(k)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ K ≤ N
// 0 ≤ arr[i] ≤ 107

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector <int> max_of_subarrays(int *a, int n, int k)
{
    vector<int>v;
    int maxi=-1e5;
    for(int i=0;i<k;i++){
      maxi=max(maxi,a[i]);
    }
    v.push_back(maxi);
    int l=0;
  for(int i=k;i<n;i++){
      if(a[l]==maxi){
          maxi=a[i];
          for(int j=l+1;j<l+k;j++){
              maxi=max(maxi,a[j]);
          }
          v.push_back(maxi);
      }
      else{
          maxi=max(maxi,a[i]);
          v.push_back(maxi);
      }
      l++;
  }
  return v;
}
// vector<int> max_of_subarrays(int *arr, int n, int k)
// {
//     vector<int> ans;
//     deque<int> dq;
//     for (int i = 0; i < n; i++)
//     {
//         if (!dq.empty() && dq.front() == i - k)
//             dq.pop_front();
//         while (!dq.empty() && arr[dq.back()] <= arr[i])
//             dq.pop_back();
//         dq.push_back(i);
//         if (i >= k - 1)
//             ans.push_back(arr[dq.front()]);
//     }
//     return ans;
// }
int main()
{
    int n,k;
    cin >> n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = max_of_subarrays(arr,n,k);
    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;
}