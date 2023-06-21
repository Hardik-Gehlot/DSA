// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Given an array having both positive and negative integers. The task is to compute the length of the
// largest subarray with sum 0.

// Example 1:
// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.

// Your Task:
// You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// -1000 <= A[i] <= 1000, for each valid i

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxLen(vector<int>&A, int n){   
    int sum = 0;
    unordered_map<int,int> mp;
    int len = 0;
    mp[0] = -1;
    for(int i=0; i<n; i++){
        sum+=A[i];
        if(mp.find(sum) != mp.end()){
            len = max(len, i-mp[sum]);
        }
        else
            mp[sum] = i;
    }
    return len;
}
int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    cout << maxLen(A,n) << endl;
    return 0;
}