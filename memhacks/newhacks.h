#pragma once


class Foo {
    float speed;
    float weight;
public:
    Foo();
    ~Foo();

    float getSpeed() const { return speed; }
    float getWeight() const { return weight; }

    void setSpeed(float speed_) { speed = speed_; }
    void setWeight(float weight_) { weight = weight_; }

    void* operator new(size_t size);
    void  operator delete(void* p);
};

class Bar : public Foo {
public:
    Bar();
    ~Bar();
    void* operator new(size_t size);
    void  operator delete(void* p);
};

class Buz : public Foo {
public:
    Buz();
    ~Buz();
    void* operator new(size_t size);
};