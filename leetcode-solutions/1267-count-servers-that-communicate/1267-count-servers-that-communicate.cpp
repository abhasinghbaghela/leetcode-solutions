class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(grid[x][y]==2){
                continue;
            }else{
                bool flg=false;
                for(int i=0;i<m;i++){
                    if( i!=x && (grid[i][y]==1 || grid[i][y]==2)){
                        grid[i][y]=2;
                        flg=true;
                    }
                }
                for(int i=0;i<n;i++){
                    if(i!=y && (grid[x][i]==1 || grid[x][i]==2)){
                        grid[x][i]=2;
                        flg=true;
                    }
                }
                if(flg){
                    grid[x][y]=2;
                }else{
                    grid[x][y]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    ans++;
                }
            }
        }
        return ans;
    }
};