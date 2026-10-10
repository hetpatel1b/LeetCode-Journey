
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<long long> diff(n);
        long long maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        // Binary search for the minimum achievable maximum difference
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long operations = 0;

            for (long long d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long level = low;
        long long operations = 0;
        long long ans = 0;
        long long count = 0;

        for (long long d : diff) {
            if (d > level) {
                operations += d - level;
                ans += level * level;
                count++;
            } else {
                ans += d * d;
            }

            if (d >= level) {
                count += 0; // Count is handled below.
            }
        }

        // Operations still available after reaching 'level'
        long long remaining = k - operations;

        if (level == 0) {
            return 0;
        }

        // Count all differences that can now be reduced from
        // 'level' to 'level - 1'.
        count = 0;
        for (long long d : diff) {
            if (d >= level) {
                count++;
            }
        }

        // Each reduction from level to level - 1 saves 2*level - 1
        ans -= remaining * (2 * level - 1);

        return ans;
    }
};
