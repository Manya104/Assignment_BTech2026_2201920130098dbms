class Solution {
    long long numPIUpto(long long ub, int limit, string &s) {
        if (s.empty()) {
            if (ub<10) {
                return 1+min((long long)limit,ub);
            }
            if (limit<=ub%10) {
                return numPIUpto(ub/10,limit,s)*(limit+1);
            }
            return numPIUpto(ub/10, limit, s)*(ub%10+1)+numPIUpto(ub/10-1, limit, s)*(limit-ub%10);
        }
        if (ub==0) return 0;
        char lastc = s.back();
        int lastd = lastc-'0';
        s.pop_back();
        if (lastd>limit) {
            return 0;
        }
        long long ans = 0;
        if (lastd<=ub%10) {
            ans =  numPIUpto(ub/10, limit, s);
        }else {
            ans = numPIUpto(ub/10-1, limit, s);
        }
        s.push_back(lastc);
        return ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return numPIUpto(finish, limit, s)- numPIUpto(start-1, limit, s);
    }
};