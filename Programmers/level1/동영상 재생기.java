class Solution {
    static int hourToMinute(String time){
        String hour = time.substring(0,2);
        String minute = time.substring(3);
        return Integer.parseInt(hour)*60 + Integer.parseInt(minute);
    }

    static String minuteToHour(int time){
        int hour = time/60;
        int minute = time%60;
        String hourString = String.valueOf(hour);
        if(hourString.length()==1){
            hourString = "0"+hourString;
        }
        String minuteString = String.valueOf(minute);
        if(minuteString.length()==1){
            minuteString = "0"+minuteString;
        }
        return hourString+":"+minuteString;
    }
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        int videoLenInt = hourToMinute(video_len);
        int curPos = hourToMinute(pos);
        int opStartInt = hourToMinute(op_start);
        int opEndInt = hourToMinute(op_end);

        for(String command : commands){
            if(opStartInt <= curPos && curPos<=opEndInt){
                curPos = opEndInt;
            }
            if("next".equals(command)){
                if(curPos + 10 >videoLenInt){
                    curPos = videoLenInt;
                }else{
                    curPos += 10;
                }
            }else if("prev".equals(command)){
                if(curPos - 10 < 0){
                    curPos = 0;
                }else{
                    curPos -= 10;
                }
            }
        }
        if(opStartInt <= curPos && curPos<=opEndInt){
            curPos = opEndInt;
        }
        answer = minuteToHour(curPos);
        return answer;
    }
}