// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// You are given N elements and your task is to Implement a Stack in which you can get a minimum
// element in O(1) time.

// Example 1:

// Input:
// push(2)
// push(3)
// pop()
// getMin()
// push(1)
// getMin()
// Output: 2 1
// Explanation: In the first test case for
// query 
// push(2)  Insert 2 into the stack.
//          The stack will be {2}
// push(3)  Insert 3 into the stack.
//          The stack will be {2 3}
// pop()    Remove top element from stack 
//          Poped element will be 3 the
//          stack will be {2}
// getMin() Return the minimum element
//          min element will be 2 
// push(1)  Insert 1 into the stack.
//          The stack will be {2 1}
// getMin() Return the minimum element
//          min element will be 1

// Expected Time Complexity: O(1) for all the 3 methods.
// Expected Auxiliary Space: O(1) for all the 3 methods.

// Constraints:
// 1 <= Number of queries <= 100
// 1 <= values of the stack <= 100



class Solution
{
    int minEle;
    stack<int> s;

public:
    /*returns min element from stack*/
    int getMin()
    {
        if (s.empty())
            return -1;
        return s.top();
    }
    /*returns poped element from stack*/
    int pop()
    {
        if (s.empty())
            return -1;
        s.pop();
        int x = s.top();
        s.pop();
        return x;
    }
    /*push element x into the stack*/
    void push(int x)
    {
        if (s.empty())
        {
            s.push(x);
            s.push(x);
        }
        else
        {
            int minn = s.top();
            s.push(x);
            if (x < minn)
                s.push(x);
            else
                s.push(minn);
        }
    }
};