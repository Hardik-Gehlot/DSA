import java.util.LinkedList;

class Solution {
    public void dfs(int s,int[][] isConnected,boolean[] visited){
        visited[s]=true;
        LinkedList<Integer> adj = new LinkedList<>();
        for(int i=0;i<isConnected.length;i++){
            if(isConnected[s][i]==1){
                adj.add(i);
            }
        }
        for(int x: adj){
            if(!visited[x]){
                dfs(x, isConnected, visited);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        boolean[] visited = new boolean[isConnected.length];
        int count=0;
        for(int i=0;i<isConnected.length;i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);
            }
        }
        return count;
    }
}
public class NumberOfProvinces {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] isConnected = {{1,0,0},{0,1,0},{0,0,1}};
        int ans = solution.findCircleNum(isConnected);
        System.out.println(ans);
    }
}
/*
https://leetcode.com/problems/number-of-provinces/
 There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

 */
