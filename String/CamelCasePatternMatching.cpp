// https://practice.geeksforgeeks.org/problems/camelcase-pattern-matching2259/1
// Problem:
// Given a dictionary of words where each word follows CamelCase notation, print all words
// (in lexicographical order) in the dictionary that match with a given pattern consisting of uppercase
// characters only.

// Example: GeeksForGeeks matches the pattern "GFG", because if we combine all the capital letters in
// GeeksForGeeks they become GFG. Also note "GeeksForGeeks" matches with the pattern "GFG" and also
// "GF", but not matches with "FG".

// CamelCase is the practice of writing compound words or phrases such that each word or abbreviation
// begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks,
// CodeBlocks, etc.

// Example 1:
// Input:
// N=3
// Dictionary=["WelcomeGeek",
// "WelcomeToGeeksForGeeks","GeeksForGeeks"]
// Pattern="WTG"
// Output:
// WelcomeToGeeksForGeeks
// Explanation:
// Since only WelcomeToGeeksForGeeks matches 
// the pattern, it is the only answer.

// Example 2:
// Input:
// N=8
// Dictionary=["Hi","Hello","HelloWorld",
// "HiTech","HiGeek","HiTechWorld",
// "HiTechCity","HiTechLab"]
// Pattern="HA"
// Output:
// -1
// Explanation:
// Since the pattern matches none of the words
// of the string,the output is -1.

// Expected Time Complexity: O(N*|S|) S=Longest string in Dictionary
// Expected Auxillary Space: O(26*N)

// Constraints:
// 1<=N<=1000
// 1<=|S|<=100
// 1<=|Pattern|<=|S|<=100
// S is the longest word in Dictionary.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool matchPattern(string word, string patternToMatch){
    string patternInWord = "";
    for(char c: word){
        if(isupper(c)) patternInWord+=c;
        if(patternInWord == patternToMatch){
            return true;
        }
    }
    return patternToMatch==patternInWord;
}
int main(){
    int n;
    cin>>n;
    string dict[n];
    string pattern;
    for(int i =0; i<n; i++){
        cin>>dict[i];
    }
    cin>>pattern;
    vector<string> ans;
    for(string word:dict){
        if(matchPattern(word,pattern)){
            ans.push_back(word);
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.empty()) ans.push_back("-1");
    for(string x:ans){
        cout<<x<<" ";
    }

    return 0;
}