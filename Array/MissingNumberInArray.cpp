// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
// Problem:
// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N.
// Find the missing element.

// Example 1:
// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4

// Example 2:
// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9

// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ A[i] ≤ 106

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum = 0;
    int temp;
    for(int i =0; i<n-1; i++){
        cin>>temp;
        sum += temp;
    }
    cout << ((n*(n+1))/2) - sum;
    
    return 0;
}