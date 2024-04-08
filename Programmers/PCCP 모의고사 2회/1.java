class Solution {
    public int[] solution(String command) {
        int[] answer = new int[2];
        int[] loc={0,0,0}; //y,x,방향
        int[][] dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<command.length();i++){
            char c=command.charAt(i);
            if(c=='G'){
                int ny=loc[0]+dir[loc[2]][0];
                int nx=loc[1]+dir[loc[2]][1];
                loc[0]=ny;
                loc[1]=nx;
            }
            else if(c=='B'){
                int ny=loc[0]+dir[(loc[2]+2)%4][0];
                int nx=loc[1]+dir[(loc[2]+2)%4][1];
                loc[0]=ny;
                loc[1]=nx;
            }
            else if(c=='R'){
                int nDir=(loc[2]+1)%4;
                loc[2]=nDir;
            }
            else if(c=='L'){
                int nDir=(loc[2]+3)%4;
                loc[2]=nDir;
            }
        }
        answer[0]=loc[1];
        answer[1]=loc[0];
        return answer;
    }
}