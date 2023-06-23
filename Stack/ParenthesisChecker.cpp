// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in
// exp. For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

// Example 1:

// Input:
// {([])}
// Output:
// true
// Explanation:
// { ( [ ] ) }. Same colored brackets can form
// balanced pairs, with 0 number of
// unbalanced bracket.

// Example 2:

// Input:
// ()
// Output:
// true
// Explanation:
// (). Same bracket can form balanced pairs,
// and here only 1 type of bracket is
// present and in balanced way.

// Example 3:

// Input:
// ([]
// Output:
// false
// Explanation:
// ([]. Here square bracket is balanced but
// the small bracket is not balanced and
// Hence , the output will be unbalanced.

// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

// Constraints:
// 1 ≤ |x| ≤ 32000

#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool ispar(string x)
{
    stack<char> stk;
    stk.push(x[0]);
    if (x[0] == '}' || x[0] == ')' || x[0] == ']')
        return false;
    for (int i = 1; i < x.size(); i++)
    {
        char ch = x[i];
        if (ch == '{' || ch == '[' || ch == '(')
            stk.push(ch);
        else
        {
            if (stk.empty())
                return false;
            char open = stk.top();
            if (ch == '}' && open != '{')
                return false;
            else if (ch == ')' && open != '(')
                return false;
            else if (ch == ']' && open != '[')
                return false;
            stk.pop();
        }
    }
    if (stk.empty())
        return true;
    return false;
}
int main()
{
    string s;
    cin >> s;
    cout << ispar(s);
    return 0;
}