// https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1
// Problem:
// Given two arrays of integers A[] and B[] of size N and M, the task is to check if a pair of
// values (one value from each array) exists such that swapping the elements of the pair will make the
// sum of two arrays equal.

// Example 1:
// Input: N = 6, M = 4
// A[] = {4, 1, 2, 1, 1, 2}
// B[] = (3, 6, 3, 3)
// Output: 1
// Explanation: Sum of elements in A[] = 11
// Sum of elements in B[] = 15, To get same 
// sum from both arrays, we can swap following 
// values: 1 from A[] and 3 from B[]

// Example 2:
// Input: N = 4, M = 4
// A[] = {5, 7, 4, 6}
// B[] = {1, 2, 3, 8}
// Output: 1
// Explanation: We can swap 6 from array 
// A[] and 2 from array B[]

// Expected Time Complexity: O(MlogM+NlogN).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N, M ≤ 106

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int findSwapValues(int A[], int n, int B[], int m){
    int sumA = 0, sumB = 0;
    for(int i=0; i<n; i++) sumA += A[i];
    for(int i=0; i<m; i++) sumB += B[i];
    
    if(sumA==sumB) return 1;
    if((sumA+sumB)%2!=0) return -1;
    
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++) mp[A[i]]++;
    
    int reference = (sumB-sumA)/2;
    
    for(int i=0; i<m; i++)
    {
        if(mp[B[i] - reference]>0) return 1;
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int arr2[m];
    for(int i =0; i<m; i++){
        cin>>arr2[i];
    }
    cout<<findSwapValues(arr,n,arr2,m);
    return 0;
}