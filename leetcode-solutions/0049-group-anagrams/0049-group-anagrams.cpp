
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string, int>> v;
        vector<string> temp = strs;
        for (int i = 0; i < n; i++) {
            sort(temp[i].begin(), temp[i].end());
            v.push_back({temp[i], i});
        }
        sort(v.begin(), v.end());
        vector<vector<string>> ans;
        for (int i = 0; i < v.size(); i++) {
            if (i == 0 || v[i].first != v[i - 1].first) {
                ans.push_back({});
            }
            ans.back().push_back(strs[v[i].second]);
        }
        return ans;
    }
};
