import java.util.*;
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<ArrayList<Integer>> q = new LinkedList<>();
        int fresh=0,time=0;
        int[] ax = {1,-1,0,0};
        int[] ay = {0,0,1,-1};
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==2){
                    ArrayList<Integer> arr = new ArrayList<>();
                    arr.add(i);
                    arr.add(j);
                    q.add(arr);
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        while(!q.isEmpty()){
            int size = q.size();
            int temp =0;
            while(size!=0){
                ArrayList<Integer> arr = q.poll();
                for(int i=0;i<4;i++){
                    int x=ax[i]+arr.get(0);
                    int y=ay[i]+arr.get(1);
                    if(!(x<0 || x>=grid.length || y<0 || y>=grid[0].length)){
                        if(grid[x][y]==1){
                            temp++;
                            grid[x][y]=2;
                            ArrayList<Integer> list = new ArrayList<>();
                            list.add(x);
                            list.add(y);
                            q.add(arr);
                        }
                    }
                }
                size--;
            }
            if(temp!=0) time++;
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    time=0;
                    return -1;
                }
            }
        }
        return time;
    }
}
public class RottingOranges {
    public static void main(String[] args) {
        int[][] grid = {{2,1,1},{1,1,0},{0,1,1}};
        Solution solution = new Solution();
        int x = solution.orangesRotting(grid);
        System.out.println(x);
    }
}





/*
https://leetcode.com/problems/rotting-oranges/
You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

*/
