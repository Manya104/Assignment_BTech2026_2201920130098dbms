class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long n = 1;
        int operIndex = -1;
        while (n < k) {
            n <<= 1;
            operIndex++;
        }
        return backtrack(n, k, operations, operIndex);
    }
    char backtrack(long long n, long long k, vector<int> &operations, int operIndex) {
        if (n == 1) {
            return 'a';
        }
        if (k > n / 2) {
            int shift = operations[operIndex];
            return 'a' + (backtrack(n / 2, k - n / 2, operations, operIndex - 1) - 'a' + shift) % 26;
        }
        else {
            return backtrack(n / 2, k, operations, operIndex - 1);
        }
    }
};