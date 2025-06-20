class Solution {
public:
    int maxDistance(string S, int k) {
        int n=0,s=0,w=0,e=0,maxdist=0,min1=0,min2=0,m=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='N') n++;
            else if(S[i]=='S') s++;
            else if(S[i]=='W') w++;
            else e++;
            min1=min(n,s);
            min2=min(e,w);
            m=min(k,min1+min2);

            int currDist = abs(w-e) + abs(n-s);
            maxdist=max(maxdist, currDist + 2*m);
        }
        return maxdist;
        
    }
};