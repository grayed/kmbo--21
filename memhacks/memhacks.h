#pragma once

#include <ostream>
#include <string>
#include <sstream>

class B;  // чтобы можно было объявить printInternals() как friend в классе A
using namespace std;
void printData(std::ostream& os);
void printData2(std::ostream& os);
class A {
    int foo;

    friend void printInternals(const B&, std::ostream& os);

public:
    std::string getBString() const;
    std::string getAString() const;
    float getDataFloat(int i) const;


    virtual string aboutA() const {
        stringstream ss;
        ss << "String A: " << a_s;
        return ss.str();
    }


    void printData(std::ostream& os, const A& a, const B& b);

    std::string a_s;
};

class B : public A {
    float data[7];
    friend void printInternals(const B&);

public:
    B();
    string get_b_s() { return b_s; }
    float get_data(int i) { return data[i]; }
    virtual string aboutB() {
        stringstream ss;
        ss << "String B: " << get_b_s() << endl;
        ss << "Data : ";
        for (int i = 0; i < 7; i++) {
            ss << get_data(i) << " ; ";
        }
        ss << endl;
        return ss.str();
    }
    void printData2(std::ostream& os);

    std::string b_s;
};

void printInternals(const B& b);