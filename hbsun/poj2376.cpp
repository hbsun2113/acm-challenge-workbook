#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include"math.h"
#include<set>
using namespace std;
typedef pair<int,int> pii;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<pii> vec(25010);
// 假设[1,p]已经被覆盖，我们现在的起点就是p+1。
// 我们要在后面的区间中找到所有起点可以覆盖到p+1,且终点最大的区间。
int main(){
    int N,T;
    scanf("%d%d", &N, &T);
    if(N==0){
        cout<<-1<<endl;
        return 0;
    }
    for(int n=0;n<N;n++) scanf("%d%d", &vec[n].first, &vec[n].second);
    sort(vec.begin(),vec.begin()+N);
    int ans=0;
    int end=1;
    int n=0;
    while(end<=T){
        int tmp=-1;
        while(n<N && vec[n].first<=end){
            tmp=max(tmp,vec[n].second);
            n++;
        }
        if(tmp==-1){
            cout<<-1<<endl;
            return 0;
        }
        else{
            ++ans;
            end=tmp+1;
            if(end>T){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    cout<<"failed"<<endl;
    return 0;
}