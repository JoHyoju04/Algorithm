class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans;
        int max_len=0;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>max_len)
                {
                    max_len=r-l+1;
                    ans=s.substr(l,max_len);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>max_len)
                {
                    max_len=r-l+1;
                    ans=s.substr(l,max_len);
                }
                l--;
                r++;
            }
            
        }
        return ans;
    }
};