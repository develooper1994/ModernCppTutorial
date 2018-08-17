#ifndef polyTemplateClass_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define polyTemplateClass_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
#include "stdafx.h"
// pure virtual
class Pizza {
public:
	virtual void MakePizza() = 0;
};

// The last templates that will be called
class NYStyleCrust {
public:
	std::string AddIngredient() {
		return "Crust so Thin You can See through it\n\n";
	}
};

class DeepDishCrust {
public:
	std::string AddIngredient() {
		return "Super Awesome Chicago Deep Dish Crust\n\n";
	}
};

// End of last templates called

// The middle templates called
template <typename T>
class LotsOfMeat : public T {
public:
	std::string AddIngredient() {
		return "Lots of Random Meat, " + T::AddIngredient();
	}
};

template <typename T>
class Vegan : public T {
public:
	std::string AddIngredient() {
		return "Vegan Cheese, Veggies, " + T::AddIngredient();
	}
};

// End of middle templates called

// We inherit from Pizza as well as the initial next template
template <typename T>
class MeatNYStyle : public T, public Pizza {
public:
	void MakePizza() {
		std::cout << "Meat NY Style Pizza : " <<
			T::AddIngredient();
	}
};

template <typename T>
class VeganDeepDish : public T, public Pizza {
public:
	void MakePizza() {
		std::cout << "Vegan Deep Dish : " <<
			T::AddIngredient();
	}
};

#endif  // HEADER_FILE