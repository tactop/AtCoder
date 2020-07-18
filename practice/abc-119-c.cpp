#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int maxMP = 9999999;
    int N,A,B,C;
    cin >>N >> A >> B >> C;
    int L[N];
    for(int i=0;i<N;i++){
        cin >> L[i];
    }
    int Abox[6];
    int Bbox[6];
    int Cbox[6];
    int as,bs,cs=0;
    int siyou[8]={};
    for(int i=0; i<(1 << (N-2));++i){
        for (int j=0;j<N;++j){
            if((i & (1<<j)) == 0){
                Abox[as]=L[j];
                siyou[j]=1;
                as++;
            }
        }
        int Abl=0;
        for(int r=0;r<6;r++){
            if(Abox[r]!=0){
                Abl++;
            }
        }
        for(int ib=0; ib<(1 << (N-1-Abl));++ib){
            for (int jb=0;jb<N;++jb){
                if((ib & (1<<jb)) == 0 && siyou[jb]!=1){
                Bbox[bs]=L[jb];
                siyou[jb]=1;
                bs++;
                }
            }
            int Bbl=0;
            for(int r=0;r<6;r++){
                if(Bbox[r]!=0){
                Bbl++;
                }
            }
            for(int ic=0; ic<(1 << (N-Abl-Bbl));++ic){
                for (int jc=0;jc<N;++jc){
                    if((ic & (1<<jc)) == 0 && siyou[jc]!=1){
                    Cbox[cs]=L[jc];
                    siyou[jc]=1;
                    cs++;
                    }
                }
                int Cbl=0;
                for(int r=0;r<6;r++){
                    if(Cbox[r]!=0){
                    Cbl++;
                    }
                }
                int MP=0;
                int asum=0;
                for(int ta=0;ta<as;ta++){
                    asum+=Abox[ta];
                }
                int bsum=0;
                for(int tb=0;tb<bs;tb++){
                    bsum+=Bbox[tb];
                }
                int csum=0;
                for(int tc=0;tc<cs;tc++){
                    csum+=Cbox[tc];
                }
                MP+=10*as;
                MP+=10*bs;
                MP+=10*cs;
                MP+=abs(A-asum);
                MP+=abs(B-bsum);
                MP+=abs(C-csum);
                if(MP<maxMP){
                maxMP=MP;
                }
            }

        }
    }
    cout << maxMP << endl;
}

