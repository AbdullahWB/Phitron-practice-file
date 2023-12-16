#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    // if(x==10){
    //     cout<< "It is ten out of ten" << endl;
    // }else{
    //     cout<< "It is not ten out of ten" << endl;
    // }

    // ternary operator
    (x % 2 == 0) ? cout << "Even" << endl : cout << "Odd" << endl;
}