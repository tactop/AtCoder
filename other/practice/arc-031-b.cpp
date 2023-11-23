#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[10][10];

int serch(int i,int r){
    map[i][r]=2;
    if(i>=1 && map[i-1][r]==1){
        serch(i-1,r);
    }
    if(i<=8 && map[i+1][r]==1){
        serch(i+1,r);
    }
    if(r>=1 && map[i][r-1]==1){
        serch(i,r-1);
    }
    if(r<=8 && map[i][r+1]==1){
        serch(i,r+1);
    }
    return 0;
}
bool check(){
    bool res =true;
    for (int i=0;i<10;++i) {
        for(int j=0;j<10;++j){
            if (map[i][j]==1){
                res =false;
            }else if(map[i][j]==2){
                map[i][j]=1;
            }
        }
    }
    return res;
}

int main(){ 
    bool ans =false;
    string S[10];
    for(int i=0;i<10;++i) {
        cin >> S[i];
        for(int j=0;j<10;++j){
            if(S[i][j]=='o'){
                map[i][j]=1;
            }else{
                map[i][j]=0;
            }
        }
    }
    for (int i=0;i<10;++i) {
        for (int r=0;r<10;++r) {
            bool umeFlag=false;
            if(map[i][r]==0){
                map[i][r]=1;//ひとつを埋め立て
                umeFlag=true;
            }
            serch(i,r);//埋め立てた地点を起点に1→2にする
            bool chk =check();
            if(chk){
                ans =true;
                //cout << i <<","<<r<< endl;  
            }
            if(umeFlag){
                map[i][r]=0;
            }
        }
    }
    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}