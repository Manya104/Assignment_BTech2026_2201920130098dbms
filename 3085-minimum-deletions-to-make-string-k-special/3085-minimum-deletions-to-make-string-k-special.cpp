class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mpp;
        for(int i=0;i<word.length();i++){
            mpp[word[i]]++;
        }
        vector<int>v;
        for(auto it:mpp){
            if(it.second!=0){
                v.push_back(it.second);
            }
        }
        sort(v.begin(),v.end());
        vector<int>presum(v.size(),0);
        presum[0]=v[0];
        for(int i=1;i<v.size();i++){
            presum[i]=presum[i-1]+v[i];
        }
        int prev=0;
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            if(i>0 &&v[i-1]==v[i]){
                continue;
            }
            if(i>0){
                prev=presum[i-1];
            }
            int ind=upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
            int remove=prev+presum[v.size()-1]-presum[ind-1]-(v[i]+k)*(v.size()-ind);
            ans=min(ans,remove);
        }
        return ans;
    }
};