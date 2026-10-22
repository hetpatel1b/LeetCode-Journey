
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int s = nums[0];
        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (s + i) % n)
                inc = false;

            if (nums[i] != (s - i + n) % n)
                dec = false;
        }

        if (inc) {
            int k = (n - s) % n;
            return min(k, n - k + 2);
        }

        if (dec) {
            int a = (s + 1) % n;
            int k = (n - a) % n;
            return 1 + min(k, n - k);
        }

        return -1;
    }
};
