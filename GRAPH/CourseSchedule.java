import java.util.*;
import java.lang.*;
class Solution {
    private boolean cycle(int i,boolean[] visited, boolean[] currVisited,LinkedList<Integer>[] adj){
        visited[i]=true;
        currVisited[i]=true;
        for(int v:adj[i]){
            if(!visited[v]){
                if(cycle(v,visited,currVisited,adj)){
                    return true;
                }
            }else if(visited[v] && currVisited[v]){
                return true;
            }
        }
        currVisited[i]=false;
        return false;
    }
    public boolean canFinish(int V, int[][] adj) {
        boolean[] visited = new boolean[V];
        boolean[] currVisited = new boolean[V];
        LinkedList<Integer>[] graph = new LinkedList[V];
        for(int i=0;i<V;i++){
            graph[i]= new LinkedList<>();
        }
        for(int[] x:adj){
            graph[x[0]].add(x[1]);
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycle(i,visited,currVisited,graph)){
                    return false;
                }
            }
        }
        return true;
    }
}
public class CourseSchedule {
    public static void main(String[] args) {
        int V = 2;
        int[][] adj = {{1,0},{0,1}};
        Solution solution = new Solution();
        boolean x = solution.canFinish(V, adj);
        System.out.println(x);
    }
}

/*
https://leetcode.com/problems/course-schedule/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 */
