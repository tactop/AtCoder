#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;


int main(){
    int N;
    cin >>N;
    double Y=0;
    for(int i=0;i<N;i++){
        double m;
        string syurui;
        cin >> m >> syurui;
        if(syurui=="JPY"){
            Y += m;
        }else{
            Y += m*380000.00000000;
        }
    }
    cout << fixed << setprecision(10) << Y <<endl;
}

