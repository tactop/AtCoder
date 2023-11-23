#include <iostream>
#include <algorithm>
using namespace std;
int main()
{   
    long long N;
    long long A[5];
    cin >>N>> A[0] >> A[1] >> A[2] >> A[3] >> A[4];

    long long aa[5];
    long long max =0;
    for (long long i = 0; i < 5; i++)
    {
        aa[i] =(N+(A[i]-1))/A[i];
        if(aa[i]>max){
            max=aa[i];
        }
    }

    cout<<max+4<<endl;

}