#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    string ymd;
    cin >> ymd;
    string YYYY,MM;
    YYYY=ymd.substr(0,4);
    MM= ymd.substr(5,2);
    if(atoi(YYYY.c_str())>=2019 && atoi(MM.c_str())>=05){
        cout << "TBD" <<endl;
    }else{
        cout << "Heisei" <<endl;
    }
}

