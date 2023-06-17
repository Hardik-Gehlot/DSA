// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1
// Problem:
// Given an array arr[] of size N. The task is to find the first repeating element in the array of
// integers, i.e., an element that occurs more than once and whose index of first occurrence is
// smallest.
// Constraints:
// 1 <= N <= 106
// O <= Ai <= 106


// Example:
// Input:
// 7
// 1 5 3 4 3 5 6
// Output:
// 2
// Explanation:
// 5 is appearing twice and its first appearance is at index 2 which is less than 3 whose first
// occurring index is 3.


#include<iostream>
using namespace std;
int main(){
    int n;
    const int N = 1e6+2; // it means N= 10^6+2
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int idx[N];
    for(int i = 0; i < n; i++) idx[i] = -1;
    int minidx = 1e6+2;
    for(int i = 0; i < n; i++){
        if(idx[a[i]]!=-1){
            minidx = min(minidx,idx[a[i]]);
        }else{
            idx[a[i]] = i;
        }
    }
    if(minidx!=1e6+2) cout<<minidx+1<<endl;
    else cout<<-1<<endl;
    return 0;
}