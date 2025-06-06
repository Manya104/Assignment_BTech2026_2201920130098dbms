class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char>mintoryt(n);
        mintoryt[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
        //     if(mintoryt[i+1]>s[i]){
        //         mintoryt[i]=s[i];
        //     }
        //     else{
        //        mintoryt[i] = mintoryt[i+1];
        //     }
        // }
        mintoryt[i]=min(mintoryt[i+1],s[i]);}
        string t="";
        string paper="";
        // string ans="";
        int i=0;
        while(i<n){
            t.push_back(s[i]);
            char mnchar = (i + 1 < n)?mintoryt[i + 1]:s[i];
            while(!t.empty()&&t.back()<=mnchar){
                paper+=t.back();
                t.pop_back();
            }i++;
        }
        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;
    }
};