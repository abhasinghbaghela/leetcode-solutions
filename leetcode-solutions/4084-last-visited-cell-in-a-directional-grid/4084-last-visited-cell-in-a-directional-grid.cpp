class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int i=0;
        int j=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans(2);
        while(i>=0 && i<m && j>=0 && j<n && grid[i][j]!='V'){
            int ip=i;
            int jp=j;
            if(grid[i][j]=='L'){
                j=j-1;
            }else if(grid[i][j]=='R'){
                j=j+1;
            }else if(grid[i][j]=='D'){
                i=i+1;
            }else{
                i=i-1;
            }
            grid[ip][jp]='V';
            ans[0]=ip;
            ans[1]=jp;
        }
        return ans;
    }
};