class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int maxCandies = min(n, limit);
        int minCandies = max(0, n - 2 * limit);
        long long result = 0;
        for (int i = minCandies; i <= maxCandies; ++i) {
            int range = min(n - i, limit) - max(0, n - i - limit) + 1;
            result += range;
        }
        return result;
    }
};