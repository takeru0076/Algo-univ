#include<iostream>
#include<algorithm>
#include<queue>
using namespace  std;

#define MAX 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2

static const int INFTY = (1<<20); //100000

int n;
int d[MAX];
vector<pair<int,int> > adj[MAX]; //整数型２つペアを一つの変数とする一次元配列

void dijkstra();

int main(){
    int k,u,v,c;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> u >> k;
        for(int j=0; j<k; j++){
            cin >> v >> c;
            adj[u].push_back(make_pair(v,c)); //末尾に要素を追加する
        }
    }

    dijkstra();

    for(int i=0; i<n; i++) cout << i << " " << (d[i] == INFTY ? -1: d[i]) << endl;
    return 0;
}

void dijkstra(){
    priority_queue<pair<int,int> > PQ;
    int color[MAX];
    for(int i=0; i<n; i++){
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[0] = 0;
    PQ.push(make_pair(0,0));
    color[0] = GRAY;

    while (!PQ.empty())
    {
        pair<int,int> f = PQ.top();PQ.pop(); //topを削除
        int u = f.second;
        color[u] = BLACK;

        if(d[u] <f.first * (-1)) continue;

        for(int j=0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v] * (-1),v));
                color[v] = GRAY;
            }
        }
    }
}