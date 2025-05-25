class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>>freq(26,vector<int>(26,0));
        int res=0;
        for(int i=0;i<words.size();i++)
        {
            int index=words[i][0]-'a';
            int i2=words[i][1]-'a';
            if(freq[i2][index] == 0)
            {
                freq[index][i2]++;
            }
            else
            {
                res+=4;
                freq[i2][index]--;
            }
        }

        for(int i=0;i<26;i++)
        {
            if(freq[i][i]>0)
            {
                res+=2;
                break;
            }
        }

        return res;
    }
};