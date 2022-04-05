#pragma once

#include <sys/types.h>

class Cls
{
    static int next_id;
    int id;

public:
    Cls();
    ~Cls();

    static void* operator new[](size_t size);
    static void  operator delete[](void *p);
};

/**
 * 1. Реализовать operator new и
 *    operator delete в классе Cls.
 *
 * 2. Реализовать в new/delete кеширование
 *    памяти из-под одного уничтоженного
 *    объекта: delete заполняет кеш (если
 *    он не заполнен), а new по возможности
 *    этот кеш использует. Подсказка:
 *
 *    private:
 *      static void *cache;
 *
 * 3. Повторить п.2 для new[]/delete[].
 */
