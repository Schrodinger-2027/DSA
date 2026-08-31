class Solution {
public:

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> v;
        int i = l, j = m + 1;

        while(i <= m && j <= r) {
            if(nums[i] <= nums[j]) {
                v.push_back(nums[i]);
                i++;
            }
            else {
                v.push_back(nums[j]);
                j++;
            }
        }

        while(i <= m) {
            v.push_back(nums[i]);
            i++;
        }

        while(j <= r) {
            v.push_back(nums[j]);
            j++;
        }

        for(int i = l; i <= r; i++)
        nums[i] = v[i - l];
    }
       
    int solve(vector<int>& nums, int l, int r) {
        if(l >= r){
            return 0;
        }

        int m = (l + r) / 2;

        int ans = solve(nums, l, m);
        ans += solve(nums, m + 1, r);

        int j = m + 1;

        for(int i = l; i <= m; i++) {
            while(j <= r && nums[i] > 2LL * nums[j])
            j++;

            ans += j - (m + 1);
        }

        merge(nums, l, m, r);

        return ans;
    }


    

    int reversePairs(vector<int>& nums) {
       
       return solve(nums , 0 , nums.size() - 1);
    }
};