// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Problem:
// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
// which has the maximum sum and return its sum.

// Example 1:
// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.

// Example 2:
// Input:
// N = 4
// Arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

// Constraints:
// 1 ≤ N ≤ 10^6
// -10^7 ≤ A[i] ≤ 10^7

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int tempSum =0;
    int sum = arr[0];
    for(int i =0; i<n; i++){
        tempSum += arr[i];
        if(sum < tempSum) sum = tempSum;
        if(tempSum < 0) tempSum = 0;
    }
    cout<<sum;
    return 0;
}