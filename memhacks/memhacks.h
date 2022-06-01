#pragma once

#include <ostream>
#include <string>
#include <vector>

class B;

class A
{
public:
    std::string getBString() const;

    void printData(std::ostream& os);

    void printData2(std::ostream& os);

    virtual std::string getBStringV() const = 0;

    virtual std::vector<float> getBDataV() const = 0;

private:
    std::string a_s;
    int foo;

    friend void printInternals(const B&);
};

class B : public A
{
public:
    B();

    std::string getBStringV() const override;

    std::vector<float> getBDataV() const override;

private:
    std::string b_s;
    float data[7];

    friend void printInternals(const B&);
};

void printInternals(const B&);