/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path = vector<int>(nums.size());
        vis = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int> &nums, int u)
    {
        if(u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                if(i && nums[i - 1] == nums[i] && !vis[i - 1]) continue;
                path[u] = nums[i];
                vis[i] = true;
                dfs(nums, u + 1);
                vis[i] = false;
            }
        }
    }
};
// @lc code=end

