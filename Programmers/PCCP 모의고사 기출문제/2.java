import java.lang.Math;
import java.util.*;

class Solution {
    int[] result;
    boolean[][] visited;

    public int solution(int[][] land) {
        int answer = 0;
        int R=land.length;
        int C=land[0].length;
        result = new int[C];
        visited=new boolean[R][C];
        int num=1;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(land[i][j]==1 && !visited[i][j]){
                    bfs(i,j,land,num);
                    num+=1;
                }
            }
        }

        for(int i=0;i<C;i++){
            answer=Math.max(answer,result[i]);
        }

        return answer;
    }

    void bfs(int r, int c, int[][] land,int num){
        Queue<Node> que=new LinkedList<>();
        int R=land.length;
        int C=land[0].length;
        int[][] dirs={{0,1},{0,-1},{1,0},{-1,0}};
        visited[r][c]=true;
        que.offer(new Node(r,c));
        int cnt=1;

        int minC=C;
        int maxC=0;
        while(!que.isEmpty()){
            Node cur=que.poll();
            minC=Math.min(minC,cur.c);
            maxC=Math.max(maxC,cur.c);
            for(int i=0;i<4;i++){
                int nR=cur.r+dirs[i][0];
                int nC=cur.c+dirs[i][1];
                if(0>nR || nR>=R || 0>nC || nC>=C || visited[nR][nC] || land[nR][nC]==0)
                    continue;
                visited[nR][nC]=true;
                que.offer(new Node(nR,nC));
                cnt+=1;
            }

        }
        for(int i=minC;i<=maxC;i++){
            result[i] += cnt;
        }

        return;
    }
}
class Node{
    int r;
    int c;

    public Node(int r, int c){
        this.r=r;
        this.c=c;
    }
}