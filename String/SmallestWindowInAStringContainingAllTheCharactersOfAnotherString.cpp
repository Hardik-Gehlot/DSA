// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// Given two strings S and P. Find the smallest window in the string S consisting of all the
// characters(including duplicates) of the string P.  Return "-1" in case there is no such window
// present. In case there are multiple such windows of same length, return the one with the least
// starting index.
// Note : All characters are in Lowercase alphabets. 

// Example 1:
// Input:
// S = "timetopractice"
// P = "toc"
// Output: 
// toprac
// Explanation: "toprac" is the smallest
// substring in which "toc" can be found.

// Example 2:
// Input:
// S = "zoomlazapzo"
// P = "oza"
// Output: 
// apzo
// Explanation: "apzo" is the smallest 
// substring in which "oza" can be found.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(n) n = len(p) O

// Constraints: 
// 1 ≤ |S|, |P| ≤ 105

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    string s,p;
    cin>>s;
    cin>>p;
    // Time limit exceed fot 3002 test case
    // int slen = s.size();
    // int plen = p.size();
    // if(slen == 0 || slen<plen) cout<< "-1";
    // unordered_map<char,int> map;
    // for(char c:p){
    //     map[c]++;
    // }
    // int count=0;
    // int start=0;
    // int minlen=INT_MAX;
    // int minleft=0;
    // for(int i=0;i<slen;i++){
    //     if(map.count(s[i])>0){
    //         map[s[i]]--;
    //         if(map[s[i]]>=0) count++;
    //     }
    //     while(count==plen){
    //         if(minlen>i-start+1){
    //             minlen=i-start+1;
    //             minleft=start;
    //         }
    //         if(map.count(s[start])>0){
    //             map[s[start]]++;
    //             if(map[s[start]]>0) count--;
    //         }
    //         start++;
    //     }
    // }
    // if(minlen>slen) cout<< "-1";
    // else
    // cout<< s.substr(minleft,minlen);
    int start=0;
    int end=0;
    int ansstart=0;
    int minlen=s.size()*3;//making minlen greater than slength
    int count=0;
    vector<int>v(256,0);
    for(int i=0;i<p.size();i++){
        v[p[i]]++;
    }
    while(end<s.size()){
        if(v[s[end]]>0)
        count++;
        v[s[end]]--;
        while(count==(int)p.size()){
            if(minlen>end-start+1){
                minlen=end-start+1;
                ansstart=start;
            }
            v[s[start]]++;
            if(v[s[start]]>0)
            count--;
           
            start++;
        }
        end++;
    }

    if(minlen>s.size())
    cout<< "-1";
    else cout<< s.substr(ansstart,minlen); 
    return 0;
}