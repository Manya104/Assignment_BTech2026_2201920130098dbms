class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char c1 = 'a';
        char c2 = 'b';
        if(x<y){
            swap(x,y);
            swap(c1,c2);
        }
        int ans = 0;
        vector<char> s1;
        for(char ch: s){
            if(ch == c2 && !s1.empty() && s1.back()==c1){
                s1.pop_back();
                ans=ans+x;
            }
            else{
                s1.push_back(ch);
            }
        }
        vector<char> s2;
        for(char ch : s1){
            if(ch == c1 && !s2.empty() && s2.back()==c2){
                s2.pop_back();
                ans=ans+y;
            }
            else{
                s2.push_back(ch);
            }
        }
        return ans;
    }
};