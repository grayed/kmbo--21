# Домашние задания для КМБО-03-21, КМБО-04-21 и КМБО-06-21

Первоначальная настройка и особенности работы в различных средах разработки описаны в [Wiki](../../wiki).

UML-диаграммы (файлы с расширением `.xmi`) можно обрабатывать в программе [Umbrello](https://umbrello.kde.org/).

## Животные №1

1. Создать иерархию классов, описывающих классификацию животных:
   * 3 уровня (например: `Animal` - `Mammal` - `Cat`), на первом уровне `class Animal`.
   * Минимум два дочерних класса для каждого родительского класса.
   * В каждом классе создать одно публично (`public`) доступное поле, отражающее уникальность соответствующего таксона.
     Например, для класса `Cat` это может быть (средняя) длина вибриссов: `float vibrissaLength`.

2. Создать в `main()` по 1 объекту каждого класса нижнего уровня и установить разумные значения для всех доступных полей в данных объектах.

3. По образу и подобию кода в `vehicles.h` и `vehicles.cpp`:
   1. Добавить функцию `about()`.
   2. Реализовать оператор вывода в поток для `Animal`.

## Животные №2

1. Сделать все поля приватными, а доступ к ним сделать через пару методов («геттер» и «сеттер»), например:
```cpp
    private:
        int foo;
    public:
        int  getFoo() const       { return foo; }
        void setFoo(int newValue) { foo = newValue; }
```
2. Реализовать конструкторы для всех классов, позволяющие инициализировать все поля каждого класса.
   Конструкторы родительских классов должны быть объявлены в области видимости `protected`.

## Векторы №1

1. Реализовать (перегрузить) следующие операции над классом `vector3d` (папка `vectors`):
   - Бинарные: `+`, `-`, `*` (умножение на скаляр), `/` (деление на скаляр).
   - Унарные: `-` (инвертирование знака), `!` (для входного вектора из одних нулей возвращает вектор из единиц,
     а для всех остальных входных векторов возвращает вектор из нулей).
2. Продемонстрировать применение всех перегруженных операций.
3. Написать функцию `bool test_vector3d()`, которая должна проверить корректность реализации всех перечисленных выше операций.
   Для каждой проваленной проверки должна выводиться в `std::cerr` ровно одна поясняющая строка, отображающая, какая операция и с какими данными повела себя неверно.
   Данную функцию вызвать из `main()`, сделать её результат определяющим для возвращаемого из `main()` значения (`0` для `true`, `1` для `false`).

## Игры с памятью №1

1. Реализовать функцию `A::getBString()`, возвращающую значение `B::b_s`
   (подразумевается, что объект, для которого вызывается, является объектом типа `B`).
   Используйте знание о расположении объектов в памяти.
2. Реализовать `A::printData()`, выводящую в поток текствое представление `A::a_s`, `B::b_s` и `B::data`
   с помощью `A::getBString()` и аналогичных техник.
3. Реализовать `A::printData2()`, выводящую в поток текствое представление `A::a_s`, `B::b_s` и `B::data`
   с помощью виртуальных функций.

## Электричество №1

1. Реализовать `const Pole* Switch::getPole(size_t idx) const`.
2. Реализовать `Pole* Object::getPole(size_t idx)`.
3. Реализовать `bool Object::isConnectedTo(const Object& other) const`.
4. Реализовать `bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName)`.
5. Реализовать класс светильника Light с двумя полюсами.
6. Реализовать класс генератора с тремя полюсами (фаза, нейтраль, земпя).
7. В функции `main()` построить цепь из генератора, выключателя и светильника.
