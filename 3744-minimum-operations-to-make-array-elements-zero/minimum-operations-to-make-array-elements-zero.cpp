class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            ans += (getOps(r) - getOps(l - 1) + 1) / 2;
        }
        return ans;
    }

private:
    long long getOps(long long n) {
        long long res = 0;
        long long ops = 0;
        for (long long power = 1; power <= n; power *= 4) {
            long long l = power;
            long long r = min(n, power * 4 - 1);
            res += (r - l + 1) * (++ops);
        }
        return res;
    }
};
