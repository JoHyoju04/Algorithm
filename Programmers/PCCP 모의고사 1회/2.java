class Solution {
    int answer;
    public int solution(int[][] ability) {
        answer = 0;
        boolean[] selected=new boolean[ability.length];
        dfs(0,ability,selected,0);
        return answer;
    }

    void dfs(int depth,int[][] ability,boolean[] selected,int sum){
        if(depth==ability[0].length){
            answer=Math.max(answer,sum);
            return;
        }
        for(int i=0;i<ability.length;i++){
            if(!selected[i]){
                selected[i]=true;
                dfs(depth+1,ability,selected,sum+ability[i][depth]);
                selected[i]=false;
            }
        }
    }
}