// https://leetcode.com/problems/next-greater-element-i/
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.


// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

// Constraints:
//     1 <= nums1.length <= nums2.length <= 1000
//     0 <= nums1[i], nums2[i] <= 104
//     All integers in nums1 and nums2 are unique.
//     All the integers of nums1 also appear in nums2.



#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int>s;
    vector<int>ans;
    unordered_map<int,int> u;
    int j = size(nums2) - 1;
    while (j >= 0)
    {
        while (!s.empty() && s.top() < nums2[j])
            s.pop();
        if (s.empty())
            u[nums2[j]] = -1;
        else
            u[nums2[j]] = s.top();
        s.push(nums2[j]);
        j--;
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(u[nums1[i]]);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i=0; i<n; i++){
        cin>>nums1[i];
    }
    for(int i=0; i<m; i++){
        cin>>nums2[i];
    }
    vector<int> ans = nextGreaterElement(nums1,nums2);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}