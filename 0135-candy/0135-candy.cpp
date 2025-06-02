class Solution {
public:

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1){
            return 1;
        }

        vector<pair<int, int>> sorted(n); // val, index
        for(int i=0; i<n; i++){
            sorted[i] = {ratings[i], i};
        }
        sort(sorted.begin(), sorted.end());

        vector<int> candies(n, 1);

        int total = 0;
        for(int i=0; i<n; i++) {
            int val = sorted[i].first;
            int index = sorted[i].second;

            if(index > 0 && ratings[index-1] < ratings[index]){
                candies[index] = max(candies[index], candies[index-1] + 1);
            }
            if(index < n-1 && ratings[index+1] < ratings[index]){
                candies[index] = max(candies[index], candies[index+1] + 1);
            }
            total += candies[index];
        }

        return total;
    }
};