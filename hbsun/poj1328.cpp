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
// ��ÿ����ΪԲ�ģ��뾶Ϊd��Բ���õ���x���ཻ�γɵ����䡣
// ����ת��Ϊѡ��㣬ʹ��ÿ�������ж�������һ����,��ĸ���Ҫ�������١�
// ����ȫ������������Ĵ�������Ϊɾ��(��Ϊÿ�������ȻҪ���չ˵����չ˵�С�����ͬʱ��Ȼ�չ˵��˴�����)
// ̰�Ĳ��ԣ���������䱻ѡ���ˣ������ǾͰѵ�ŵ������ұ߽��ϣ�Ȼ��ȥ�������ж��ٸ�����Ҳ����ͬʱ��������չ˵���
// ע�⣬�жϸ�������С��ϵҪ��EPS��
int main(){
    int n,d;
    while(scanf("%d%d", &n, &d)!=EOF && n!=0){
        int x,y;
        bool flag=false;  // ��ȫ����Ϊ������Ҫ�����������
        for(int i=0;i<n;i++){
            scanf("%d%d", &x, &y);
            if(y>d || y<-d){
                flag=true;
                continue; // С�ӣ���ΪҪ���������ݣ����Բ���break
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