#include <bits/stdc++.h>
using namespace std;
namespace abdullah{
    int age1=20;
    void hello(){
        cout<< "abdullah namespace"<<endl;
    }
}
namespace mohammad{
    int age2=20;
    void gelo(){
        cout<< "mohammad namespace"<<endl;
    }
}
using namespace abdullah;
// using namespace mohammad;

int main()
{
    cout<< age1<< endl;
    hello();
    cout<< mohammad::age2<< endl;
    mohammad::gelo();

    return 0;
}