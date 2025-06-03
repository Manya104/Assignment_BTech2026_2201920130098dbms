class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,  unordered_set<int> &visited,
        unordered_set<int> &foundBoxes){
            
            if(visited.count(box)){//current box is already visited
                return 0;
            }
            if(status[box] == 0){
                foundBoxes.insert(box);
                return 0;//box is closed
            }
            visited.insert(box);
            int candiesCollected = candies[box];//collect the candies from inside this box

            for(int &insideBox : containedBoxes[box]){//check how many boxes are inside this box
                candiesCollected += dfs(insideBox, status, candies, keys, containedBoxes, visited,  foundBoxes);
                
            }

            for(int &boxKey : keys[box]){
                status[boxKey] = 1;// set status of that box as 1 since key is found
                if (foundBoxes.count(boxKey)){//only if we have encountered this box before
                    candiesCollected += dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes);
                }
            }
            return candiesCollected;

    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;//boxes which have been found but their keys have not been found yet

        for(int &box : initialBoxes){
            candiesCollected += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);

        }
        return candiesCollected;
    }
};