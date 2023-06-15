// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
// Problem:
// The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on
// which you buy and sell the stock so that in between those days for which profit can be generated.
// Note: Since there can be multiple solutions, the driver code will print 1 if your answer is correct,
// otherwise, it will return 0. In case there's no profit the driver code will print the string
// "No Profit" for a correct solution.

// Example 1:
// Input:
// N = 7
// A[] = {100,180,260,310,40,535,695}
// Output:
// 1
// Explanation:
// One possible solution is (0 3) (4 6)
// We can buy stock on day 0,
// and sell it on 3rd day, which will 
// give us maximum profit. Now, we buy 
// stock on day 4 and sell it on day 6.

// Example 2:
// Input:
// N = 5
// A[] = {4,2,2,2,4}
// Output:
// 1
// Explanation:
// There are multiple possible solutions.
// one of them is (3 4)
// We can buy stock on day 3,
// and sell it on 4th day, which will 
// give us maximum profit.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 2 ≤ N ≤ 106
// 0 ≤ A[i] ≤ 106

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int buyDay = 0,sellDay = 0,i,j,cost=0,profit=0;
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        cost = arr[i]-arr[buyDay];
        if(cost>profit){
            sellDay = i;
            profit = cost;
        }
        if(profit>=cost || i==n-1){
            if(profit!=0){
                ans.push_back({buyDay,sellDay});
            }
            buyDay = i;
            profit=0;
        }
    }
    if(ans.size()>0){
        cout<<1;
    }else cout<<0;
    return 0;
}