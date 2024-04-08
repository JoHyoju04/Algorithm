import java.lang.Math;
class Solution {
    public int solution(int[] menu, int[] order, int k) {
        int answer = 0;
        int[] finishTime=new int[order.length];

        int time=0;
        int idx=0;
        for(int od : order){
            int menuTime=menu[od];
            if(idx*k>time){
                time=idx*k+menuTime;
            }
            else{
                time+=menuTime;
            }
            finishTime[idx++]=time;
        }

        for(int i=0;i<order.length;i++){
            int cnt=finishTime[i]/k+1;
            if(finishTime[i]%k==0)
                cnt-=1;
            cnt=Math.min(cnt,order.length);
            answer=Math.max(answer,cnt-i);
        }
        return answer;
    }
}