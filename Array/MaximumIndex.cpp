// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1
// Problem:
// Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to
// the constraint of A[i] < A[j] and i < j.
 

// Example 1:
// Input:
// N = 2
// A[] = {1, 10}
// Output:
// 1
// Explanation:
// A[0]<A[1] so (j-i) is 1-0 = 1.

// Example 2:
// Input:
// N = 9
// A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array A[1] < A[7]
// satisfying the required 
// condition(A[i] < A[j]) thus giving 
// the maximum difference of j - i 
// which is 6(7-1).

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ A[i] ≤ 109

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int leftMin[n];
    int rightMax[n];
    leftMin[0]=arr[0];
    rightMax[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
        leftMin[i]=min(leftMin[i-1],arr[i]);
    for(int i=n-2;i>=0;i--)
        rightMax[i]=max(rightMax[i+1],arr[i]);
    int i=0,j=0,maxdiff=0;
    while(i<n && j<n){
        if(leftMin[i]<=rightMax[j]){
            maxdiff=max(maxdiff,j-i);
            j++;
        }else i++;
    }
    cout<<maxdiff;
    return 0;
}