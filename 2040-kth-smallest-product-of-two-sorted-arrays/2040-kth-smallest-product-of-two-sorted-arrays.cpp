class Solution {
public:

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10;
        long long high = 1e10;
        while(low < high){
            long long mid = low + (high - low)/2;
            if(products(nums1,nums2,mid) < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    long long products(vector<int>& nums1, vector<int>& nums2, long long target){
        long long count = 0;
        int n = nums1.size();
        int m = nums2.size();
        for(int num1 : nums1){
            if(num1 == 0){
                if(target >= 0) count = count + m;
                continue;
            }
            int low = 0;
            int high = m;
            while(low < high){
                int mid = low + (high - low)/2;
                long long multiply = 1LL*num1*nums2[mid];
                if(multiply <= target){
                    if(num1 > 0) low = mid + 1;
                    else high = mid;
                }
                else{
                    if(num1 > 0) high = mid;
                    else low = mid + 1;
                }
            }
            count += (num1 > 0) ? low : (m-low);
        }
        return count;
    }

};