class Solution {
public:
    void solve(vector<int>& nums, int index,
               vector<int>& output,
               vector<vector<int>>& ans) {

        // Base case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Exclude current element
        solve(nums, index + 1, output, ans);

        // Include current element
        output.push_back(nums[index]);

        solve(nums, index + 1, output, ans);

        // Backtracking
        output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(nums, 0, output, ans);

        return ans;
    }
};