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
typedef pair<int,int> pii; // 把int换成long long 会超时
//http://www.carolunar.com/2017/02/12/poj-3040-allowance/
//https://www.cnblogs.com/demian/p/6560926.html

// 宗旨：每次凑成C时 浪费得越少，能发的时间就越长
// 也就是说我每次凑成C，都尽量保证剩余最大，这样肯定没毛病

// 贪心策略
// 1. 首先面额不小于C的硬币属于没办法节约的类型，先统统发掉。
// 2. 然后对硬币面额从大到小尽量凑得接近C，允许等于或不足C，但是不能超出C。
// 3. 然后从小到大找到一个coin，和2的累积值加起来超过C。这样就可以组成一个C了。

// 双向贪心
// 从大到小：因为大的是小的倍数，所以首选放大的。因为如果从小的开始累积，在超过C之前，必然经过这个大的，因此使用大的替换小的更优(至少没有浪费)。
// 从小到大：找到一个凑成C的最小值，使得我们浪费的数额最少。

int main(){
    int N,C;
    vector<pii> vec;
    scanf("%d%d", &N, &C);
    int ans=0;
    int v,b;

    for(int n=0;n<N;n++){
        scanf("%d%d", &v, &b);
        if(v>C) ans+=b;
        else vec.push_back(make_pair(v,b));
    }

    int m=vec.size();

    sort(vec.begin(),vec.end());

    while(true){
        int tmp=C;
        for(int i=m-1;i>=0;i--){
            if(tmp>0 && vec[i].second>0){
                int count=min(vec[i].second,tmp/vec[i].first);
                vec[i].second-=count;
                tmp-=count*vec[i].first;
            }
        }


        for(int i=0;i<N;i++){
            if(tmp>0 && vec[i].second>0 && vec[i].first>=tmp){
                vec[i].second--;
                tmp-=vec[i].first;
                //break;
            }
        }

        if(tmp>0) break;
        ans++;

    }
    printf("%d\n",ans);
    return 0;
}