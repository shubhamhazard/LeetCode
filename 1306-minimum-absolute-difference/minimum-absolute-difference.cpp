class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i=1;i<arr.size(); i++)
        {
            if((arr[i] - arr[i-1]) < diff)
                {
                    diff = arr[i] - arr[i-1];
                }
        }
        vector<int> ans;
        vector<vector<int>> res;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i] - arr[i-1] == diff)
            {
                ans.push_back(arr[i-1]);
                ans.push_back(arr[i]);
                res.push_back(ans);
                ans.clear();
            }
        }
        return res;
    }
};