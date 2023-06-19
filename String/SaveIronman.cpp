// https://practice.geeksforgeeks.org/problems/save-ironman0227/1
// Problem:
// Jarvis is weak in computing palindromes for Alphanumeric characters.
// While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck in
// computing palindromes. You are given a string S containing alphanumeric characters. Find out whether
// the string is a palindrome or not. If you are unable to solve it then it may result in the death of
// Iron Man.

// Example 1:
// Input : S = "I am :IronnorI Ma, i"
// Output : YES
// Explanation:
// Ignore all the symbol and whitespaces S = "IamIronnorIMai".
// Now, Check for pallandrome ignoring uppercase and lowercase
// english letter.


// Example 2:
// Input : S = Ab?/Ba 
// Output :  YES 

// Expected Time Complexity: O(N). where N is the length of the string
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 100000
// Note: Consider alphabets and numbers only for palindrome check. Ignore symbols and whitespaces.

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool saveIronman(string ch)
{
    // Time Limit Exceed
    // string s;
    // for(char c:ch){
    //     if(isalnum(c)!=0)
    //         s = s + c;
    // }
    // int i=0,j=s.size()-1;
    // while(i<j){
    //     if(tolower(s[i])!=tolower(s[j])) return false;
    //     i++;j--;
    // }
    // return true;
    
    
    //Approach 2:
    int idx=0, n=ch.length();
    for(int i=0;i<n;i++){
        char c=ch[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            ch[idx++]=ch[i];
        }
    }
    ch.erase(ch.begin()+idx, ch.end());
    transform(ch.begin(), ch.end(), ch.begin(), ::tolower);
    string temp=ch;
    reverse(ch.begin(), ch.end());
    if(temp==ch)
    return true;
    return false;
}
int main(){
    string s;
    cin>>s;
    cout << saveIronman(s);
    return 0;
}