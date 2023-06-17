// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// * Problem:
// Given a matrix of size r*c. Traverse the matrix in spiral form.

// ? Example 1:
// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// Explanation:

// ? Example 2:
// Input:
// r = 3, c = 4  
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}}
// Output: 
// 1 2 3 4 8 12 11 10 9 5 6 7
// Explanation:
// Applying same technique as shown above, 
// output for the 2nd testcase will be 
// 1 2 3 4 8 12 11 10 9 5 6 7.

// ! Expected Time Complexity: O(r*c)
// ! Expected Auxiliary Space: O(r*c), for returning the answer only.

// * Constraints:
// 1 <= r, c <= 100
// 0 <= matrixi <= 100

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    int matrix[r][c];
    for(int i =0; i<r; i++){
        for(int j=0;j<c; j++){
            cin>>matrix[i][j];
        }
    }

    // * Approach 1:
    // int init=0;
    // int row = r;
    // int col = c;
    // int count=0,total = r*c;
    // while(row>0 && col>0){
    //     for(int i=init;count<total && i<init+col;i++){
    //         cout<<matrix[init][i]<<" ";
    //         count++;
    //     }
    //     row--;
    //     for(int i=init+1;count<total && i<=row+init;i++){
    //         cout <<matrix[i][col+init-1]<<" ";
    //         count++;
    //     }
    //     col--;
    //     for(int i = col+init-1;count<total && i>=init; i--){
    //         cout<<matrix[row+init][i]<<" ";
    //         count++;
    //     }
    //     row--;
    //     for(int i=row+init;count<total && i>init;i--){
    //         cout<<matrix[i][init]<<" ";
    //         count++;
    //     }
    //     col--;
    //     init++;
    // }

    // * Approach 2:
    int count = 0 ;
        int row = r;
        int col = c;
        int total = row*col ;
        
        //index
        
        int startingRow = 0 ;
        int startingCol = 0 ;
        int endingRow = row-1 ;
        int endingCol = col-1 ;
        
        while(count<total){
            //print Starting row ;
            
            for(int i=startingCol ; count<total && i<=endingCol ; i++){
                cout<<matrix[startingRow][i]<<" ";
                count++ ;
            }
            
            startingRow++ ;
            
            //print ending col 
            
            for(int i=startingRow ; count<total && i<=endingRow ; i++){
                cout<<matrix[i][endingCol]<<" ";
                count++ ;
            }
            
            endingCol-- ;
            
            //print ending row ;
            
            for(int i=endingCol ; count<total  && i>=startingCol ; i--){
                cout<<matrix[endingRow][i]<<" ";
                count++ ;
            }
            endingRow-- ;
            
            //print starting Col 
            
            for(int i=endingRow ; count<total  && i>=startingRow ; i--){
            cout<<matrix[i][startingCol]<<" ";
            count++ ;
            }
            
            startingCol++ ;
        }
    return 0;
}