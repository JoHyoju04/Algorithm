class Solution {
    static final int RED_START = 1;
    static final int BLUE_START = 2;
    static final int RED_END = 3;
    static final int BLUE_END = 4;
    static final int WALL = 5;
    static int answer=17;
    static int[][] dirs= {{0,1},{0,-1},{1,0},{-1,0}};
    static boolean[][][] visited;

    static public void dfs(int depth,int[] redLoc,int[] blueLoc,int[][] maze){
        if(maze[redLoc[0]][redLoc[1]]==RED_END && maze[blueLoc[0]][blueLoc[1]]==BLUE_END){
            answer = Math.min(answer,depth);
            return;
        }
        for(int i=0;i<4;i++){
            int[] nextRedLoc = new int[2];
            int[] nextBlueLoc = new int[2];
            nextRedLoc[0] =redLoc[0];
            nextRedLoc[1] = redLoc[1];
            boolean redReach = false;
            if(maze[redLoc[0]][redLoc[1]]!=RED_END){
                nextRedLoc[0] += dirs[i][0];
                nextRedLoc[1] += dirs[i][1];
            }
            else redReach = true;
            if(nextRedLoc[0]>=maze.length || nextRedLoc[0]<0 ||nextRedLoc[1]>=maze[0].length || nextRedLoc[1]<0 || (visited[0][nextRedLoc[0]][nextRedLoc[1]] && !redReach)) continue;
            if(maze[nextRedLoc[0]][nextRedLoc[1]]==WALL) continue;
            for(int j=0;j<4;j++){
                nextBlueLoc[0] =blueLoc[0];
                nextBlueLoc[1] = blueLoc[1];
                boolean blueReach = false;
                if(maze[blueLoc[0]][blueLoc[1]]!=BLUE_END){
                    nextBlueLoc[0] += dirs[j][0];
                    nextBlueLoc[1] += dirs[j][1];
                }else blueReach=true;
                if(nextBlueLoc[0]>=maze.length || nextBlueLoc[0]<0|| nextBlueLoc[1]>=maze[0].length || nextBlueLoc[1]<0 || (visited[1][nextBlueLoc[0]][nextBlueLoc[1]] && !blueReach)) continue;
                if(maze[nextBlueLoc[0]][nextBlueLoc[1]]==WALL) continue;
                if(nextRedLoc[0] == nextBlueLoc[0] && nextRedLoc[1] == nextBlueLoc[1])  continue;
                if(redLoc[0] == nextBlueLoc[0] && redLoc[1] == nextBlueLoc[1] && blueLoc[0]==nextRedLoc[0] && blueLoc[1]==nextRedLoc[1])   continue;

                visited[0][nextRedLoc[0]][nextRedLoc[1]] = true;
                visited[1][nextBlueLoc[0]][nextBlueLoc[1]] = true;
                dfs(depth+1,nextRedLoc,nextBlueLoc,maze);
                visited[0][nextRedLoc[0]][nextRedLoc[1]] = false;
                visited[1][nextBlueLoc[0]][nextBlueLoc[1]] = false;
            }
        }
    }

    public int solution(int[][] maze) {
        int[] redLoc = new int[2];
        int[] blueLoc = new int[2];
        visited = new boolean[2][maze.length][maze[0].length];
        for(int i =0;i<maze.length;i++){
            for(int j=0;j<maze[0].length;j++){
                if(maze[i][j]==RED_START){
                    redLoc[0] = i;
                    redLoc[1] = j;
                }else if(maze[i][j]==BLUE_START){
                    blueLoc[0] = i;
                    blueLoc[1] = j;
                }
            }
        }
        visited[0][redLoc[0]][redLoc[1]] = true;
        visited[1][blueLoc[0]][blueLoc[1]] = true;
        dfs(0,redLoc,blueLoc,maze);
        if(answer==17)  answer=0;
        return answer;
    }
}