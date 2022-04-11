// [x] 1. Как сделать так, чтобы выводилась не 1, а true/false?
// [x] 2. Как вывести все поля через about, а не только последнее? (иначе не очень понятно, зачем писать about для промежуточных классов)
// [x] 3. Зачем в этих файлах использовать директиву #pragma once ?

#include <iostream>
#include <string>
#include <sstream>
#include "animal.h"
using namespace std;

inline ostream& operator <<(ostream& os, const Animal& animal) {
	return os << animal.about();
}

int main()
{
	Capybara	 Marcus;
	Rat			 Mickey;
	Langoustine	 Anton;
	Crab		 Crabsburger;

	Marcus.heterotrophic = true;
	Marcus.lactation = true;
	Marcus.the_biggest_rodent = true;

	Mickey.heterotrophic = true;
	Mickey.lactation = true;
	Mickey.cute_af = true;

	Anton.heterotrophic = true;
	Anton.claw_number = 0;
	Anton.is_spikes = true;

	Crabsburger.heterotrophic = true;
	Crabsburger.claw_number = 2;
	Crabsburger.is_shell = true;

	cout << "Crabsburger the Crab" << endl << Crabsburger << endl;
	cout << "Marcus the Capybara" << endl << Marcus << endl;
}
