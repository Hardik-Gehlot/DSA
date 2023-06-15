// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Problem:
// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find
// the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

// Example 1:
// Input:
// N = 6
// arr[] = 7 10 4 3 20 15
// K = 3
// Output : 7
// Explanation :
// 3rd smallest element in the given
// array is 7.

// Example 2:
// Input:
// N = 5
// arr[] = 7 10 4 20 15
// K = 4
// Output : 15
// Explanation :
// 4th smallest element in the given
// array is 15.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(log(n))

// Constraints:
// 1 <= N <= 105
// 1 <= arr[i] <= 105
// 1 <= K <= N

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin>>k;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.size() < k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    cout<<pq.top();
    return 0;
}