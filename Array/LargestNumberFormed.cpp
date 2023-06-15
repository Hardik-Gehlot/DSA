// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
// Problem:
// Given a list of non negative integers, arrange them in such a manner that they form the largest
// number possible.The result is going to be very large, hence return the result in the form of a string.

// Example 1:
// Input: 
// N = 5
// Arr[] = {3, 30, 34, 5, 9}
// Output: 9534330
// Explanation: Given numbers are {3, 30, 34,
// 5, 9}, the arrangement 9534330 gives the
// largest value.

// Example 2:
// Input: 
// N = 4
// Arr[] = {54, 546, 548, 60}
// Output: 6054854654
// Explanation: Given numbers are {54, 546,
// 548, 60}, the arrangement 6054854654 
// gives the largest value.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105
// 0 ≤ Arr[i] ≤ 1018

#include<iostream>
#include<algorithm>
using namespace std;
bool camp(string a,string b){
	return a+b>b+a;
}
int main(){
    int n;
    cin>>n;
    vector<string> arr;
    string x;
    for(int i =0; i<n; i++){
        cin>>x;
        arr.push_back(x);
    }
    string ans;
	sort(arr.begin(),arr.end(),camp);
	for(auto x:arr) ans += x;
	cout << ans;
    return 0;
}