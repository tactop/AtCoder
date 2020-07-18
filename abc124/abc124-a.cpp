#include <iostream>
#include <string>

using namespace std;
int main()
{
    int A, B;

    cin>>A>>B;

    if (A>B)
    {
        cout<<2*A-1<<endl;
    }else if(B>A){
       cout<<2*B-1<<endl;
    }else{
        cout<<2*A<<endl;
    }
}