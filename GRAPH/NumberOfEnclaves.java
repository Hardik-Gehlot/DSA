class Solution {
    public void dfs(int[][] grid,int i,int j){
        if(i<0 || i>=grid.length || j<0 || j>= grid[0].length){
            return;
        }
        int ax[] = {1,-1,0,0};
        int ay[] = {0,0,1,-1};
        if(grid[i][j]==1){
            grid[i][j]=2;
            for(int x=0;x<4;x++){
                dfs(grid, i+ax[x], j+ay[x]);
            }
        }
    }
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        for(int i=0;i<n;i++){
            // left -> top to bottom
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }

            //right -> top to bottom
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1);
            }
        }
        for(int j=0;j<m;j++){
            // top -> left to right
            if(grid[0][j]==1){
                dfs(grid,0,j);
            }

            //bottom -> left to right
            if(grid[n-1][j]==1){
                dfs(grid,n-1,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int x:grid[i]){
                if(x==1)
                    ans++;
            }
        }
        return ans;
    }
}
public class NumberOfEnclaves {
    public static void main(String[] args) {
        int[][] grid = {
            {0,0,0,0},
            {1,0,1,0},
            {0,1,1,0},
            {0,0,0,0},
        };
        Solution solution = new Solution();
        int x = solution.numEnclaves(grid);
        System.out.println(x);
    }
}

/*
https://leetcode.com/problems/number-of-enclaves/
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:

Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

 */
