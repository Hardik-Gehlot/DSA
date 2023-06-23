// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// Given an input stream A of n characters consisting only of lower case alphabets. While reading
// characters from the stream, you have to tell which character has appeared only once in the stream
// upto that point. If there are many characters that have appeared only once, you have to tell which
// one of them was the first one to appear. If there is no such character then append '#' to the answer.

// Example 1:

// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'

// Example 2:

// Input: A = "zz"
// Output: "z#"
// Explanation: For every character first non
// repeating character is as follow-
// "z" - first non-repeating character is 'z'
// "zz" - no non-repeating character so '#'

// Expected Time Complexity: O(26 * n)
// Expected Space Complexity: O(26)

// Constraints:
// 1 <= n <= 105

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        count[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << FirstNonRepeating(s);
    return 0;
}