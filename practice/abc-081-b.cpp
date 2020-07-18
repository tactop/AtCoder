#include <iostream>
using namespace std;

int main() {
    int N;
    int n[250];
    int res =0;
    cin >> N;
    for(int i=0;i<N;i++) cin >> n[i];
    while(true){
        bool kisuu_ari = false;
        for(int i=0;i<N;i++){
            if(n[i]%2!=0) kisuu_ari=true;
            else n[i]=n[i]/2;
        }
        if(kisuu_ari)break;
        res++;
    }   
    cout << res << endl;     
}