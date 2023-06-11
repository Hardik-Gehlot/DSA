import java.util.HashMap;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] arr = s.split(" ");
        HashMap<Character, String> hash = new HashMap<>();
        if(pattern.length()!=arr.length) return false;
        for(int i=0;i<pattern.length();i++){
            char c = pattern.charAt(i);
            if(hash.containsKey(c)){
                if(!hash.get(c).equals(arr[i])){
                    return false;
                }
            }else{
                if(!hash.containsValue(arr[i])){
                    hash.put(c, arr[i]);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}
public class NumberOfClosedIslands {
    public static void main(String[] args) {
        Solution solution = new Solution();
        // System.out.println(solution.closedIsland(grid));
        String pattern = "abba";
        String s ="cat cat cat cat";
        String[] arr = s.split(" ");
        boolean b = false;
        HashMap<Character, String> hash = new HashMap<>();
        if(pattern.length()!=arr.length) b=false;
        for(int i=0;i<pattern.length();i++){
            char c = pattern.charAt(i);
            if(hash.containsKey(c)){
                if(!hash.get(c).equals(arr[i])){
                    b= false;
                }
            }else{
                if(!hash.containsValue(arr[i])){
                    hash.put(c, arr[i]);
                }else{
                    return f
                }
            }
        }
        b=true;

    }
}

/*
https://leetcode.com/problems/number-of-closed-islands/
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

 */
