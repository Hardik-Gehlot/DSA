import java.util.*;
import java.lang.*;
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> path = new ArrayList<>();
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int source=0,des=graph.length-1;
        dfsrec(source,des,graph);
        return res;
    }
    public void dfsrec(int source,int des,int[][] graph){
        path.add(source);
        if(source==des){
            res.add(new ArrayList<>(path));
        }
        for(int i=0;i<graph[source].length;i++){
            dfsrec(graph[source][i],des,graph);
        }
        path.remove(path.size()-1);
    }
}
public class AllPathFromSourceToTarget {
    public static void main(String[] args) {
        int[][] graph = {{4,3,1},{3,2,4},{3},{4},{}};
        Solution solution = new Solution();
        List<List<Integer>> list = solution.allPathsSourceTarget(graph);
        for(List<Integer> li:list){
            for(int x:li){
                System.out.print(x+" ");
            }
            System.out.println("");
        }
    }
}


/*
https://leetcode.com/problems/all-paths-from-source-to-target/
 Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:

Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:

Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

 */
