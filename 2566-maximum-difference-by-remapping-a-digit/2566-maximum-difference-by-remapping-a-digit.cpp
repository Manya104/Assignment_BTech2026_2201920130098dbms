class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int max_val = num;
        int min_val = num;

       
        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp) {
                if (c == d) c = '9';
            }
            max_val = max(max_val, stoi(temp));
        }

       
        for (char d = '0'; d <= '9'; ++d) {
            string temp = s;
            for (char& c : temp) {
                if (c == d) c = '0';
            }
            min_val = min(min_val, stoi(temp));
        }

        return max_val - min_val;
    }
};