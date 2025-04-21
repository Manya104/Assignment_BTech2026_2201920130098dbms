class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0; // long long to avoid integer overflow
        long long maxPrefix = 0, minPrefix = 0;

        // Calculate prefix sums and track the maximum and minimum values
        for (int difference : differences) {
            prefix += difference;
            maxPrefix = max(maxPrefix, prefix);
            minPrefix = min(minPrefix, prefix);
        }

        // Calculate valid start and end bounds
        long long start = lower - minPrefix;
        long long end = upper - maxPrefix;

        // If the range is invalid, return 0
        return (start > end) ? 0 : end - start + 1;
    }
};