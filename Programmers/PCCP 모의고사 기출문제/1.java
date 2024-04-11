import java.lang.*;
class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        int curHealth=health;
        int beforeTime=0;
        for(int i=0;i<attacks.length;i++){
            if(i!=0)    beforeTime=attacks[i-1][0];
            int notAttackTimes=attacks[i][0]-beforeTime-1;
            int addHealth=notAttackTimes/bandage[0]*bandage[2];
            int secHealth=notAttackTimes*bandage[1];
            curHealth=Math.min(health,addHealth+secHealth+curHealth);

            curHealth -= attacks[i][1];
            if(curHealth<=0){
                return -1;
            }
        }
        answer=curHealth;
        return answer;
    }
}