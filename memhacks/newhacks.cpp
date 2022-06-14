#include <iostream>
#include "newhacks.h"

using namespace std;

void solve() {
    //Создание всех трех элементов на стеке
    Foo f(1, 'a'); Bar b(13); Buz z(123);

    //Создание всех трех элементов в динамической памяти
    Foo *f1 = new Foo; Bar *b1 = new Bar; Buz *z1 = new Buz;
    delete f1; delete b1; delete z1;

    //Для того чтобы запретить создание элемента типа Buz
    //достаточно operator new/delete записать в private:
}

int main() {
    solve();


    return 0;
}
