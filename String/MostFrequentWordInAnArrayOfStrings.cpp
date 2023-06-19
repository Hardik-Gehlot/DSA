// https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings3528/1
// Problem:
// Given an array arr containing N words consisting of lowercase characters. Your task is to find the
// most frequent word in the array. If multiple words have same frequency, then print the word whose
// first occurence occurs last in the array as compared to the other strings with same frequency.

// Example 1:
// Input:
// N = 3
// arr[] = {geeks,for,geeks}
// Output: geeks
// Explanation: "geeks" comes 2 times.

// Example 2:
// Input:
// N = 2
// arr[] = {hello,world}
// Output: world
// Explanation: "hello" and "world" both
// have 1 frequency. We print world as
// its first occurence comes last in the
// input array.

// Expected Time Complexity: O(N * WORD_LEN).
// Expected Auxiliary Space: O(N * WORD_LEN).
// Constraints:
// 1 <= N <= 50000
// 1 <= |each string| <= 50
// Sum of length of every string does not exceed 5*105

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int max=0;
    unordered_map<string,int> map;
    string word = "";
    unordered_map<string,int> indexes;
    int idx = 0;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
        if(indexes.count(arr[i])==0){
            indexes[arr[i]]=i+1;
        }
        if(map[arr[i]]>= max){
            max = map[arr[i]];
        }
    }
    for(auto x:indexes){
        if(map[x.first]==max && idx<x.second){
            word=x.first;
            idx=x.second;
        }
    }
    cout << word;
    return 0;
}