// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Example 1:

// Input:
// N = 4
// Petrol = 4 6 7 4
// Distance = 6 5 3 5
// Output: 1
// Explanation: There are 4 petrol pumps with
// amount of petrol and distance to next
// petrol pump value pairs as {4, 6}, {6, 5},
// {7, 3} and {4, 5}. The first point from
// where truck can make a circular tour is
// 2nd petrol pump. Output in this case is 1
// (index of 2nd petrol pump).

// Expected Time Complexity: O(N)
// Expected Auxiliary Space : O(1)

// Constraints:
// 2 ≤ N ≤ 10000
// 1 ≤ petrol, distance ≤ 1000

#include <iostream>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int fuel = 0;
        int negfuel = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            fuel += p[i].petrol - p[i].distance;
            if (fuel < 0)
            {
                start = i + 1;
                negfuel += fuel;
                fuel = 0;
            }
        }
        if (fuel + negfuel >= 0)
            return start;

        else
            return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].petrol >> p[i].distance;
    Solution obj;
    cout << obj.tour(p, n) << endl;
    return 0;
}