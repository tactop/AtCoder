#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string W;
    int ans = 0;
    vector<string> L;
    vector<int> alpha(26, 0);
    for(auto wc : W) {
        int wcnum = wc - 'a';
        if(alpha[wcnum] == 0) {
            alpha[wcnum] = 1;
        }
    }
    string l;
    while(cin >> l) {
        vector<int> lalpha(26, 0);
        for(auto lc : l) {
            int lcnum = lc - 'a';
            if(lalpha[lcnum] == 0) {
                lalpha[lcnum] = 1;
            }
        }
        bool che = true;
        for(int i = 0; i < 26; i++) {
            if(alpha[i] != lalpha[i]) {
                cout << alpha[i] << ":" << lalpha[i] << endl;
                che = false;
            }
        }
        if(che) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}