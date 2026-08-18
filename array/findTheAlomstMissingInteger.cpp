class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        vector<int> count(51, 0);

        int n = nums.size();

        // Every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            set<int> st;

            // Elements inside this subarray
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // This number appeared in one more subarray
            for (int x : st) {
                count[x]++;
            }
        }

        int ans = -1;

        // Find largest number appearing in exactly 1 subarray
        for (int x = 0; x <= 50; x++) {

            if (count[x] == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};