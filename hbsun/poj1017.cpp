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
// �ȷű߳�Ϊ6��3�ġ�
// ֮��ʣ��ı߽ǿ��ԷŶ��ٱ߳�2�ģ�����߳�Ϊ2�ģ����������֮ǰ������ٱ߳�1�ģ�����1��
// https://www.cnblogs.com/mycapple/archive/2012/08/23/2652070.html
int main(){
    int a[7];
    int three2two[4]={0,5,3,1};
    while(scanf("%d%d%d%d%d%d", &a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]==0) break;
        int ans=0;
        ans+=(a[6]+a[5]+a[4]+(a[3]+3)/4); // �ȼ���һ��Ҫ���������ӵ�,ע��a[3]��ȡ�컨��Ĳ�����һ��6*6�������Է�4��3*3�ģ����Կ�a[3]���ж��ٸ�4�����ϡ�
        int two=5*a[4]+three2two[a[3]%4]; // ����һ��4*4�������Է�5��2*2�� ʣ�� 1��3*3,�����Է�5��2*2��2��3*3����3��2*2��3��3*3��1��2*2��
        if(a[2]>two) ans+=(a[2]-two+8)/9; // �߽ǷŲ��µ�2*2��ҲҪ�������䡣һ��6*6���Է�9��2*2��
        int one=ans*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;
        if(a[1]>one) ans+=(a[1]-one+35)/36;
        printf("%d\n",ans);
    }

    return 0;
}