// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// *Problem:
// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N}
// is missing and one number 'B' occurs twice in array. Find these two numbers.

// ? Example 1:
// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1.

// ? Example 2:
// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and 
// smallest positive missing number is 2.

// !Expected Time Complexity: O(N)
// !Expected Auxiliary Space: O(1)

// *Constraints:
// 2 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ N


#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        arr[i] = arr[i]-1;
    for(int i=0;i<n;i++){
        arr[arr[i]%n]+=n;
    }
    int missingElement,repeatedElement;
    for(int i=0;i<n;i++){
        if(arr[i]/n == 0) //missing element have no added n
            missingElement=i+1;
        if(arr[i]/n > 1) // repeating element shall have added multiple times n
            repeatedElement=i+1;
    }
    cout<<repeatedElement<<" "<<missingElement;
    return 0;
}