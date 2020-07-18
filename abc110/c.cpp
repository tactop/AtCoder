#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#include <unordered_map>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
int main() {
    string S, T;
    cin >> S >> T;
    unordered_map<char, int> ss;
    vector<int> ves;
    int num = 0;
    rep(i, 0, S.size()) {
        if(ss.count(S[i]) != 0) {
            ves.push_back(ss[S[i]]);

        } else {
            ss.emplace(S[i], num);
            ves.push_back(num);
            num++;
        }
    }
    unordered_map<char, int> st;
    vector<int> vet;
    int num2 = 0;
    rep(i, 0, T.size()) {
        if(st.count(T[i]) != 0) {
            vet.push_back(st[T[i]]);

        } else {
            st.emplace(T[i], num2);
            vet.push_back(num2);
            num2++;
        }
    }
    bool res = true;
    rep(i, 0, S.size()) {
        if(ves[i] != vet[i]) {
            res = false;
        }
    }
    if(res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}