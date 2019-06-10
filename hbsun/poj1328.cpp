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
typedef pair<double,double> pii;
vector<pii> vec(1010);
int t=1;

const double EPS = 1e-6;
// 以每个岛为圆心，半径为d画圆，得到与x轴相交形成的区间。
// 问题转化为选择点，使得每个区间中都至少有一个点,点的个数要尽可能少。
// 将完全包含其他区间的大区间标记为删除(因为每个区间必然要被照顾到，照顾到小区间的同时自然照顾到了大区间)
// 贪心策略：如果该区间被选择了，则我们就把点放到它的右边界上，然后去看后面有多少个区间也可以同时被这个点照顾到。
// 注意，判断浮点数大小关系要用EPS。
int main(){
    int n,d;
    while(scanf("%d%d", &n, &d)!=EOF && n!=0){
        int x,y;
        bool flag=false;  // 完全是因为题里需要多组测试用例
        for(int i=0;i<n;i++){
            scanf("%d%d", &x, &y);
            if(y>d || y<-d){
                flag=true;
                continue; // 小坑，因为要继续读数据，所以不能break
            }
            vec[i].first=x-sqrt((double)d*d-y*y);
            vec[i].second=x+sqrt((double)d*d-y*y);
        }

        if(flag){
            printf("Case %d: %d\n",t++,-1);
            continue;
        }

        vector<bool> ign(1010,false);
        sort(vec.begin(),vec.begin()+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(vec[i].second>=vec[j].second+EPS){
                    ign[i]=true;
                    break;
                }
            }
        }
        int ans=0;
        int i=0,j=0;
        while(i<n){
            while(i<n && ign[i]) i++;
            if(i==n) break;

            ans++;

            j=i+1;
            while(j<n && vec[j].first<=vec[i].second+EPS) j++;
            i=j;
        }

        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}