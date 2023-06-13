// Problem:
// Given an unsorted array A of size N of non-negative integers, find a continuous subarray
// which adds to a given number S.
// Constraints:
// 1 <= N <= 105
// 0 <= Ai <= 1010

// Example:
// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4
// Explanation: The sum of elements from 2nd position to 4th position is 12.

#include <iostream>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = arr[0];
    int ptr1 = 0, ptr2 = 0;
    long long sum = arr[0];
    if (sum == s){
        cout<<"1 1";
        return 0;
    }
    while (ptr2 < n - 1)
    {
        if (sum + arr[ptr2 + 1] <= s)
        {
            sum += arr[ptr2 + 1];
            ptr2++;
        }
        else
        {
            sum -= arr[ptr1];
            ptr1++;
        }
        if (sum == s)
            cout<< ptr1 + 1 << ptr2 + 1;
    }
    return -1;
}