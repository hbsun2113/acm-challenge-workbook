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
#include<numeric>>
using namespace std;
// 先放边长为6～3的。
// 之后，剩余的边角可以放多少边长2的，放完边长为2的，用面积计算之前空余多少边长1的，最后放1。
// https://www.cnblogs.com/mycapple/archive/2012/08/23/2652070.html
int main(){
    int a[7];
    int three2two[4]={0,5,3,1};
    while(scanf("%d%d%d%d%d%d", &a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]==0) break;
        int ans=0;
        ans+=(a[6]+a[5]+a[4]+(a[3]+3)/4); // 先计算一定要开辟新箱子的,注意a[3]中取天花板的操作，一个6*6中最多可以放4个3*3的，所以看a[3]中有多少个4，向上。
        int two=5*a[4]+three2two[a[3]%4]; // 放了一个4*4，还可以放5个2*2。 剩了 1个3*3,还可以放5个2*2；2个3*3，放3个2*2；3个3*3，1个2*2。
        if(a[2]>two) ans+=(a[2]-two+8)/9; // 边角放不下的2*2，也要单独开箱。一个6*6可以放9个2*2。
        int one=ans*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;
        if(a[1]>one) ans+=(a[1]-one+35)/36;
        printf("%d\n",ans);
    }

    return 0;
}