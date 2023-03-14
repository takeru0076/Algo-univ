#include <iostream>
#include <cmath> //数学関数
#include <string>
#include <map> //「連想配列クラス」とは検索可能なキーと、キーに対応する値の組（ペア）を要素とするコンテナクラスで、 保持している要素から、キーを指定して値を高速に取り出せるクラスのこと.二分木。
#include <queue> 

using namespace std;

#define N 3
#define N2 9

struct Puzzle
{
    int f[N2]; // 各々のタイルの状態(spaceは0だけど、9に換算する)
    int space; // 空白の位置を管理indexで0 - 8まで
    string path;    // 解法までのルートを記録

     // 同じ状態遷移か判定する
    bool operator < (const Puzzle &p) const {
    for(int i=0; i<N2; i++){
        if(f[i] == p.f[i]) continue;
        // 最短を求めるためにタイル数値が大きいと一致していると判定する(上から1,2,3と並ぶので)
        return f[i] > p.f[i];
    }
    return false;
    }
};

//上,右,下,左の順でチェックする
static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,-1,0,1};
static const char dir[4] = {'u','l','d','r'};

bool isTarget(Puzzle);
string bfs(Puzzle);

int main(){
     Puzzle in;
     for(int i=0; i<N2; i++){
         cin >> in.f[i];
         if(in.f[i] == 0){
             in.f[i] = N2;
             in.space = i;
         }
     }
     string ans = bfs(in);
     cout << ans.size() << endl;
    return 0;
}

// 幅優先探索を行う
string bfs(Puzzle s){
    queue<Puzzle> Q;
    map<Puzzle, bool> V;// 同じ遷移状態がないか判定するためにmapを利用
    Puzzle u,v;
    s.path = "";
    Q.push(s);
    V[s] = true;  // 最初の状態遷移を保存

    // 幅優先探索
    while (!Q.empty()){
        u = Q.front(); Q.pop();
                // 正解チェック
        if(isTarget(u)) return u.path;
        // 空白の位置を算出する
        int sx = u.space / N;
        int sy = u.space % N;

        // スペースの周りの四方のタイルを動かす
        for(int r=0; r<4; r++){
            // 動かすタイルのindexを算出する(上,右,下,左の順)
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            // 範囲外チェック
            if(tx < 0) continue;
            if(ty < 0) continue;
            if(tx >= N) continue;
            if(ty >= N) continue;
            v = u;
            swap(v.f[u.space] , v.f[tx * N + ty]);
             // 入れ替えた場所がspaceになる
            v.space = tx * N + ty;
            if(!V[v]){
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}

bool isTarget(Puzzle p){
     // パズルが順番通り一致しているかチェック
    for(int i=0; i<N2; i++)
        if(p.f[i] != (i+1)) return false;
        return true;
}