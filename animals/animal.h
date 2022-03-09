#pragma once

#include <iostream>
#include <sstream>
namespace std {
	class Animal {
	private:
		double weight;				// kg
		int age;                    // years

	public:
		double get_weight();
		void set_weight(double _weight);

		int get_age();
		void set_age(int _age);
		virtual string about() const;

	protected:
		Animal(double _weight, int _age);
	};

	class Mammal : public Animal {
	private:
		double pregnance_dyration;	// months

	public:
		double get_pregnance_dyration();
		void set_pregnance_dyration(double _pregnance_dyration);

		string about() const override;

	protected:
		Mammal(double _weight, int _age, double _pregnance_dyration);
	};

	class Cat : public Mammal {
	private:
		double vibrissa_length;		// meters

	public:
		double get_vibrissa_length();
		void set_vibrissa_length(double _vibrissa_length);

		string about() const override;

		Cat(double _weight, int _age, double _vibrissa_length);
	};

	class Dog : public Mammal {
	private:
		bool is_domestic;

	public:
		bool get_is_domestic();
		void set_is_domestic(bool _is_domestic);

		string about() const override;

		Dog(double _weight, int _age, bool _is_domestic);
	};

	class Reptile : public Animal {
	private:
		double egg_period;          // months

	public:
		double get_egg_period();
		void set_egg_period( double _egg_period);

		string about() const override;

	protected:
		Reptile(double _weight, int _age, double _egg_period);
	};

	class Crocodile: public Reptile {
	private:
		string tooth_shape;

	public:
		string get_tooth_shape();
		void set_tooth_shape(string _tooth_shape);

		string about() const override;

		Crocodile(double _weight, int _age, string _tooth_shape);
	};

	class Snake : public Reptile {
	private:
		string pattern;

	public:
		string get_pattern();
		void set_pattern(string _pattern);

		string about() const override;
		Snake(double _weight, int _age, string _pattern);
	};
}