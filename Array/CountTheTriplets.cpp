// https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1
// Problem:
// Given an array of distinct integers. The task is to count all the triplets such that sum
// of two elements equals the third element.

// Constraints:
// 1 ≤ N ≤ 103
// 1 ≤ arr[i] ≤ 105

// Example1:
// Input: 
// N = 4 
// arr[] = {1, 5, 3, 2}
// Output: 2 
// Explanation: There are 2 triplets:
//  1 + 2 = 3 and 3 +2 = 5

// Example2:
// Input: 
// N = 3
// arr[] = {2, 3, 4}
// Output: 0
// Explanation: No such triplet exits

// Time Complexity: O(N^2)
// Auxiliary Space: O(1)


#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,count=0;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr + n);
    for(int i = n-1; i>=0; i--){
        int j=0;
        int k=i-1;
        while(j<k){
            if(arr[j]+arr[k]==arr[i]) count++;
            if(arr[j]+arr[k]>arr[i]) k--;
            else j++;
        }
    }
    cout << count;
    return 0;
}