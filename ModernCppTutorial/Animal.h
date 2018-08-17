#include "stdafx.h"
// static üyeler linker hatalarýndan sakýnmak için cpp dosyalarýnda tanýmlanýr. "pragma one" gibi komutlar da hatayý engellemez.
// en iyisi class,struct, vb. yapýlarýn kalýbýný header dosyasýna, gövdelerini .cpp dosyalarýna yazmaktýr.
// https://stackoverflow.com/questions/8479480/link-error-when-declaring-public-static-variables-in-c
#ifndef ANIMAL_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define ANIMAL_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once // visual c++ özel header korumasý
#endif  // _MSC_VER
class Animal
{
protected: // dýþarýdan görülemez. public aktarýmda public kalýr.
private: // dýþarýdan görülemez. public aktarýmda private kalýr. Class varsayýlan olarak "privatedir."
	std::string name;
	double height;
	double weight;
	static int numOfAnimals; // her yeni nesne oluþumunda baþa sarmaz. böylece kaç tane nesne oluþtuðunu sayabiliriz.
public: // nesne oluþturulduktan sonra nesne ile dýþarýdan görülebilir. public aktarýmda public kalýr.
		// modern c++ bazý durumlarda otomatik yapýcý ve yýkýcý fonksiyonlarý tanýmlayabilir ama çok sýnýrlýdýr.
	Animal() { SetAll("bilinmeyen", 0, 0); ekranayaz << "Animal() created: " << this->name << yenisatýr; } // Class oluþturucu. class hafýzada nasýl yer ayýrýr, nasýl tanýmlanýr gibi bilgileri ifade eder.
	Animal(std::string sname, double sheight, double sweight)
	{
		SetAll(sname, sheight, sweight); ekranayaz << "Animal(std::string, double, double) created: " << 
			this->name << yenisatýr;
	} // Oluþturucu ve yýkýcý aþýrý yüklenebilir. Burada varsayýlan oluþturucuyu derleyici oluþturacaktýr.
	~Animal() { ekranayaz << "~Animal() destroyed: " << this->name << yenisatýr; }// Class yýkýcý. class hafýzadan nasýl kaldýrýlýr, nasýl referanslar ve ilgili veriler silinir gibi bilgileri ifade eder.
	// Dýþarýdan görülebilecek fonksiyon yazýyorum. Fonksiyon gövdesi class içinde yazýabilir.
	std::string GetName() { return name; } // private üyelere direk eriþim yasaktýr ama böyle eriþim yasak deðildir. C# alýntýsý
	// this iþaretçisi class içindeki deðiþkenleri ve fonksiyonlarý iþaret eder.
	void SetName(std::string sname) { this->name=sname; }
	double GetHeight() { return height; } // get fonksiyonlarý public olduðundan this iþaretçisine ihtiyacý yok.
	void SetHeight(double sheight) { this->height = sheight; }
	double GetWeight() { return weight; }
	void SetWeight(double sweight) { this->weight = sweight; }
	// static üye class dýþýnda tanýmlanýr.
	void SetAll(std::string sname, double sheight, double sweight) {
		this->name = sname; this->height = sheight; this->weight = sweight;
		++Animal::numOfAnimals;
	} // fonksiyon tanýtýcýsý. 
	static int GetNumOfAnimals() { return numOfAnimals; }
	std::stringstream ToString() {
		std::stringstream ss;
		ss << GetName() << " is " << GetHeight() << " cm uzunluk ve " << GetWeight() << " kg aðýrlýðýnda ";
		return ss;
	} // st
	inline void PrintAll(bool newline = false) {
		auto ss = this->ToString();
		std::string str;
		while (std::getline(ss, str)) {
			std::cout << str;
		}
		if (newline) yenisatýryaz;
	}
};
// int Animal::numOfAnimals = 0; // deðerin verilmesini .cpp içinde yapýn.

#endif  // HEADER_FILE