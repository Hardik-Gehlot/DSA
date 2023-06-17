// https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1
// Problem:
// Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if
// a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.

// Example 1:

// Input:
// R = 2, C = 2
// matrix[][] = {{1, 0},
//               {0, 0}}
// Output: 
// 1 1
// 1 0 
// Explanation:
// Only cell that has 1 is at (0,0) so all 
// cells in row 0 are modified to 1 and all 
// cells in column 0 are modified to 1.


// Example 2:

// Input:
// R = 4, C = 3
// matrix[][] = {{ 1, 0, 0},
//               { 1, 0, 0},
//               { 1, 0, 0},
//               { 0, 0, 0}}
// Output: 
// 1 1 1
// 1 1 1
// 1 1 1
// 1 0 0 
// Explanation:
// The position of cells that have 1 in
// the original matrix are (0,0), (1,0)
// and (2,0). Therefore, all cells in row
// 0,1,2 are and column 0 are modified to 1. 

// Expected Time Complexity: O(R * C)
// Expected Auxiliary Space: O(R + C) 

// Constraints:
// 1 ≤ R, C ≤ 1000
// 0 ≤ matrix[i][j] ≤ 1

#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int matrix[m][n];
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    int r = m;
    int c = n;
    int rowIdx[r]={0};
    int colIdx[c]={0};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==1){
                rowIdx[i] = 1;
                colIdx[j]=1;
            }
        }
    }
    for(int i=0;i<r;i++){
        if(rowIdx[i]==1){
            for(int j=0;j<c;j++){
                matrix[i][j]=1;
            }
        }
    }
    for(int i=0;i<c;i++){
        if(colIdx[i]==1){
            for(int j=0;j<r;j++){
                matrix[j][i]=1;
            }
        }
    }
    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            cout<<matrix[i][j]+" ";
        }
        cout<<endl;
    }
    return 0;
}
