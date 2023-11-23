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
    cin >> N >> K >> C >> S;
    vector<int> L(K);
    vector<int> R(K);
    int ind = 0;
    int wsum = 0;
    while(ind < N) {
        if(wsum >= K) {
            break;
        }
        if(S[ind] == 'x') {
            ind++;
        } else {
            L[wsum] = ind;
            wsum++;
            ind += 1 + C;
        }
    }
    ind = N - 1;
    wsum = 0;
    while(ind >= 0) {
        if(wsum >= K) {
            break;
        }
        if(S[ind] == 'x') {
            ind--;
        } else {
            R[K - 1 - wsum] = ind;
            wsum++;
            ind -= 1 + C;
        }
    }

    rep(i, 0, K) {
         //cout << "L:" << L[i] << ",R:" << R[i] << endl;
        if(L[i] == R[i]) {
            cout << L[i]+1 << endl;
        }
    }
}
