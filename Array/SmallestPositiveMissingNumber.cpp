// Problem:
// You are given an array arr[] of N integers including 0. The task is to find the smallest
// positive number missing from the array.
// Constraints:
// 1 <= N <= 10^6
// -10^6 <= Ai <= 10^6
// Example:
// Input:
// N = 5
// A[] = {-1,0,1,3,-4}
// Output: 2
// Explanation: The smallest positive number that is missing is 2;.
#include<iostream>
using namespace std;
int main(){
    int n,temp;
    cin>>n;
    int N = 1e6+2;
    bool check[N];
    for(int i =0; i<n; i++){
        cin>>temp;
        if(temp>=0) check[temp]=true;
    }
    for (int i = 0; i < N; i++){
        if(check[i]==false){
            cout<<i;
            break;
        }
    }
    
    return 0;
}