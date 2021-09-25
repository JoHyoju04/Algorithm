class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int answer=0,left=0,right=0;
        
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end())   break;
            right++;
            m.insert({s[i],i});
        }
        answer=right;
        right--;
        while(right<s.size()-1){
            if(m.find(s[++right])!=m.end()){
                int i;
                for(i=left;i<right;i++){
                    m.erase(s[i]);
                    if(s[right]==s[i])  break;
                }
                left=i+1;
            }
            m.insert({s[right],right});
            answer=max(answer,right-left+1);
        }
        return answer;
    }
};