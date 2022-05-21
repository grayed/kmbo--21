#include "newhacks.h"

using namespace std;

int main() {
    //объявление объектов в динамической памяти
    //демонстрация работы переопределенных методов new,delete
    Foo* obj1 = new Foo;
    delete obj1;

    obj1 = new Foo;
    delete obj1;
    Bar* obj2 = new Bar;
    delete obj2;
    obj2 = new Bar;
    delete obj2;

    //Buz* obj3 = new Buz;
    //мы не можем обратиться к методу клааса Buz, тк мы объявили его в зоне protected
    
    //объявление объектов на стэке
    Foo obj12, obj13;
    obj12.show_adress();
    obj13.show_adress();
    Bar obj22, obj23;
    obj22.show_adress(); // Вот так функция работает тк я ее объявил в теле класса
    obj23.show_adress();
    Buz obj32, obj33;
    obj32.show_adress();
    obj33.show_adress();
    return 0;
}