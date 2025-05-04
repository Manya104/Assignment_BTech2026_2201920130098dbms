class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0};
        int totalPairs = 0;

        // Loop through each domino in the input list
        for (int i = 0; i < dominoes.size(); i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];

            // Sort the domino so that smaller number is always first
            // This helps to treat [2,1] and [1,2] as the same
            int key;
            if (a < b)
                key = a * 10 + b;
            else
                key = b * 10 + a;

            // Add the current count of this domino to total pairs
            totalPairs += count[key];

            // Increment the count for this domino
            count[key]++;
        }
        // Return the total number of equivalent domino pairs
        return totalPairs;
    }
};