class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> bitExpire(30, -1); 
        int nextExpire = n; 

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 30; ++bit) {
                if (nums[i] & (1 << bit)) {
                    bitExpire[bit] = i;
                }
            }

            nextExpire = i;
            for (int bit = 0; bit < 30; ++bit) {
                if (bitExpire[bit] != -1) {
                    nextExpire = max(nextExpire, bitExpire[bit]);
                }
            }

            result[i] = nextExpire - i + 1;
        }

        return result;
    }
};
