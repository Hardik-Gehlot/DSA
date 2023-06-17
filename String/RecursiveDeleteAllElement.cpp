// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1
// Problem:
// Given a string s, remove all its adjacent duplicate characters recursively. 

// Note: For some test cases, the resultant string would be an empty string. In that case, the function
// should return the empty string only.

// Example 1:
// Input:
// S = "geeksforgeek"
// Output: "gksforgk"
// Explanation: 
// g(ee)ksforg(ee)k -> gksforgk


// Example 2:
// Input: 
// S = "abccbccba"
// Output: ""
// Explanation: 
// ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(|S|)


// Constraints:
// 1<=|S|<=105

#include<iostream>
#include<string>
#include<stack>
using namespace std;
string rremove(string s){
    bool duplicate = 0;                     
    string ansString = "";                
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[i+1]){               
            duplicate = 1;                
            int end = i;
            while(s[i] == s[end]){
                end++;
            }
            i = end-1;
        }else{                            
            ansString += s[i];
        }
    }
    if(duplicate){                        
      return rremove(ansString);         
    }
    return s;
    }
int main(){
    string s;
    cin>>s;
    string ans = rremove(s);
    cout << ans;
    return 0;
}