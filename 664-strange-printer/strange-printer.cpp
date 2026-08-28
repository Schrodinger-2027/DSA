class Solution {
public:

    vector<vector<int>> dp;

    int findans(int i , int j , string& s){

        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int n = s.size();

        int ans = 1 + findans(i + 1 , j , s);

        for(int k = i + 1 ; k <= j ; ++k){
            if(s[i] == s[k]){
                ans = min(ans , findans(i + 1 , k - 1 , s) + findans(k , j , s));
            }
        }
       

        dp[i][j] = ans;

        return dp[i][j];
    }
    int strangePrinter(string s) {
        
        int n = s.size();

        dp.assign(n , vector<int>(n , -1));

        return findans(0 , n - 1 , s);
    }
};