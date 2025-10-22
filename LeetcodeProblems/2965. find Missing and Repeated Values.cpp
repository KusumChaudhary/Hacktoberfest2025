class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        vector<int> sub(total + 1, 0); 
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sub[grid[i][j]]++;
            }
        }

        int repeating = -1, missing = -1;
        for (int i = 1; i <= total; i++) {
            if (sub[i] == 0) missing = i;
            if (sub[i] > 1) repeating = i;
        }

        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};
