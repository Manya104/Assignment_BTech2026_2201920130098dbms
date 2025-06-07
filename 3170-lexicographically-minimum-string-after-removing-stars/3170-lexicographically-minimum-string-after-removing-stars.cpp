class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qp;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='*')   qp.push(make_pair((s[i]-'a')*1000000-i,i));
            else
            {
                auto temp=qp.top();
                s[temp.second]=' ';
                qp.pop();
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' || s[i]=='*')   continue;
            else    ans+=s[i];
        }
        return ans;
    }
};