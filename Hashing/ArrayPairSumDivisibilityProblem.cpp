// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
// Problem:
// Given an array of integers and a number k, write a function that returns true if given array can be
// divided into pairs such that sum of every pair is divisible by k.
 
// Example 1 :
// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.

// Example 2:
// Input : arr = [2, 4, 1, 3], k = 4
// Output: False
// Explanation: There is no possible solution.

// Expected Time Complexity: O(n)
// Expected Space Complexity : O(n)
 
// Constraints:
// 1 <= length of array <= 10^5
// 1 <= elements of array <= 10^5
// 1 <= k <= 10^5

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool canPair(vector<int> nums, int k) {
    int hash[k + 1] = {0};
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] % k;
        hash[nums[i]] += 1;
    }
    hash[0] = 0;
    for (int i = 1; i <= (k+1) / 2; i++) {
        if(k%2==0){
            if(k/2==i){
                if(hash[i]%2!=0){
                    return false;
                }
                hash[i]=0;
                
            }else{
                if(hash[i]!=hash[k-i]){
                    return false;
                }
                hash[i]=0;
                hash[k-i]=0;
            }
        }else{
            if(hash[i]==hash[k-i]){
                hash[i]=0;
                hash[k-i]=0;
            }else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<canPair(v);
    return 0;
}
