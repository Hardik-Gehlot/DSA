// https://practice.geeksforgeeks.org/problems/geek-and-its-colored-strings1355/1
// Problem:
// Find the count of all possible strings of size n.Each character of the string is either ‘R’, ‘B’ or
// ‘G’. In the final string there needs to be at least r number of ‘R’, at least b number of ‘B’ and at
// least g number of ‘G’ (such that r + g + b <= n). 

// Example 1:
// Input: n = 4, r = 1, g = 1, b = 1
// Output: 36 
// Explanation: No. of 'R' >= 1, 
// No. of ‘G’ >= 1, No. of ‘B’ >= 1 
// and (No. of ‘R’) + (No. of ‘B’) 
// + (No. of ‘G’) = n then 
// following cases are possible: 
// 1. RBGR and its 12 permutation 
// 2. RBGB and its 12 permutation 
// 3. RBGG and its 12 permutation 
// Hence answer is 36.

// Example 2:
// Input: n = 4, r = 2, g = 0, b = 1
// Output: 22
// Explanation: No. of 'R' >= 2,
// No. of ‘G’ >= 0, No. of ‘B’ >= 1
// and (No. of ‘R’) + (No. of ‘B’)
// + (No. of ‘G’) <= n then 
// following cases are possible:
// 1. RRBR and its 4 permutation
// 2. RRBG and its 12 permutation
// 3. RRBB and its 6 permutation
// Hence answer is 22.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1<= n <=20
// 1<= r+b+g <=n

#include<iostream>
using namespace std;
long long fact[21];
void func(){
    fact[0]=1;
    for(int i=1;i<=20;++i)
    {
        fact[i]=fact[i-1]*i;
    }
}
long long possibleStrings(int n, int r, int b, int g) {
    func();
    long long ans=0;
    int left=n-(r+g+b);
    for(int i=0;i<=left;++i)
    {
        for(int j=0;j<=left;++j)
        {
            int k=left-(i+j);
            if(k>=0)
            {
                int R=r+i;
                int G=g+j;
                int B=b+k;
                ans+=(fact[n]/(fact[R]*fact[G]*fact[B]));
            }
        }
    }
    return ans;
}
int main(){
    int n,r,g,b;
    cin>>n>>r>>g>>b;
    cout << possibleStrings(n,r,b,g) << endl;
    return 0;
}