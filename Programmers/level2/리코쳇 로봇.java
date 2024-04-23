import java.util.Queue;
import java.util.LinkedList;
class Solution {
    static int R;
    static int C;
    static int[][] dirs={{0,1},{0,-1},{1,0},{-1,0}};
    public int solution(String[] board) {
        int answer = 0;
        R=board.length;
        C=board[0].length();
        int startR=0;
        int startC=0;
        int endR=0;
        int endC=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(board[i].charAt(j)=='R'){
                    startR=i;
                    startC=j;
                }
                if(board[i].charAt(j)=='G'){
                    endR=i;
                    endC=j;
                }
            }
        }
        answer=bfs(board,startR,startC,endR,endC);
        return answer==0?-1:answer;
    }
    private int bfs(String[] board,int startR,int startC,int endR,int endC){
        boolean[][][] visited=new boolean[4][R][C];
        Queue<Node> que=new LinkedList<>();
        que.offer(new Node(startR,startC,0)); //r,c,cnt

        while(!que.isEmpty()){
            Node cur=que.poll();
            int curR=cur.r;
            int curC=cur.c;
            int cnt=cur.cnt;
            if(curR==endR && curC==endC){
                return cnt;
            }
            for(int i=0;i<4;i++){
                if(!visited[i][curR][curC]){
                    int[] stopLoc=move(board,curR,curC,i);

                    if(stopLoc[0]==curR &&stopLoc[1]==curC) continue;
                    visited[i][curR][curC]=true;
                    que.offer(new Node(stopLoc[0],stopLoc[1],cnt+1));
                }
            }
        }
        return 0;
    }

    private int[] move(String[] board,int r,int c,int dir){
        int[] retLoc=new int[2];
        int nr=r;
        int nc=c;
        while(true){
            nr+=dirs[dir][0];
            nc+=dirs[dir][1];
            if(!isNotOOB(nr,nc) || board[nr].charAt(nc)=='D')    break;
        }
        retLoc[0]=nr-dirs[dir][0];;
        retLoc[1]=nc-dirs[dir][1];
        return retLoc;
    }
    private boolean isNotOOB(int r, int c){
        return 0<=r && r<R && 0<=c && c<C;
    }
}
class Node{
    int r;
    int c;
    int cnt;
    public Node(int r,int c,int cnt){
        this.r=r;
        this.c=c;
        this.cnt=cnt;
    }
}