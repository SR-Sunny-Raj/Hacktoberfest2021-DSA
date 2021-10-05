import java.util.*;

/**
 * shortestPath
 */
public class shortestPath {

    public static int shortestPathSolve(int[][] grid, int k) {
        Queue<int[]> queue = new ArrayDeque<>();
        queue.add(new int[]{0, 0, 0, k});
        
        boolean[][] vis = new boolean[grid.length][grid[0].length];
        
        int[][] dirns = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(queue.size() > 0){
            int[] cc = queue.remove();
            // cc -> current coordinate
            if(vis[cc[0]][cc[1]]) continue;
            if(cc[3] < 0) continue;
            vis[cc[0]][cc[1]] = true;
            
            if(cc[0] == grid.length-1 && cc[1] == grid[0].length-1) return cc[2];
            // cdnts -> coordinates
            // dirns -> directions
            for(int[] cdnts: dirns){
                int nx = cc[0] + cdnts[0];
                int ny = cc[1] + cdnts[1];
                if(nx < 0 || nx >= grid.length) continue;
                if(ny < 0 || ny >= grid[0].length) continue;
                
                if(grid[nx][ny] == 0){
                    queue.add(new int[]{nx, ny, cc[2]+1, cc[3]});
                }else{
                    queue.add(new int[]{nx, ny, cc[2]+1, cc[3]-1});
                }
            }
        }
        
        return -1;
    }

    public static void main(String[] args) {

        // QUESTION -> 1293. Leetcode -> Shortest Path in a Grid with Obstacles Elimination

        // Scanner sc = new Scanner(System.in);
        int[][] grid = {{0,1,0},{1,0,1},{0,0,0}};
        int[][] grid2 = {{0,0},{1,0},{1,0},{1,0},{1,0},{1,0},{0,0},{0,1},{0,1},{0,1},{0,0},{1,0},{1,0},{0,0}};
        int[][] grid3 = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
        int k = 1;
        int k2 = 4;

        // Testcases -:

        System.out.println(shortestPathSolve(grid, k));
        System.out.println(shortestPathSolve(grid2, k2));
        System.out.println(shortestPathSolve(grid3, k));
    }
}