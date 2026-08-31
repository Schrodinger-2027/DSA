class Solution {
public:
    int solve(int n) {
        if (n <= 2) {
            return n;
        }
        int prev = 1;
        int curr = 2;

        for (int i = 3; i <= n; i++) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
    int climbStairs(int n) {
        return solve(n);    
    }
};