//#include"bits/stdc++.h"
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
int dx[]={0,0,1,-1,0};
int dy[]={1,-1,0,0,0};
vector<vector<int>> vec; // 最大限度
vector<vector<int>> dis; // 实际到达的时间
const int INF = 10000;

// dfs要使用的变量
int ans;
int maxt;

/*
这道题目求最短，要使用BFS,而不是DFS。
之前以为同样可以使用DFS进行求解，但是不可以，原因如下：
1. 如果进行暴力求解，则时间复杂度太高，因为每个节点会被遍历多次
2. 如果对节点进行vis标记，即如果访问过就不再访问了。这个没有办法保证是最短

结论：DFS其实很暴力，它只能用来告诉我们是否有可行解，但是不能保证拿到最优解。如果用全局变量来维持最小值，恐怕都是超时的。
*/

int  bfs(){
    if(vec[0][0]==0) return -1;  // 上来就被炸了
    if(vec[0][0]==INF) return 0; // 本来就是安全点
    queue<pii> q;
    dis[0][0]=0;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pii &p=q.front();
        q.pop();
        int x=p.first;
        int y=p.second;
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];

            if(xx<0 || xx>=410 || yy<0 || yy>=410) continue;
            if(vec[xx][yy]==INF) return dis[x][y]+1;
            if(vec[xx][yy]<=dis[x][y]+1) continue;
            if(dis[xx][yy]!=-1) continue;

            dis[xx][yy]=dis[x][y]+1;
            q.push(make_pair(xx,yy));
        }
    }
    return -1;
}



void dfs(int x, int y, int move){
//    cout<<x<<" "<<y<<" "<<move<<endl;
    if(move>maxt) return;
//    if(vec[x][y]==0){
////        cout<<"ans:"<<x<<" "<<y<<" "<<" "<<move<<endl;
//        ans=min(ans,move);
//        return ;
//    }

    vec[x][y]=maxt;
    for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
//        if(x==0 && y==4) cout<<xx<<" "<<yy<<" "<<vec[xx][yy]<<endl;
        if(xx<0 || xx>=310 || yy<0 || yy>=310 ) continue;
        if(vec[xx][yy]==0){
            ans=min(ans,move+1);
            return ;
        }
        if(move+1>=vec[xx][yy]) continue;
        dfs(xx,yy,move+1);
    }
}


int main(){
    int M;
    while(cin>>M, M!=0) {
        vec.clear();
        vec.resize(410,vector<int>(410,INF));
        dis.clear();
        dis.resize(410,vector<int>(410,-1));

        int x,y,t;
        for(int m=0;m<M;m++){
            cin>>x>>y>>t;
            for(int k=0;k<5;k++){
                int xx=x+dx[k];
                int yy=y+dy[k];
                if(xx<0 || xx>=310 || yy<0 || yy>=310) continue;
                vec[xx][yy]=min(vec[xx][yy],t);
            }
        }

//        for(int i=0;i<10;i++){
//            for(int j=0;j<10;j++){
//                cout<<vec[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<maxt<<endl;

        cout<<bfs()<<endl;
        return 0;
    }





}
