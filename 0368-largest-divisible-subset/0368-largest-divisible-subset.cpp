class Solution {
public:

    void backtrack( vector<int>& nums, vector<int>& ans, vector<int>& dp, int idx, int len )
    {
        ans.push_back( nums[idx] );
        if( len == 1 )
            return;
        for( int i = 0; i < idx; i++ )
            if( ( ( nums[i] % nums[idx] == 0 ) || ( nums[idx] % nums[i] == 0 ) ) && dp[i] == len - 1 )
            {
                backtrack( nums, ans, dp, i, len - 1 );
                break; // any one subset is fine
            }
        return;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort( nums.begin(), nums.end() ); // sort to make sure dp assumption works always
        int n = nums.size();
        vector<int> dp( n, 1 );

        // Find the largest subset size
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < i; j++ )
                if( ( nums[i] % nums[j] == 0 ) || ( nums[j] % nums[i] == 0 ) )
                    dp[i] = max( dp[i], 1 + dp[j] );

        // get index where largest subset ends to backtrack
        int len = 1, idx = 0;
        for( int i = 1; i < n; i++ )
            if( dp[i] > len )
                len = dp[i], idx = i;

        vector<int> ans;
        backtrack( nums, ans, dp, idx, len ); // backtrack
        return ans;
    }
};