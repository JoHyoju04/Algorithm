import java.util.Arrays;

class Solution {
    public String solution(String input_string) {
        String answer = "";
        int[] cnts= new int[75];
        String s="";
        for(int i=0;i<input_string.length();i++){
            char ch= input_string.charAt(i);
            if(i==0){
                s+=ch;
                cnts[ch-'0']=1;
                continue;
            }
            if(input_string.charAt(i-1)==ch){
                s+=ch;
            }
            else{
                if(cnts[ch-'0']>0 && answer.indexOf(ch)==-1){
                    answer+=ch;
                }
                s+=ch;
            }
            cnts[ch-'0']+=s.length();
        }

        if(answer.length()==0){
            return "N";
        }
        char[] charArr = answer.toCharArray(); 
        Arrays.sort(charArr); 
        answer = new String(charArr);

        return answer;
    }
}