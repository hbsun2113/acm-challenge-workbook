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
// 这个说得也挺明白：https://www.cnblogs.com/demian/p/6560860.html
// 将区间按左端点排序，用最小堆维护每个牛栏内最右端点坐标。
// 对于每头牛，若其左端点大于堆顶元素，则可以插入该元素对应的牛栏并更新堆，否则新建牛栏。
// 说明为什么要更新堆:因为一旦插入该牛栏，该牛栏的右边界就变了。

struct cow{
    int first,second;
    int id;
    bool operator< (const cow &other) const{
        return first<other.first;
    }
};
vector<cow> vec(50010);

int main(){
    int N;
    cin>>N;
    for(int n=0;n<N;n++){
        scanf("%d%d", &vec[n].first, &vec[n].second);
        vec[n].id=n;
    }

    sort(vec.begin(),vec.begin()+N);

    int cnt=0;
    vector<int> ans(N);
    // (右边界，id)
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    for(int n=0;n<N;n++){
        if(p.empty() || vec[n].first<=p.top().first){
            ans[vec[n].id]= ++cnt;
            p.push(make_pair(vec[n].second,vec[n].id));
        }
        else{
            ans[vec[n].id]=ans[p.top().second];
            p.pop(); // 注意要更新堆
            p.push(make_pair(vec[n].second,vec[n].id));
        }
    }

    printf("%d\n", cnt);
    for(int n=0;n<N;n++)
        printf("%d\n", ans[n]);
    return 0;
}