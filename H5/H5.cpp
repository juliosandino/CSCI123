#include <iostream>
using namespace std;

void MyFunc (int, int&, int);
int main ()
{
    int Var1 = 10, Var2 = 20, Var3 = 30;

    cout << Var1 << endl;
    cout << Var2 << endl;
    cout << Var3 << endl;

    MyFunc(Var1, Var2, Var3);

    cout << Var1 << endl;
    cout << Var2 << endl;
    cout << Var3 << endl;

    return 0;
}

void MyFunc (int Para1, int& Para2, int Para3)
{
    int Var1 = 20; int Var2 = 5; int Var3 = 10;

    Var1 += Para3;
    Para2 += Var2;
    Var2 += Para1 + Para2;
    Para1 = Var3;
    Para3 = Var2;

    cout << Var1 <<endl;
    cout << Var2 <<endl;
    cout << Var3 << endl;
    cout << Para1 <<endl;
    cout << Para2 <<endl;
    cout << Para3 << endl;
}