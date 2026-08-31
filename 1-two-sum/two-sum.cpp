/*
Approach:
Use an unordered_map to store value -> index.
For each nums[i], check whether target - nums[i] has already appeared.
If yes, return the two indices.

Alternative: Brute force checks every pair in O(n^2).

Time: O(n)
Space: O(n)
*/

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];

            if (mp.count(x))
            return {mp[x], i};

            mp[nums[i]] = i;
        }

        return {};
    }
};
       