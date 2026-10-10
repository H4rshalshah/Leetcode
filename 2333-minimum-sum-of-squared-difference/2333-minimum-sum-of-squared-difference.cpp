class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int max_d = 0;
        
        std::vector<int> diffs(n);
        for (int i = 0; i < n; ++i) {
            diffs[i] = std::abs(nums1[i] - nums2[i]);
            max_d = std::max(max_d, diffs[i]);
        }
        
        if (max_d == 0) return 0;
        
        std::vector<long long> count(max_d + 1, 0);
        for (int d : diffs) {
            count[d]++;
        }
        
        long long k = (long long)k1 + k2;
        
        for (int d = max_d; d > 0; --d) {
            if (count[d] == 0) continue;
            
            if (k >= count[d]) {
                k -= count[d];
                count[d - 1] += count[d];
                count[d] = 0;
            } else {
                count[d - 1] += k;
                count[d] -= k;
                k = 0;
                break;
            }
        }
        
        long long ans = 0;
        for (long long d = 1; d <= max_d; ++d) {
            ans += d * d * count[d];
        }
        
        return ans;
    }
};