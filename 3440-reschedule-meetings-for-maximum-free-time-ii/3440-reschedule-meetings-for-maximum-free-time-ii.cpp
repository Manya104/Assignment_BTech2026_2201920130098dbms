class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTimes;
        freeTimes.push_back(-1); // Sentinel for prefix/suffix safety

        // Calculate gaps between meetings (free times)
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                freeTimes.push_back(startTime[i]);
            else
                freeTimes.push_back(startTime[i] - endTime[i - 1]);

            if (i == n - 1)
                freeTimes.push_back(eventTime - endTime[i]);
        }

        freeTimes.push_back(-1); // Sentinel at the end
        int len = freeTimes.size();

        // Compute prefix max and suffix max
        vector<int> prefixMax(len + 1, 0), suffixMax(len + 2, 0);
        for (int i = 1; i < len; ++i)
            prefixMax[i] = max(prefixMax[i - 1], freeTimes[i]);
        for (int i = len - 1; i >= 1; --i)
            suffixMax[i] = max(suffixMax[i + 1], freeTimes[i]);

        int maxFree = 0, windowSize = 2;
        int i = 1, j = 1, currSum = 0;

        while (j <= len - 2) {
            if (j - i + 1 < windowSize) {
                currSum += freeTimes[j++];
                continue;
            }

            currSum += freeTimes[j];
            int duration = endTime[i - 1] - startTime[i - 1];

            // Check if the current meeting can be rescheduled to a bigger gap
            if (prefixMax[i - 1] >= duration || suffixMax[j + 1] >= duration)
                maxFree = max(maxFree, currSum + duration);
            else
                maxFree = max(maxFree, currSum);

            currSum -= freeTimes[i++];
            ++j;
        }

        return maxFree;
    }
};