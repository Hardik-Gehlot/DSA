// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
// Problem:
// Given an array of integers and a number K. Find the count of distinct elements in every window of
// size K in the array.

// Example 1:
// Input:
// N = 7, K = 4
// A[] = {1,2,1,3,4,2,3}
// Output: 3 4 4 3
// Explanation: Window 1 of size k = 4 is
// 1 2 1 3. Number of distinct elements in
// this window are 3. 
// Window 2 of size k = 4 is 2 1 3 4. Number
// of distinct elements in this window are 4.
// Window 3 of size k = 4 is 1 3 4 2. Number
// of distinct elements in this window are 4.
// Window 4 of size k = 4 is 3 4 2 3. Number
// of distinct elements in this window are 3.

// Example 2:
// Input:
// N = 3, K = 2
// A[] = {4,1,1}
// Output: 2 1

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= K <= N <= 105
// 1 <= A[i] <= 105 , for each valid i

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> countDistinct (int A[], int n, int k){
    unordered_map<int,int>map;
    int i=0;
    int j=0;
    vector<int>ans;
    int count=0;
    while(j<k){
        if(map[A[j]]++ == 0) count++;
        j++;
    }
    ans.push_back(count);
    while(j<n){
        map[A[i]]--;
        if(map[A[i]] == 0){
            count--;
        }
        if(map[A[j]]++ == 0) count++;
        j++;
        i++;
        ans.push_back(count);
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> ans= countDistinct(arr,n,k);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}