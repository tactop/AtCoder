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
    long long X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<long long> p(A);
    vector<long long> q(B);
    vector<long long> r(C);
    vector<long long> qr(B + C);
    vector<long long> qrg(B + C);
    vector<long long> ab;
    rep(i, 0, A) { cin >> p[i]; }
    rep(i, 0, B) {
        cin >> q[i];
        qr[i] = q[i];
    }
    rep(i, 0, C) {
        cin >> r[i];
        qr[B + i] = r[i];
    }
    // cout << "qr" << endl;
    qrg = qr;
    sort(p.begin(), p.end(), greater<long long>());
    sort(q.begin(), q.end(), greater<long long>());
    sort(r.begin(), r.end(), greater<long long>());
    sort(qr.begin(), qr.end(), greater<long long>());
    sort(qrg.begin(), qrg.end());
    rep(i, 0, X) { ab.push_back(p[i]); }
    rep(i, 0, Y) { ab.push_back(q[i]); }
    sort(ab.begin(), ab.end(), greater<long long>());
    // rep(i, 0, B + C) { cout << qr[i] << endl; }
    vector<long long> ruip(A);
    vector<long long> ruiq(B);
    vector<long long> ruir(C);
    vector<long long> ruiab(B + C);

    ruip[0] = p[0];
    ruiq[0] = q[0];
    ruir[0] = r[0];
    ruiab[0] = ab[0];
    rep(i, 1, A) { ruip[i] += ruip[i - 1] + p[i]; }
    rep(i, 1, B) { ruiq[i] += ruiq[i - 1] + q[i]; }
    rep(i, 1, C) { ruir[i] += ruir[i - 1] + r[i]; }
    rep(i, 1, X + Y) { ruiab[i] += ruiab[i - 1] + ab[i]; }
    long long max = 0;
    rep(i, 0, X + Y) {
        if(i > C) {
            continue;
        }
        long long sum = 0;
        sum += ruiab[X + Y - 1 - i];
        if(i > 0) {
            sum += ruir[i - 1];
        }
        if(sum > max) {
            max = sum;
        }
    }
    cout << max << endl;
}
