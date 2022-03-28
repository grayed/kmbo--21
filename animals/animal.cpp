#include "animal.h"
#include<iostream>
#include<sstream>


using namespace std;


int main() {
    Cat cat();
    Lizard lizard();
    cat().set_vibrissae_length(6);
    lizard().set_how_long_tail_grow(5);
    int res = cat().get_vibrissae_length();
    cout << res <<;
    return 0;
}