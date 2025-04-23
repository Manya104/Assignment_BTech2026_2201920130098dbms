class Solution {
public:
    int countLargestGroup(int n) {
        
        unordered_map<int,int> mp;
        for(int i = 1; i <= n; i++) {

            int tmp = i;
            int sum = 0;
            while(tmp) {
                sum += (tmp%10);
                tmp /= 10;  
            }

            mp[sum]++;
        }

        int mxSize = 0;
        int mxCnt = 0;
        for(auto it: mp) {
            if(it.second > mxSize) {
                mxSize = it.second;
                mxCnt = 1;
            }
            else if(it.second == mxSize) {
                mxCnt++;
            }
        }

        return mxCnt;
    }
};