
class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<long long>> c;

    long long solve(vector<int>& a) {
        int n = a.size();
        if (n <= 2) return 1;

        vector<int> l, r;

        for (int i = 1; i < n; i++) {
            if (a[i] < a[0])
                l.push_back(a[i]);
            else
                r.push_back(a[i]);
        }

        long long x = solve(l);
        long long y = solve(r);

        return c[n - 1][l.size()] * x % MOD * y % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        c.assign(n + 1, vector<long long>(n + 1, 1));

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                c[i][j] = (c[i - 1][j - 1] +
                           c[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};
