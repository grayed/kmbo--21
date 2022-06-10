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
	Langoustine	 Anton(1, false, 1);
	Crab		 Crabsburger;

	cout << "--- Marcus the Capybara ---" << endl << Marcus;

	Marcus.set_the_biggest_rodent(false);
	Marcus.set_lactation(false);
	Marcus.set_heterotrophic(false);

	cout << "--- Marcus the Imposter ---" << endl << Marcus;

	cout << "--- Mickey the Rat ---" << endl << Mickey;

	Mickey.set_cute_af(false);
	Mickey.set_heterotrophic(false);
	Mickey.set_lactation(false);

	cout << "--- Mickey the Imposter ---" << endl << Mickey;

	cout << "--- Anton the Demi-Imposter ---" << endl << Anton;

	Anton.set_claw_number(2);

	cout << "--- Anton the Crab ---" << endl << Anton;

	cout << "--- Crabsburger the Crab ---" << endl << Crabsburger;

	cout << "--- Crabsburger the Imposter ---" << endl;

	cout << "claw_number ? " << Crabsburger.get_claw_number() << endl;
	cout << "heterotrophic ? " << Crabsburger.get_heterotrophic() << endl;
	cout << "is_shell ? " << Crabsburger.get_is_shell() << endl;

	/*
	Mickey.heterotrophic = true;
	Mickey.lactation = true;
	Mickey.cute_af = true;

	Anton.heterotrophic = true;
	Anton.claw_number = 0;
	Anton.is_spikes = true;

	Crabsburger.heterotrophic = true;
	Crabsburger.claw_number = 2;
	Crabsburger.is_shell = true;
	*/

	//cout << "Crabsburger the Crab" << endl << Crabsburger << endl;
	//cout << "Marcus the Capybara" << endl << Marcus << endl;
}
