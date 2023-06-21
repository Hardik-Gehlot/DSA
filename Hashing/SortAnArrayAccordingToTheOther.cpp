// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1
// Problem:
// Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ]
// such that all the relative positions of the elements in the first array are the same as the
// elements in the second array A2[ ].
// See example for better understanding.
// Note: If elements are repeated in the second array, consider their first occurance only.

// Example 1:
// Input:
// N = 11 
// M = 4
// A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
// A2[] = {2, 1, 8, 3}
// Output: 
// 2 2 1 1 8 8 3 5 6 7 9
// Explanation: Array elements of A1[] are
// sorted according to A2[]. So 2 comes first
// then 1 comes, then comes 8, then finally 3
// comes, now we append remaining elements in
// sorted order.

// Example 2:
// Input:
// N = 11 
// M = 4
// A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
// A2[] = {99, 22, 444, 56}
// Output: 
// 1 1 2 2 3 5 6 7 8 8 9
// Explanation: No A1[] elements are in A2[]
// so we cannot sort A1[] according to A2[].
// Hence we sort the elements in non-decreasing 
// order.

// Expected Time Complexity: O(N * Log(N)).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N, M ≤ 106
// 1 ≤ A1[i], A2[i] ≤ 106

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
    vector<int>ans;
    unordered_map<int,int>map;
    sort(A1.begin(),A1.end());
    for(int x:A1){
        map[x]++;
    }
    for(int x:A2){
        while(map[x]-- > 0){
            ans.push_back(x);
        }
    }
    for(int x:A1){
        if(map[x]>0){
            ans.push_back(x);
        }   
    }
    return ans;
} 
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1;
    vector<int>arr2;
    int x;
    for(int i =0; i<n; i++){
        cin>>x;
        arr1.push_back(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        arr2.push_back(x);
    }
    vector<int> ans = sortA1ByA2(arr1,n,arr2,m);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}