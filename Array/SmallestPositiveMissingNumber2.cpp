// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
// Problem:
// You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

// Example 1:
// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing 
// number is 6.

// Example 2:
// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing 
// number is 2.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// -106 <= arr[i] <= 106

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
      {
          int element = arr[i];
          if(element>=1&&element<=n)
          {
              int chair = element-1;
              if(arr[chair]!=element)
              {
                  int temp  = arr[chair];
                  arr[chair] = arr[i];
                  arr[i]= temp;
                  i--;
              }
          }
      }
       
      for(int i=0;i<n;i++)
      {
          if((i+1)!=arr[i]){
            cout<< i+1;
            return 0;
          }
           
      }
       
      cout<< n+1;
    return 0;
}