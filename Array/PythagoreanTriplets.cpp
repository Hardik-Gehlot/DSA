// https://practice.geeksforgeeks.org/problems/pythagorean-triplet3018/1
// Problem:
// Given an array arr of N integers, write a function that returns true if there is a 
// triplet (a, b, c) that satisfies a2 + b2 = c2, otherwise false.

// Example 1:
// Input:
// N = 5
// Arr[] = {3, 2, 4, 6, 5}
// Output: Yes
// Explanation: a=3, b=4, and c=5 forms a
// pythagorean triplet.

// Example 2:
// Input:
// N = 3
// Arr[] = {3, 8, 5}
// Output: No
// Explanation: No such triplet possible.

// Expected Time Complexity: O(max(Arr[i])2)
// Expected Auxiliary Space: O(max(Arr[i]))

// Constraints:
// 1 <= N <= 107
// 1 <= Arr[i] <= 1000


#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; i--)
    {
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            if (pow(arr[j], 2) + pow(arr[k], 2) == pow(arr[i], 2)){
                cout << "Yes";
                return 0;
            }
            else if (pow(arr[j], 2) + pow(arr[k], 2) > pow(arr[i], 2))
                k--;
            else
                j++;
        }
    }
    cout<< "No";
    return 0;
}