// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Problem:
// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from
// being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in
// the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).

// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already 
// sorted so there is no inversion count.

// Example 3:

// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array 
// are same, so there is no inversion count.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 5*105
// 1 ≤ arr[i] ≤ 1018

#include<iostream>
using namespace std;
int ans = 0;
void merge(int arr[],int low,int mid, int high){
    int a[high-low+1];
    int i=low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            ans += mid-i+1;
            a[k++]=arr[j++];
        }else{
            a[k++]=arr[i++];
        }
    }
    while(i<=mid){
        a[k++] = arr[i++];
    }
    while(j<=high){
        a[k++] = arr[j++];
    }
    int mainidx = low;
    k = high-low+1;
    for(int i = 0;i<k;i++){
        arr[mainidx++]=a[i];
    }
}
void mergeSort(int arr[],int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout << ans;
    return 0;
}
