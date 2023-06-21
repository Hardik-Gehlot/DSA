// https://practice.geeksforgeeks.org/problems/common-elements5420/1
// Problem:
// Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both
// the lists and return the list in sorted order. Duplicates may be there in the output list.

// Example:
// Input:
// n = 5
// v1[] = {3, 4, 2, 2, 4}
// m = 4
// v2[] = {3, 2, 2, 7}
// Output:
// 2 2 3
// Explanation:
// The common elements in sorted order are {2 2 3}

// Constraints:
// 1 ≤ n, m ≤ 105
// 1 ≤ Vi ≤ 105

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> common_element(vector<int>v1,vector<int>v2){
    vector<int>ans;
    unordered_map<int,int>map;
    for(int x:v1){
        map[x]++;
    }
    for(int x:v2){
        if(map[x]){
            ans.push_back(x);
            map[x]--;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n,m;
    cin>>n;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    cin>>m;
    vector<int> v2(m);
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }
    vector<int> ans = common_element(v1,v2);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}