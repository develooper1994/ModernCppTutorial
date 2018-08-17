#pragma once
#include "stdafx.h"
#include "stdheaders.h"
#include "customHeaders.h"
// Dikkat! bu header dosyasý YararlýFonksiyonlar.h içinde dahil edildi. Sakýn böyle birþey yapmayýn. Eðitim amaçlýdýr.
#include "YararlýFonksiyonlar.h"

namespace functionalStyle { // þimdilik sadece header dosyalarýyla kullanýn.
	static auto println = [](const char  *message) { std::cout << message << std::endl; };

	template<typename Collection,typename sep>
	static std::vector<Collection> StringToVector(Collection cumle, sep seperator) {
		std::vector<Collection> kelimeler;
		std::stringstream ss(cumle);
		Collection ayrýdý;
		while (getline(ss, ayrýdý, seperator)) { kelimeler.push_back(ayrýdý); }
		return kelimeler;
	}
	template<> // std::string ve char için özel yazýlmýþ fonksiyon.
	static std::vector<std::string> StringToVector(std::string cumle, char seperator) {
		std::vector<std::string> kelimeler;
		std::stringstream ss(cumle);
		std::string ayrýdý;
		while (getline(ss, ayrýdý, seperator)) {
			kelimeler.push_back(ayrýdý);
		}
		return kelimeler;
	}

	template <typename Collection, typename unop>
	static void for_each(Collection col, unop op) {
		std::for_each(col.begin(), col.end(), op);
	}

	template <typename Collection, typename unop>
	static Collection map(Collection col, unop op) {
		std::transform(col.begin(), col.end(), col.begin(), op);
		return col;
	}

	template <typename Collection, typename Predicate>
	static Collection filterNot(Collection col, Predicate predicate) {
		auto returnIterator = std::remove_if(col.begin(), col.end(), predicate);
		col.erase(returnIterator, std::end(col));
		return col;
	}

	template <typename Collection, typename Predicate>
	static Collection filter(Collection col, Predicate predicate) {
		//capture the predicate in order to be used inside function
		auto fnCol = filterNot(col, [predicate](typename Collection::value_type i) { return !predicate(i); });
		return fnCol;
	}

	//fonksiyonelDersi.cpp tanýmlarý içindedir.
	// 1. Created to store as a variable and to
	// pass into other functions
	static inline double MultBy2(double num) { return num * 2; }
	// 2. Functions can receive other functions
	// the first double is the return type followed
	// by the data types for the parameter
	static inline double DoMath(std::function<double(double)> func, double num) { return func(num); }
	// 3. You can store functions in a vector
	static inline double MultBy3(double num) { return num * 3; }
	// 4. ----- PROBLEM -----
	// Checks for odd using modulus
	static inline bool IsItOdd(int num) { return !(num % 2) ? false : true; }
	// Receives a list and generates a list of odd values
	// from that list 
	static inline std::vector<int> ChangeList(std::vector<int> list, std::function<bool(int)> func) {
		std::vector<int> oddList;
		for (auto& i : list)
			if (func(i))
				oddList.push_back(i);
		return oddList;
	}
	static std::vector<char> GetHAndTList(std::vector<char> possibleValues, int numberValuesToGenerate) {
		// Saðlanan muhtemel deðerlerden rastgele bir liste oluþtur. input "char listesi" ve kaç tane üretsin, output 
		// Generates a random list from the possible values supplied
		srand(time(NULL));
		std::vector<char> hAndTList;

		for (int x = 0; x < numberValuesToGenerate; ++x) {
			int randIndex = rand() % possibleValues.size(); // listede kaç tane varsa...
			hAndTList.push_back(possibleValues.at(randIndex)); // Rastgele birini seçiyor ve listeye ekliyor.
															   // toplamda 100 tane böylece rastgele üretilmiþ ama rastgele sayýlarda 'H' ve 'T' olacak.
		}
		return hAndTList;
	}
	static int GetNumberOfMatches(std::vector<char> list, char valueToFind) {
		// Eþleþen karakterler sayýsýný bul. 'H' ve 'T' karakterlerinin sayýsýný veriyor.
		int numOfMatches = 0;
		for (char& c : list)
			if (c == valueToFind)
				numOfMatches++;
		return numOfMatches;
	}


	// YararlýFonksiyonlar.h
	// void yararlýFonk::printAll(auto); // lambda fonksiyonlarýnýn auto ile fonksiyon bildirimi yapýlamaz.

}








