#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include"math.h"
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const long long mod=1e9;

// 这个题目没有完全理解，按照起点排序和按照终点排序的区别到底是什么？



struct inter{
    int s,e,v;
    // 因为是要向前找离自己最近的时间段，且不和自己发生冲突的，所以按照尾部进行排序
    bool operator < (const inter &other) const {
//        return this->s<other.s;
        return this->e<other.e;

        // 如果这么写，就错了！
        if(this->s!=other.s) return this->s<other.s;
        else return this->e<other.e;
    }
};


//必须按照结尾排序
int main(){
    int N,M,R;
    cin>>N>>M>>R;
    if(M==0){
        cout<<0<<endl;
        return 0;
    }
    vector<inter> vec(M);
    for(int m=0;m<M;m++)
        cin>>vec[m].s>>vec[m].e>>vec[m].v;
    sort(vec.begin(),vec.end());

    vector<int> dp(M,0);  //在此时能拿到的最大值，可能包含当前区间，也可能不含当前区间
    dp[0]=max(0,vec[0].v);
    for(int m=1;m<M;m++){
        dp[m]=max(dp[m-1],vec[m].v);
        for(int j=0;j<m;j++){
            if(vec[j].e+R<=vec[m].s)
                dp[m]=max(dp[m],dp[j]+vec[m].v);
        }
    }
//    int ans=0;
//    for(int i=0;i<M;i++) ans=max(ans,dp[i]);
//    cout<<ans<<endl;
    cout<<dp[M-1]<<endl;
}

//必须按照结尾排序
int main2(){
    int N,M,R;
    cin>>N>>M>>R;
    vector<inter> vec(M);
    for(int m=0;m<M;m++)
        cin>>vec[m].s>>vec[m].e>>vec[m].v;
    sort(vec.begin(),vec.end());


    vector<int> dp1(M,0ll); // 选了   当前区间
    vector<int> dp2(M,0ll); // 没有选 当前区间
    dp1[0]=vec[0].v;
    dp2[0]=0;
    for(int m=1;m<M;m++){
        dp2[m]=max(dp1[m-1],dp2[m-1]);

        for(int j=0;j<m;j++){
            if(vec[j].e+R<=vec[m].s)
                dp1[m]=max(max(dp1[j],dp2[j]),dp1[m]);
        }
        dp1[m]+=vec[m].v;
        cout<<dp1[m]<<" "<<dp2[m]<<endl;
    }

    cout<<max(dp1[M-1],dp2[M-1])<<endl;
    return 0;
}



// 怎么排序都没有关系,
// 这种方法在最后还需要重新遍历一次dp，感觉不是很优雅
// 先不看
int main1(){
    int N,M,R;
    cin>>N>>M>>R;
    vector<inter> vec(M);
    for(int m=0;m<M;m++)
        cin>>vec[m].s>>vec[m].e>>vec[m].v;
    sort(vec.begin(),vec.end());

    vector<int> dp(M,0ll);  //选了当前区间，能拿到的最大值
    for(int m=0;m<M;m++){
        dp[m]=vec[m].v;
        for(int j=0;j<m;j++){
            if(vec[j].e+R<=vec[m].s)
                dp[m]=max(dp[m],dp[j]+vec[m].v);
        }
    }

    // 因为dp[i]的含义肯定是包含当前区间，所有我们需要再遍历一次。以为说不定最优解不包含当前区间
    int ans=0;
    for(int i=0;i<M;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}