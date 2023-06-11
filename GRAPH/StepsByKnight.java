import java.util.*;
class Solution{
    //Function to find out minimum steps Knight needs to reach target position.
    public int minStepToReachTarget(int KnightPos[], int TargetPos[], int N)
    {
        int tx = TargetPos[0]-1,ty = TargetPos[1]-1;
        int x1 = KnightPos[0]-1,y1 = KnightPos[1]-1;
        
        if(x1 == tx && y1 == ty) return 0;
        Queue<ArrayList<Integer>> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][N];
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(x1);
        arr.add(y1);
        q.add(arr);
        visited[x1][y1]=true;
        int ans = 0;
        while(!q.isEmpty()){
            int size = q.size();
            ans++;
            while(size!=0){
                ArrayList<Integer> ar = q.poll();
                int xx = ar.get(0);
                int yy = ar.get(1);
                int[] ax = {1,1,-1,-1,2,-2,2,-2};
                int[] ay = {2,-2,2,-2,1,1,-1,-1};
                for(int i=0;i<8;i++){
                    int nx = ax[i] + xx;
                    int ny = ay[i] + yy;
                    if(nx==tx && ny==ty) return ans;
                    if(!(nx <0 || nx >= N || ny <0 || ny >= N)){
                        if(!visited[nx][ny]){
                            visited[nx][ny]=true;
                            ArrayList<Integer> list = new ArrayList<>();
                            list.add(nx);
                            list.add(ny);
                            q.add(list);
                        }
                    }
                }

                size--;
            }
        }

        return ans;
    }
}
public class StepsByKnight {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] kp = {4,5};
        int[] tp = {1,1};
        int ans = solution.minStepToReachTarget(kp,tp, 6);
        System.out.println(ans);
    }
}

/*
https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1 
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

 

 

Your Task:
You don't need to read input or print anything.
Your task is to complete the function minStepToReachTarget() which takes the initial position
of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the
chessboard (N) as input parameters and returns the minimum number of steps required by the 
knight to reach from its current position to the given target position or return -1 if its
not possible.
 */
