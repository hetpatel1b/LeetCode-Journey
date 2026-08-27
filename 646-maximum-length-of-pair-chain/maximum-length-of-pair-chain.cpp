class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        // Sort pairs by their ending value
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int answer = 0;
        int last = -1001;  // Smaller than minimum possible value

        // Check every pair
        for (auto pair : pairs) {
            
            // Current pair can be added to the chain
            if (pair[0] > last) {
                answer++;
                last = pair[1];
            }
        }

        return answer;
    }
};