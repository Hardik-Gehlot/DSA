// https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
// Problem:
// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 10^9 + 7.

// Example 1:
// Input:
// N = 3
// Output: 5
// Explanation: 5 strings are (000,
// 001, 010, 100, 101).

// Example 2:
// Input:
// N = 2
// Output: 3
// Explanation: 3 strings are
// (00,01,10).

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int zeroend=1;
    int oneend=1;
    int  sum=zeroend+oneend;
    if(n==1)
    return sum;
    
     int i=2;
    while(i<=n)
    {
        oneend=zeroend%1000000007;
        zeroend=sum%1000000007;
        sum=zeroend+oneend%1000000007;
        i++;
    }
    cout<< sum%(1000000007);
    return 0;
}