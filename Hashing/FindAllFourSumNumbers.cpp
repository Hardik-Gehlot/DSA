// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
// Problem:
// Given an array of integers and another number. Find all the unique quadruple from the given array
// that sums up to the given number.

// Example 1:
// Input:
// N = 5, K = 3
// A[] = {0,0,2,1,1}
// Output: 0 0 1 2 
// Explanation: Sum of 0, 0, 1, 2 is equal
// to K.

// Example 2:
// Input:
// N = 7, K = 23
// A[] = {10,2,3,4,5,7,8}
// Output: 2 3 8 10 
//         2 4 7 10 
//         3 5 7 8 
// Explanation: Sum of 2, 3, 8, 10 = 23,
// sum of 2, 4, 7, 10 = 23 and sum of 3,
// 5, 7, 8 = 23.

// Expected Time Complexity: O(N3).
// Expected Auxiliary Space: O(N2).

// Constraints:
// 1 <= N <= 100
// -1000 <= K <= 1000
// -100 <= A[] <= 100

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    set<vector<int>>temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int start=j+1,end=n-1;
            while(start<end){
                if(arr[i]+arr[j]+arr[start]+arr[end]==k){
                    vector<int>quadruple={arr[i],arr[j],arr[start],arr[end]};
                    temp.insert(quadruple);
                    start++;
                    end--;
                }
                else if(arr[i]+arr[j]+arr[start]+arr[end]<k){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
    }
    
    for(auto it : temp){
        ans.push_back(it);
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<int>> ans = fourSum(v,k);
    for(auto v:ans){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}