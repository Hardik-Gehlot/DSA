// https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1
// Problem:
// Given an integer array of N elements. You need to find the maximum sum of two elements such that
// sum is closest to zero.

// Example 1:
// Input:
// N = 3
// arr[] = {-8 -66 -60}
// Output: -68
// Explanation: Sum of two elements closest to 
// zero is -68 using numbers -60 and -8.

// Example 2:
// Input: 
// N = 6
// arr[] = {-21 -67 -37 -18 4 -65}
// Output: -14
// Explanation: Sum of two elements closest to
// zero is -14 using numbers -18 and 4.

// Note : In Case if we have two of more ways to form sum of two elements closest to zero return the maximum sum.

// Expected Time Complexity: O(N*logN).
// Expected Auxiliary Space: O(1).

// Constraints:
// 2 ≤ N ≤ 5 * 105
// -106 ≤ arr[i] ≤ 106

#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int left=0,right=n-1;
    int sum,prev=arr[left]+arr[right];
    while(left<right){
        sum = arr[left]+arr[right];
        if(abs(sum)<abs(prev)) prev = sum;
        else if(abs(prev)==abs(sum)) prev = max(prev,sum);
        if(sum<0) left++;
        else right--;
    }
    cout<< prev;
    return 0;
}