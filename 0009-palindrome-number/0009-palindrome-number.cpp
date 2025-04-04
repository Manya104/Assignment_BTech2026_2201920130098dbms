class Solution {
public:
    bool isPalindrome(int x) {
        int temp = 0;
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        while (x > temp) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        if (x == temp || x == temp / 10) {
            return true;
        }
        return false;
    }
};