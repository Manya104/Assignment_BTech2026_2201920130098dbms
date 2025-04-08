class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int steps = 0;

        while (true) {
            map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            bool allUnique = true;
            for (auto& pair : freq) {
                if (pair.second > 1) {
                    allUnique = false;
                    break;
                }
            }

            if (allUnique) break;

            int toRemove = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + toRemove);
            steps++;
        }

        return steps;
    }
};