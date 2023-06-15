// https://practice.geeksforgeeks.org/problems/unsorted-array4925/1
// Problem:
// Given an unsorted array of size N. Find the first element in array such that all of its left elements
// are smaller and all right elements to it are greater than it.
// Note: Left and right side elements can be equal to required element. And extreme elements cannot be
// required element.

 

// Example 1:
// Input:
// N = 4
// A[] = {4, 2, 5, 7}
// Output:
// 5
// Explanation:
// Elements on left of 5 are smaller than 5
// and on right of it are greater than 5.

 

// Example 2:
// Input:
// N = 3
// A[] = {11, 9, 12}
// Output:
// -1

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Constraints:
// 3 <= N <= 106
// 1 <= A[i] <= 106

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int lmax[n],rmin[n];
    lmax[0]=arr[0];
    rmin[n-1]=arr[n-1];

    for(int i=1;i<n;i++)
        lmax[i]=max(lmax[i-1],arr[i]);
    
    for(int i=n-2;i>=0;i--)
        rmin[i]=min(rmin[i+1],arr[i]);
    
    for(int i=1;i<n-1;i++){
        if(arr[i]>=lmax[i] && arr[i]<=rmin[i]){
            cout<< arr[i];
            return 0;
        }
    }
    
    cout<< -1;
    return 0;
}
