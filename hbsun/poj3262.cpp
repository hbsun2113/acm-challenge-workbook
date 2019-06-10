#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include"math.h"
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;

/*
 * 按照单一策略肯定不行：1. 如果每次选最近的，但它可能吃得很少  2.如果每次选最能吃的，但它可能很远(食量可能差距不大)。
 * 贪心题目，我们可以考虑相邻两项的关系：假设 (a,b)和(c,d) 如果先选(a,b)则消耗2ad,如果先选(c,d)，则消耗2bc
 * 则先选(a,b)的条件就是2ad<2bc，因此只要按照这个标准进行冒泡排序即可
*/
bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first*b.second<b.first*a.second;
};

int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> vec(100010);
    ll sum=0;
    for(int n=0;n<N;n++){
        scanf("%d%d",&vec[n].first,&vec[n].second);
        sum+=vec[n].second;
    }

    sort(vec.begin(),vec.begin()+N,cmp);

    ll ans=0;
    for(int n=0;n<N;n++){
//        cout<<vec[n].first<<" "<<vec[n].second<<endl;
        sum-=vec[n].second;
        ans+=sum*2*vec[n].first;
//        cout<<sum<<" "<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}