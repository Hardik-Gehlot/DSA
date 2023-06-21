// https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1
// Problem:
// Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all
// pairs from both arrays whose sum is equal to X.

// Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and
// (u2,v2), if u1 < u2 then
// (u1,v1) should be printed first else second.

// Example 1:
// Input:
// A[] = {1, 2, 4, 5, 7}
// B[] = {5, 6, 3, 4, 8} 
// X = 9 
// Output: 
// 1 8
// 4 5 
// 5 4
// Explanation:
// (1, 8), (4, 5), (5, 4) are the
// pairs which sum to 9.

// Example 2:
// Input:
// A[] = {-1, -2, 4, -6, 5, 7}
// B[] = {6, 3, 4, 0} 
// X = 8 
// Output:
// 4 4 
// 5 3

// Expected Time Complexity: O(NLog(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N, M ≤ 106
// -106 ≤ X, A[i], B[i] ≤ 106


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<pair<int, int>> allPairs(int A[], int B[], int n, int m, int X)
{
    sort(A, A + n);
    unordered_map<int, int> map;
    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++)
    {
        map[B[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int val;
        if (A[i] > 0)
            val = X - A[i];
        else
            val = X + A[i];
        if (map[val] > 1)
            ans.push_back({A[i], val});
    }
    return ans;
}
int main()
{
    int n, m,x;
    cin >> n >> m>>x;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<pair<int,int> > ans = allPairs(a,b,n,m,x);
    if(ans.size() ==  0) cout<< -1;
    else 
        for(int i = 0; i < ans.size(); i++){
            if(i == 0)
                cout<<ans[i].first<<" "<<ans[i].second;
            else
                cout<<", "<<ans[i].first<<" "<<ans[i].second;
        }
    return 0;
}