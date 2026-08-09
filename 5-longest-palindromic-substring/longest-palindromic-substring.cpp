class Solution {
public:
    string longestPalindrome(string s) {

        if(s.size() == 1) return s;
        
        string t = "@#";
        for(int i = 0 ; i < s.size() ; ++i){
            t.push_back(s[i]);
            t.push_back('#');
        }
        t.push_back('$');

        int n = t.size();

        vector<int> radius(n , 0);
        int center = 0;
        int right = 0;
        
        for(int i = 1 ; i < n - 1 ; ++i){
            int mirror = 2 * center - i;

            if(i < right){
                radius[i] = min(radius[mirror] , right - i);
            }
            while(t[i + radius[i] + 1] == t[i - radius[i] - 1]){
                radius[i]++;
            }
            if(i + radius[i] > right){
                center = i;
                right = i + radius[i];
            }
        }

        int idx = 0;
        int maxLen = 0;

        for(int i = 0 ; i < n ; ++i){
            if(radius[i] > maxLen){
                idx = i ;
                maxLen = radius[i];
            }
        }
        int start = (idx - maxLen) / 2;
        
        return s.substr(start , maxLen);
    }
};