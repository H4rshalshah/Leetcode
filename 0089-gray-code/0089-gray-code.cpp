class Solution {
public:
    vector<int> grayCode(int n) {
        int count = 1 << n; // 2^n elements
        vector<int> result(count);
        for (int i = 0; i < count; ++i) {
            result[i] = i ^ (i >> 1);
        }
        return result;
    }
};