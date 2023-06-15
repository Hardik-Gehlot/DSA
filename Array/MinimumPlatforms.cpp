// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Problem:
// Given arrival and departure times of all trains that reach a railway station. Find the minimum
// number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and
// departure time can never be the same for a train but we can have arrival time of one train equal to
// departure time of the other. At any given instance of time, same platform can not be used for both
// departure of a train and arrival of another train. In such cases, we need different platforms.


// Example 1:
// Input: n = 6 
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation: 
// Minimum 3 platforms are required to 
// safely arrive and depart all trains.

// Example 2:
// Input: n = 3
// arr[] = {0900, 1100, 1235}
// dep[] = {1000, 1200, 1240}
// Output: 1
// Explanation: Only 1 platform is required to 
// safely manage the arrival and departure 
// of all trains. 

// Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent 
// hour (between 00 to 23 ) and the last two characters represent minutes (this may be > 59).


// Expected Time Complexity: O(nLogn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 50000
// 0000 ≤ A[i] ≤ D[i] ≤ 2359

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int dep[n];
    for(int i =0; i<n; i++){
        cin>>dep[i];
    }
    sort(arr+0,arr+n);
        sort(dep+0,dep+n);
        int count=0;
        int j=0;
        int t=dep[0];
        for(int i=0;i<n;i++)
        {
            if(arr[i]>t)
            {
                // free platform available and hence used
                // t updated to time when another platform will be free
                j++;
                t=dep[j];
            }
            else
            {
                // no free platform available so new platform required
                count++;
            }
        }
        cout<< count;
    return 0;
}
