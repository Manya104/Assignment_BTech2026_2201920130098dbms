#define ll long long
#define MX 15000LL      // MX should be around 30000, since sqrt(1e9) = 31622, but they just won't let me make this big

class Solution {
public:
    const ll M = (ll)(1e9)+7;

    struct state{
        int cnt[26]={0};
    };

    state add1(state& cur, vector<int> &nums){
        state ans;
        for (int i=0; i<26; i++){
            int mul = cur.cnt[i];
            if (!mul) continue;
            int end = i+nums[i]+1;
            if (i+nums[i]<26){
                ans.cnt[i+1] += mul;
                ans.cnt[i+1] %= M;
                if (i+nums[i]+1 < 26){
                    ans.cnt[end] -= mul;
                    ans.cnt[end] %= M;
                }
            }
            else{
                // (i+1, 25), (0, i+nums[i])
                end%=26;
                if (i+1 < 26){
                    ans.cnt[i+1] += mul;
                    ans.cnt[i+1] %= M;
                }
                ans.cnt[0] += mul;
                ans.cnt[0] %= M;
                ans.cnt[end] -= mul;
                ans.cnt[end] %= M;
            }
        }
        for (int i=1; i<26; i++){
            ans.cnt[i] += ans.cnt[i-1];
            ans.cnt[i] %= M;
        } 
        return ans;
    }

    state add(state &cur, state pre[][MX+1], int t){
        state ans;
        for (int i=0; i<26; i++){
            ll mul = cur.cnt[i];
            if (!mul) continue;
            for (int j=0; j<26; j++){
                // each char i changed to val many of char j
                ll val = pre[i][t].cnt[j];
                ans.cnt[j] += val * mul % M;
                ans.cnt[j] %= M;
            }
        }
        return ans;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        state pre[26][MX+1];
        int SQMX = min((int)(sqrt(t))+1, (int)(MX));
        for (int i=0; i<26; i++){
            pre[i][0].cnt[i] = 1;
            for (int j=1; j<=SQMX; j++){
                pre[i][j] = add1(pre[i][j-1], nums);
            }
        }

        state ans_state;
        for (char ch : s)
            ans_state.cnt[ch-'a']++;
        while (t>0){
            int ct = min(SQMX, t);
            ans_state = add(ans_state, pre, ct);
            t -= ct;
        }
        int ans=0;
        for (int i=0; i<26; i++){
            ans += ans_state.cnt[i];
            ans %= M;
        }
        return (ans%M+M)%M;
    }
};