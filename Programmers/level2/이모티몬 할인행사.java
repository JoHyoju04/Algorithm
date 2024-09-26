import java.util.*;

class Solution {
    static int emoticonsLen;
    static List<Integer[]> candidates = new ArrayList<>();
    static int[] rate = {10,20,30,40};

    static void dfs(int depth,int[] selected,int[]emoticons,int[][]users){
        if(depth==emoticonsLen){
            int totalJoin = 0;
            int totalAmount = 0;
            for(int[] user : users){
                int userRate = user[0];
                int userPrice = user[1];
                int amount=0;
                for(int i=0;i<emoticonsLen;i++){
                    if(selected[i]>=userRate){
                        amount += emoticons[i] * (100-selected[i])*0.01;
                    }
                }
                if(amount>=userPrice){
                    totalJoin++;
                }else{
                    totalAmount += amount;
                }
            }
            candidates.add(new Integer[]{totalJoin,totalAmount});
            return;
        }
        for(int i=0;i<4;i++){
            selected[depth] = rate[i];
            dfs(depth+1,selected,emoticons,users);
            selected[depth] = 0;
        }
    }
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = {};
        emoticonsLen = emoticons.length;
        int[] selected = new int[emoticonsLen];
        dfs(0,selected,emoticons,users);

        Collections.sort(candidates,(o1,o2)->o1[0]==o2[0]?o2[1]-o1[1]:o2[0]-o1[0]);
        answer = new int[]{candidates.get(0)[0],candidates.get(0)[1]};

        return answer;
    }
}