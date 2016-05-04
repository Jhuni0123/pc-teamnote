#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 2147483647;
const int mod = 1000000007;

//Counter Clock-Wise
int ccw(int x1,int x2,int x3,int y1,int y2,int y3){
    int t = x1*y2+x2*y3+x3*y1;
    t = t - y1*x2-y2*x3-y3*x1;
    return t;
}
//dijkstra
void dijkstra(int k){
	for(int i=1;i<=n;i++){
		d[i]=INF;
	}
	d[k]=0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(pii(0,k));
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		int dis=p.first, v=p.second;
		if(d[v]>dis)continue;
		for(int i=0;i<g[v].size();i++){
			pii q=g[v][i];
			int to = q.first, cost = q.second;
			if(d[to] > cost+dis){
				pq.push(pii(d[to] = cost+dis,to));
			}
		}
	}
}
