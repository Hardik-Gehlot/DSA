// https://practice.geeksforgeeks.org/problems/string-ignorance/0
// Problem:
// Given a string of both uppercase and lowercase alphabets, the task is to print the string with
// alternate occurrences of any character dropped(including space and consider upper and lowercase as
// same).
// Input:
// First line consists of T test cases. First line of every test case consists of String S.

// Output:
// Single line output, print the updated string.

// Constraints:
// 1<=T<=100
// 1<=|String|<=10000

// Example:
// Input:
// 2
// It is a long day dear.
// Geeks for geeks
// Output:
// It sa longdy ear.
// Geks fore

// Explanation:
// For the 1st test case. 
// Print first "I" and then ignore next "i". Similarly print first space then ignore next space. and so on.

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    int t;
    cin>>t;
    while(t-- >=0){
        getline(cin, s);
        bool freq[27]={false};
        int idx=0;
        string ans="";
        for(char ch :s){
            if(ch == ' '){
                if(!freq[26]){
                    freq[26]=true;
                    ans += ch;
                }else freq[26]=false;
            }else{
                if(!freq[tolower(ch)-'a']){
                freq[tolower(ch)-'a']=true;
                ans += ch;
            }else freq[tolower(ch)-'a']=false;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}