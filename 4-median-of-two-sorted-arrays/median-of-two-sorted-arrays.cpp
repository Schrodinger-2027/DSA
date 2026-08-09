class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size()){
            swap(nums1 , nums2);
        }   

        int n = nums1.size();
        int m = nums2.size();

        int k = (m + n + 1) / 2;

        int l = 0 ;
        int r = n ;

        while(l <= r){
            int mid = l + (r - l) / 2;

            int cut1 = mid;
            int cut2 = k - mid;

            int l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            int r1 = (cut1 == n ? INT_MAX : nums1[cut1]);
            int l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
            int r2 = (cut2 == m ? INT_MAX : nums2[cut2]);

            if(l1 <= r2 && l2 <= r1){
                double ans = max(l1 , l2);

                if((m + n) % 2 == 1) return ans;

                ans += min(r1 , r2);

                return ans / 2.0;
            }
            else if(l1 > r2){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return 0;
    }
};