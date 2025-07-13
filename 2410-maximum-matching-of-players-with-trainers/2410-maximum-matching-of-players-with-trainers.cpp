class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        // Sort players and trainers to allow greedy matching
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

        int i = 0; // pointer for players
        int j = 0; // pointer for trainers
        int c = 0; // match count

        // Try to match players with trainers one by one
        while (i < p.size() && j < t.size()) {
            if (p[i] <= t[j]) {
                // Player i matched with trainer j
                c++;
                i++;
                j++;
            } 
            else {
                // Trainer j can't train player i, try next trainer
                j++;
            }
        }

        // Return the total number of successful matchings
        return c;
    }
};