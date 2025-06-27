class Solution {
public:
string result="";
bool isSubsequence(string& s, string& sub, int k){
    int i=0, j=0;
    int L=sub.length();
    int n=s.length();
    while(i<n && j<L*k){
        if(s[i]==sub[j%L]){
            j++;
        }
        i++;
    }
    return j==k*L;
}
bool backtracking(string& s, string& curr, vector<bool>&canUse, vector<int>&requiredFreq, int k, int maxLen){
    if(curr.length()==maxLen){
        if(isSubsequence(s,curr,k)){
            result=curr;
            return true;
        }
        return false;
    }
    for(int i=25;i>=0;i--){
        if(canUse[i]==false || requiredFreq[i]==0){
            continue;
        }
        char ch=i+'a';
        curr.push_back(ch);
        requiredFreq[i]--;
        if(backtracking(s, curr, canUse, requiredFreq, k, maxLen)){
            return true;
        }
        curr.pop_back();
        requiredFreq[i]++;
    }
    return false;
}
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        int freq[26]={};
        for(char& ch:s){
            freq[ch-'a']++;
        }
        vector<bool>canUse(26,false);
        vector<int>requiredFreq(26,0);
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
                canUse[i]=true;
                requiredFreq[i]=freq[i]/k;
            }
        }
        int maxLen=n/k;
        for(int l=maxLen;l>=0;l--){
            vector<int>tempRequiredFreq=requiredFreq;
            string curr="";
            if(backtracking(s, curr, canUse, tempRequiredFreq, k, l)){
                return result;
            }
        }
        return result;
    }
};