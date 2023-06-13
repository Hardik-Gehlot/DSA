// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1
// Problem:
// Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively
// i.e first element should be max value, second should be min value, third should be second max,
// fourth should be second min and so on.
// Note: Modify the original array itself. Do it without using any extra space. You do not have to
// return anything.

// Example 1:

// Input:
// n = 6
// arr[] = {1,2,3,4,5,6}
// Output: 6 1 5 2 4 3
// Explanation: Max element = 6, min = 1, 
// second max = 5, second min = 2, and 
// so on... Modified array is : 6 1 5 2 4 3.

// Example 2:

// Input:
// n = 11
// arr[]={10,20,30,40,50,60,70,80,90,100,110}
// Output:110 10 100 20 90 30 80 40 70 50 60
// Explanation: Max element = 110, min = 10, 
// second max = 100, second min = 20, and 
// so on... Modified array is : 
// 110 10 100 20 90 30 80 40 70 50 60.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= n <= 10^6
// 1 <= arr[i] <= 10^7

// Solution:
// Idea is to use the logic  “Dividend = Divisor × Quotient + Remainder”
// arr[i]= newValue%mx * mx + oldValue;

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int minidx = 0, maxidx = n - 1;
        int mx = arr[n-1]+1;
        for(int i=0;i<n;i++){
            if(i%2==0){//i is even
                arr[i]=((arr[maxidx]%mx)*mx) + arr[i];
                maxidx--;
            }else{ // i is odd
                // arr[i]=(arr[i]+arr[minidx]%mx)*mx;
                arr[i]=((arr[minidx]%mx)*mx) + arr[i];
                minidx++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=arr[i]/mx;
        }
        for(int i =0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}