#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> s(H);
    rep(i, 0, H) { cin >> s[i]; }
    // {0, 1, ..., n-1} の部分集合の全探索
    long long res = INF;
    for(int bit = 0; bit < (1 << (H - 1)); ++bit) {
       // cout << "hei" << endl;
        vector<int> tmp;
        vector<int> sen(H - 1);
        tmp.push_back(0);
        for(int i = 0; i < H - 1; ++i) {
            if(bit & (1 << i)) { // 列挙に i が含まれるか
                tmp.push_back(0);
                sen[i] = 1;
            }
        }
        //cout << "size:" << tmp.size() << endl;
        long long kouho = tmp.size() - 1;
        rep(t, 0, W) {
            int ret = 0;
            int tmpnum = 0;
            bool koe = false;
            while(ret < H) {
                if(s[ret][t] == '1') {
                    tmp[tmpnum]++;
                 
                    if(tmp[tmpnum] > K) {
                        koe = true;
                    }
                }
                if(ret!=H-1&&sen[ret] == 1) {
                    tmpnum++;
                }
                ret++;
                
            }

            if(koe) {
                kouho++;
                rep(k, 0, tmp.size()) { tmp[k] = 0; }
                int ret2 = 0;
                int tmpnum2 = 0;
                bool koe2 = false;
                while(ret2 < H) {
                    if(s[ret2][t] == '1') {
                        tmp[tmpnum2]++;
                        if(tmp[tmpnum2] > K) {
                            koe2 = true;
                        }
                    }
                    if(ret2!=H-1&&sen[ret2] == 1) {
                        tmpnum2++;
                    }
                    ret2++;
                }
                if(koe2) {
                    kouho = INF;
                    break;
                }
            }
        }
        //cout << "kouho:" << kouho << endl;
        if(kouho < res) {
            res = kouho;
        }
    }
    cout << res << endl;
}
