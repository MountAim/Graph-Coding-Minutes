#include<bits/stdc++.h>
using namespace std;

int m,n;
vector<vector<int>> g;
vector<vector<int>> dir={{0,-1},{-1,-1},{1,-1},{0,1},{-1,1},{1,1}};
int S,T;
int flow;

void bfs(vector<int> &pre){
    queue<int> q;
    q.push(S);
    vector<int> visited(m*n+2,0);
    visited[S]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<m*n+2;++i){
            if(visited[i]==0 && g[cur][i]==1){
                visited[i]=1;
                q.push(i);
                pre[i]=cur;
            }
        }
    }
}
void EK(){
    while(true){
        vector<int> pre(m*n+2,-1);
        bfs(pre);
        if(pre[T]==-1) break;
        int v=T;
        while(true){
            int u=pre[v];
            g[u][v]--;
            g[v][u]++;
            v=u;
            if(v==S) break;
        }
        flow++;
    }
}

int maxStudents(vector<vector<char>> seats) {
    m=seats.size();
    n=seats[0].size();
    S=m*n;
    T=m*n+1;
    g=vector<vector<int>>(m*n+2,vector<int>(m*n+2,0));  // residual capacity 
    int seatcnt=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(seats[i][j]=='#') continue;
            seatcnt++;
            if(j%2==0){
                g[S][i*n+j]=1;
                for(int d=0;d<6;++d){
                    int ni=i+dir[d][0];
                    int nj=j+dir[d][1];
                    if(ni<0 || ni>=m || nj<0 || nj>=n || seats[ni][nj]=='#') continue;
                    g[i*n+j][ni*n+nj]=1;
                }
            }else{
                g[i*n+j][T]=1;
            }
        }
    }
    flow=0;
    EK();
    return seatcnt-flow;
}
