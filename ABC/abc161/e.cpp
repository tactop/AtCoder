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
    int N, K, C;
    string S;
    set<int> kouho;
    cin >> N >> K >> C >> S;

    int ind = 0;
    int wsum = 0;
    while(ind < N) {
        if(S[ind] == 'x') {
            ind++;
        } else {
            kouho.insert(ind);
            wsum++;
            ind += 1 + C;
        }
    }
    for(auto k : kouho) {
        // cout << k << endl;
        string ts = S;
        ts[k] = 'x';
        // cout << ts << endl;
        int t = 0;
        int tsum = 0;
        set<int> se;
        while(t < N) {
            if(ts[t] == 'x') {
                t++;
            } else {
                se.insert(t);
                tsum++;
                t += 1 + C;
            }
        }
        if(tsum < K) {
            cout << k + 1 << endl;
        } else {
            for(auto tk : kouho) {
                if(se.count(tk) == 0) {
                    kouho.erase(tk);
                }
            }
        }
    }
}
