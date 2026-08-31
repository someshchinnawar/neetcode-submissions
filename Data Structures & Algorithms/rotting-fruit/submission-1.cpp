class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //in queue is has the element position, with its time 
        //like (2,2), 0;
        //     (row,col),time;
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];

        //push rotten fruit into queue
        //and also mark that fruit as visited in the visited array
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        //bfs
        //each fruit can rotten in 4 direction 
        //rotten fruit(row,col) = upward(row-1,col) , right(row,col+1)
        //down(row+1,col) , left(row,col-1)
        // so neighbour row is like (row-1,row,row+1,row);
        //so neighbour col is like (col,col+1,col,col-1);
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int timeMin = 0;
        while(!q.empty()){
            //if element in queue is (2,1),0;
            //row is the first will give (2,1) and .first will give = 2
            //col is the first will give (2,1) and .second will give = 1
            //time front.second will give 0;
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            timeMin = max(timeMin,t);
            q.pop();
            
            //why 4 beacuse element are size of drow
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                        q.push({{nrow,ncol}, t+1});
                        vis[nrow][ncol] = 2;
                    }
            }
        }
        //if any one fresh furit is left then return -1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return timeMin;
    }
};
