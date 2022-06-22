#pragma once

#include <iostream>

class Animal {
	private:
		float weight;				// kg

	public:
		const float getWeight() const { return weight; }
		void setWeight(const float v) { weight = v; }

	protected:
		Animal(const float w) { weight = w; }
};
