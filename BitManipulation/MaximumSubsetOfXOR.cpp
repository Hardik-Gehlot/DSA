// https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1
// Problem:
// Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR subset value in the given array arr[].

// Example 1:

// Input :
// N = 3
// arr[] = {2, 4, 5}
// Output : 7
// Explanation :
// The subset {2, 5} has maximum
// subset XOR value.

// Example 2 :

// Input :
// N= 3
// arr[] = {9, 8, 5}
// Output : 13
// Explanation :
// The subset {8, 5} has maximum
// subset XOR value.

// Expected Time Complexity : O(N*Log(max(arr[i])))
// Expected Auxiliary Space : O(1)

// Contraints :
// 1 <= N <= 105
// 1 <= arr[i] <= 106

#include <iostream>
#include<algorithm>
using namespace std;
int maxSubsetXOR(int arr[], int N)
{
    int ans = 0;
    while(true)
    {
        int max_ele = *max_element(arr, arr + N);
        if(max_ele==0)
        {
            return ans;
        }
        ans = max(ans, ans ^ max_ele);
        for (int i = 0; i < N;i++)
        {
            arr[i]=min(arr[i],arr[i]^max_ele);
        }

    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxSubsetXOR(arr,n);
    return 0;
}