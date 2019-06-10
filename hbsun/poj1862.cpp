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
typedef pair<int,int> pii;

/*
 * POJ 1862: Stripies
 * 题意：n个细胞，质量为m1、m2的结合后会变成质量为2sqrt(m1*m2)的新细胞，求最后形成的终极细胞的最小质量。
 * 类型：贪心
 * 算法：由于越先参与的细胞取根号的次数越多，每次选取最大的两个细胞结合，使得越大的细胞能够越多地减少。
 */

int main(){
    int N;
    cin>>N;
    int t;
    priority_queue<double> p;
    for(int n=0;n<N;n++){
        cin>>t;
        p.push(t);
    }
    double a,b;
    double c;
    for(int n=0;n<N-1;n++){
        a=p.top();
        p.pop();
        b=p.top();
        p.pop();
        c=2*sqrt(a*b);
        p.push(c);
    }
    printf("%.3f\n",p.top());
    return 0;
}