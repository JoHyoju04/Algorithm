class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        int R = board.length;
        int C = board[0].length;
        int[][] durability = new int[R+1][C+1];

        for(int i=0;i<skill.length;i++){
            int type = skill[i][0];
            int r1 = skill[i][1],c1 = skill[i][2];
            int r2 = skill[i][3],c2 = skill[i][4];
            int degree = skill[i][5];

            //공격
            if(type==1) degree *= -1;

            durability[r1][c1] += degree;
            durability[r1][c2+1] += -degree;
            durability[r2+1][c1] += -degree;
            durability[r2+1][c2+1] += degree;
        }

        for(int i=0;i<R+1;i++){
            for(int j=0;j<C+1;j++){
                if(j==0) continue;
                durability[i][j] += durability[i][j-1];
            }
        }

        for(int i=0;i<C+1;i++){
            for(int j=0;j<R+1;j++){
                if(j==0) continue;
                durability[j][i] += durability[j-1][i];
            }
        }

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                int sum = board[i][j]+durability[i][j];
                if(sum>0)   answer+=1;
            }
        }
        return answer;
    }
}