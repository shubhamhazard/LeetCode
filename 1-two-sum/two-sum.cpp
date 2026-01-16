class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        vector<pair<int,int>> pairs;
        for(int i=0; i<nums.size(); i++)
        {
            pairs.push_back({nums[i],i});
        }

        sort(pairs.begin(), pairs.end());

        int start = 0;
        int end = pairs.size()-1;

        while(start < end)
        {
            int sum = pairs[start].first + pairs[end].first;
            if(sum == target)
                {
                    ans.push_back(pairs[start].second);
                    ans.push_back(pairs[end].second);
                    break;
                }
            else if(sum < target)
            {
                start++;
            }
            else
                end--;
        }

        return ans;
    }
};