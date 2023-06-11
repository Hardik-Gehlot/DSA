class Solution {
    public void dfs(char[][]board,int i,int j){
        if(i<0 || i>=board.length || j<0 || j>=board[0].length){
            return;
        }
        if(board[i][j]=='O'){
            board[i][j] = 'B';
            dfs(board,i+1,j);
            dfs(board,i-1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
        }
    }
    public void solve(char[][] board) {
        int n= board.length;
        int m=board[0].length;
        for(int i=0;i<n;i++){
            // left -> top to bottom
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            // right -> top to bottom
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            // top -> left to right
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
            // bottom -> left to right
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='B'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
}
public class SurroundedRegion {
    public static void main(String[] args) {
        char[][] board = {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'},
        };
        Solution solution = new Solution();
        solution.solve(board);
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                System.out.print(board[i][j]+" ");
            }
            System.out.println("");
        }
    }
}


/*
https://leetcode.com/problems/surrounded-regions/
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:

Input: board = [["X"]]
Output: [["X"]]
 */