class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //sort array 
         sort(folder.begin(), folder.end());
        vector<string> result;
        //loop folder array 
        for (int i = 0; i < folder.size(); i++)
        {
            //push first folder in vector
            result.push_back(folder[i]);
            //udse other index to compare rest of folder
            int j=i+1;
            //woth in currenr array size if folder j size> folder i siz && folder j substru is same as folder i si
              while (j < folder.size() &&
                   folder[j].size() > folder[i].size() &&
                   folder[j].substr(0, folder[i].size()) == folder[i] &&
                   folder[j][folder[i].size()] == '/')
                   {
                    ++j;
                   }

                   i=j-1;


        }
return result;
        
    }
};