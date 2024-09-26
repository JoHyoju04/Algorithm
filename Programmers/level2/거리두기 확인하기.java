import java.util.*;

class Solution {
    static boolean search(int r,int c,String[] place){
        int[][] manhattan = {{-2,0},
                {-1,-1},{-1,0},{-1,1},
                {0,-2},{0,-1},{0,1},{0,2},
                {1,-1},{1,0},{1,1},
                {2,0}
        };
        for(int i=0;i<manhattan.length;i++){
            int nr = r+manhattan[i][0];
            int nc = c+manhattan[i][1];
            if(nr<0||nr>=5 || nc<0||nc>=5)  continue;
            //사람이 있다면
            if(place[nr].charAt(nc)=='P'){
                //대각선에 있다면
                if(nr!=r && nc!=c){
                    //파티션이 하나라도 없다면 거리두기 지키지 못함
                    if(!(place[nr].charAt(c)=='X' && place[r].charAt(nc)=='X')){
                        return true;
                    }
                }
                //대각선에 없다면
                else{
                    //가로에 있다면
                    if(nr==r){
                        if(place[r].charAt(Math.max(nc,c)-1)!='X'){
                            return true;
                        }
                    }
                    //세로에 있다면
                    else{
                        if(place[Math.max(nr,r)-1].charAt(c)!='X'){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        for(int i=0;i<5;i++){
            boolean isManhattanDistOut = false;
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    if(places[i][j].charAt(k)=='P'){
                        isManhattanDistOut = search(j,k,places[i]);
                    }
                    //거리두기 지키고 있지 않다면
                    if(isManhattanDistOut){
                        break;
                    }
                }
                //거리두기 지키고 있지 않다면
                if(isManhattanDistOut){
                    break;
                }
            }
            //거리두기 지키고 있지 않다면
            if(isManhattanDistOut){
                answer[i] = 0;
            }else{
                answer[i] = 1;
            }
        }
        return answer;
    }
}