class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        int cnt=0;
        stack<pair<int,int>>st;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }      
                long long sum = 0;
                st.push({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;
                while(!st.empty()){
                    int r=st.top().first;
                    int c=st.top().second;
                    st.pop();
                    for(int i=0;i<4;i++){
                        int newr=r+dir[i][0];
                        int newc=c+dir[i][1];
                        if(newr >= 0 && newr < n &&
                            newc >= 0 && newc < m &&
                            grid[newr][newc] !=0) {
                            sum += grid[newr][newc];
                            grid[newr][newc] = 0;
                            st.push({newr, newc});
                        }
                    }
                }
                if(sum%k==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};