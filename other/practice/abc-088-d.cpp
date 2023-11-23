#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;
//未完成
int main(){
    int H,W;
    cin >> H >> W;

    string S[H];
    int shiro =0;

    for(int i=0; i<W;++i){
        cin >> S[i];
        for(int j=0;j<W;++j){
            if(S[i][j]=='.') shiro++;
        }
    }   
    int INF = 1 << 13;
    // 十分大きければなんでもいいが、オーバーフローに注意
    vector<vector<int>> d(H, vector<int>(W, INF));

    queue<pair<int, int>> q;
    // 訪れるべき点を蓄える

    // 初期化
    d[0][0] = 1;
    q.push({0, 0});
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};
    // 周囲4マスを見るときに使う

    while (!q.empty()) {
        // qの先頭データを取り出す
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;

        // qの先頭を削除
        q.pop();

        // dx[4]とdy[4]を使って周囲4マスを見る
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 境界判定((nx, ny)が盤面に入っているか)
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {

                // 白マスかつ最短経路か判定
                if (S[nx][ny] == '.' && d[x][y] + 1 < d[nx][ny]) {

                    // 最短経路更新
                    d[nx][ny] = d[x][y] + 1;

                    // 「訪れるべき点」に追加
                    q.push({nx, ny});
                }
            }
        }
    }
    if(d[H-1][W-1]==INF){
        cout << -1 <<endl;
    }else{
     cout << shiro - d[H-1][W-1] << endl;   
    }

 }