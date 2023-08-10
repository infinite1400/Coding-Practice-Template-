#include<bits/stdc++.h>
using namespace std;
int dirx[] = { 0, 1, 0, -1 };
int diry[] = { -1, 0, 1, 0 };
int dfs1(vector<vector<char>> &grid,vector<vector<int>> &vis,int sr,int sc){
    int ans=1e9;
    vis[sr][sc]=1;
    if(sr==grid.size()-1 && sc==grid[0].size()-1) return 0;
    for(int i=1;i<=2;i++){
        int x=dirx[i]+sr;
        int y=diry[i]+sc;
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && vis[x][y]==0 && (grid[x][y]=='*' || grid[x][y]=='.')){
            ans=min(ans,1+dfs1(grid,vis,x,y));
        }
    }
    return ans;
    
}
int dfs2(vector<vector<char>> &grid,vector<vector<int>> &vis,int sr,int sc){
    int ans=1e9;
    vis[sr][sc]=1;
    if(sr==grid.size()-1 && sc==grid[0].size()-1) return 0;
    for(int i=1;i<=2;i++){
        int x=dirx[i]+sr;
        int y=diry[i]+sc;
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && vis[x][y]==0 && (grid[x][y]=='#' || grid[x][y]=='.')){
            ans=min(ans,1+dfs2(grid,vis,x,y));
        }
    }
    return ans;
    
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis2(n,vector<int>(m,0));
    int x=dfs2(grid,vis2,0,0);
    if(x==1e9) x=-1;
    cout<<x<<endl;
    vector<vector<int>> vis1(n,vector<int>(m,0));
     int y=dfs1(grid,vis1,0,0);
    if(y==1e9) y=-1;
    cout<<y<<endl;
    
    return 0;
}
