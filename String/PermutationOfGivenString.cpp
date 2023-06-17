// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
// Problem:
// Given a string S. The task is to print all unique permutations of the given string in
// lexicographically sorted order.

// Example 1:
// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA .

// Example 2:
// Input: ABSG
// Output:
// ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
// BASG BGAS BGSA BSAG BSGA GABS GASB 
// GBAS GBSA GSAB GSBA SABG SAGB SBAG 
// SBGA SGAB SGBA
// Explanation:
// Given string ABSG has 24 permutations.

// Expected Time Complexity: O(n! * n)
// Expected Space Complexity: O(n! * n)

// Constraints:
// 1 <= length of string <= 5

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void permutation(vector<string>& v1, string S, int i){
    if(i>=S.length()){
        for(int k=0;k<v1.size();k++) 
            if(S==v1[k]) return;  
        v1.push_back(S);
        return;
    }
    
    for(int j=i;j<S.length();j++){
        // Swap
        swap(S[i],S[j]);
        permutation(v1,S,i+1);
        
        //Backtrack
        swap(S[i],S[j]);
    }
}
int main(){
    string S;
    cin>>S;
    vector<string> v1;
    int i= 0;
    permutation(v1,S,i);
    sort(v1.begin(),v1.end());
    for(int i =0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    return 0;
}