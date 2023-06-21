// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a
// subset of a1[] or not. Both the arrays can be sorted or unsorted. There can be duplicate elements.
 

// Example 1:
// Input:
// a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
// a2[] = {11, 3, 7, 1, 7}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]


// Example 2:
// Input:
// a1[] = {1, 2, 3, 4, 4, 5, 6}
// a2[] = {1, 2, 4}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]


// Example 3:
// Input:
// a1[] = {10, 5, 2, 23, 19}
// a2[] = {19, 5, 3}
// Output:
// No
// Explanation:
// a2[] is not a subset of a1[]

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n,m <= 105
// 1 <= a1[i], a2[j] <= 106

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m) {
    if(m>n) return "No";
    unordered_map<int,int>map;
    for(int i=0;i<n;i++){
        map[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(map[a2[i]] == 0) return "No";
        map[a2[i]]--;
    }
    return "Yes";
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    int arr2[m];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    for(int i =0; i<m; i++){
        cin>>arr2[i];
    }
    cout<<isSubset(arr, arr2,n,m);
    return 0;
}