// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Problem:
// Given an array A of positive integers. Your task is to find the leaders in the array. An element of 
// array is leader if it is greater than or equal to all the elements to its right side. The rightmost 
// element is always a leader. 

// Example 1:
// Input:
// n = 6
// A[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: The first leader is 17 
// as it is greater than all the elements
// to its right.  Similarly, the next 
// leader is 5. The right most element 
// is always a leader so it is also 
// included.

// Example 2:
// Input:
// n = 5
// A[] = {1,2,3,4,0}
// Output: 4 0


// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

 
// Constraints:
// 1 <= n <= 107
// 0 <= Ai <= 107

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> res;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int max = arr[n-1];
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=max){
            res.push_back(arr[i]);
            max=arr[i];
        }
    }
    reverse(res.begin(), res.end());
    for (auto x : res)
        cout << x << " ";
    return 0;
}