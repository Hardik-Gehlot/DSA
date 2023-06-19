// https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener2031/1
// Problem:
// Design a system that takes big URLs like “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/”
// and converts them into a short URL. It is given that URLs are stored in database and every URL has an
// associated integer id.  So your program should take an integer id and generate a URL. 
// A URL character can be one of the following
//     A lower case alphabet [‘a’ to ‘z’], total 26 characters
//     An upper case alphabet [‘A’ to ‘Z’], total 26 characters
//     A digit [‘0′ to ‘9’], total 10 characters
// There are total 26 + 26 + 10 = 62 possible characters.
// So the task is to convert an integer (database id) to a base 62 number where digits of 62 base are
// "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

// Example 1:
// Input: 
// N = 12345
// Output: 
// dnh
// 12345
// Explanation: "dnh" is the url for id 12345

// Example 2:
// Input: 
// N = 30540
// Output: 
// h6K
// 30540
// Explanation: "h6K" is the url for id 30540

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 1018

#include<iostream>
#include<string>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    string ans="";
	string map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char ch;
	while(n){
	    ch = map[n%62];
	    n /= 62;
	    ans = ch+ans;
	}
	cout << ans;
    return 0;
}