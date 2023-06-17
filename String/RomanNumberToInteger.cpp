// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
// Problem:
// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols
// and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:
// Input:
// s = V
// Output: 5

// Example 2:
// Input:
// s = III 
// Output: 3

// Expected Time Complexity: O(|S|), |S| = length of string S.
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=roman no range<=3999

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int sum = 0;
    int number = 0;
    int prev=0;
    for(int i=n-1;i>=0;i--){
        switch(s[i]){
            case 'M':
                number=1000;
                break;
            case 'D':
                number=500;
                break;
            case 'C':
                number=100;
                break;
            case 'L':
                number=50;
                break;
            case 'X':
                number=10;
                break;
            case 'V':
                number=5;
                break;
            case 'I':
                number=1;
                break;
        }
        if(number<prev) sum -= number;
        else sum+=number;
        prev = number;
    }
    cout<< sum;
    return 0;
}