class Solution {
public:
    int sumCounts(vector<int>& nums) {
       int n = nums.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; ++i) {
            bitset<101> seen;
            int distinctCount = 0;
            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) {
                    seen.set(nums[j]);
                    distinctCount++;
                }
                totalSum += distinctCount * distinctCount;
            }
        }
        
        return totalSum; 
    }
};