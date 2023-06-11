import java.util.*;
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> result = new ArrayList<>();
        boolean[] visited  = new boolean[graph.length];
        boolean[] currVisited  = new boolean[graph.length];
        boolean[] presentCycle  = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!visited[i]){
                cycle(i,visited,currVisited,graph,presentCycle);
            }
        }
        for(int i=0;i<presentCycle.length;i++){
            if(!presentCycle[i]){
                result.add(i);
            }
        }
        return result;
    }
    private boolean cycle(int i,boolean[] visited, boolean[] currVisited,int[][]graph,boolean[] presentCycle){
        visited[i]=true;
        currVisited[i]=true;
        for(int v:graph[i]){
            if(!visited[v]){
                if(cycle(v,visited,currVisited,graph,presentCycle)){
                    presentCycle[i] = true;
                    return true;
                }
            }else if(visited[v] && currVisited[v]){
                presentCycle[i] = true;
                return true;
            }
        }
        currVisited[i]=false;
        return false;
    }
}
public class FindEventualSafeState {
    public static void main(String[] args) {
        int[][] grid = {{1,2},{2,3},{5},{0},{5},{},{}};
        Solution solution = new Solution();
        List<Integer> arr = solution.eventualSafeNodes(grid);
        for(int x:arr){
            System.out.print(x+" ");
        }
    }
}
/*
https://leetcode.com/problems/find-eventual-safe-states/
 There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:
Illustration of graph

Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.

 */
