class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_to_color;  // Maps each ball to its current color
        unordered_set<int> distinct_colors;  // Stores all distinct colors
        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            // If the ball already has a color, check if it was unique
            if (ball_to_color.find(ball) != ball_to_color.end()) {
                int old_color = ball_to_color[ball];

                // Remove old color if it's no longer used
                bool still_exists = false;
                for (const auto& [key, val] : ball_to_color) {
                    if (val == old_color && key != ball) {
                        still_exists = true;
                        break;
                    }
                }
                if (!still_exists) {
                    distinct_colors.erase(old_color);
                }
            }

            // Assign new color to the ball
            ball_to_color[ball] = color;
            distinct_colors.insert(color);

            // Store the result
            ans[i] = distinct_colors.size();
        }

        return ans;
    }
};
