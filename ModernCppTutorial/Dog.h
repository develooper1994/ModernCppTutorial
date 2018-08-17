#pragma once
#include "Animal.h"
class Dog : public Animal // Animal sýnýfýnýn tüm özelliklerini aldý.
{
private:
	std::string sound{"hav"};
public:
	// Bu aþamada Animal classýn içindeki istenen fonksiyonlarý aþýrý yüklemek üzere kullanýlýr. Yoksa Linker hatalarý ile karþýlaþýlýr.
	// Aslýnda bu sorun c++ virtual fonksiyonlarý ile çözülür.
	// virtual fonksiyonlar java ve C# interface durumunun dengidir.
	using Animal::SetAll;
	using Animal::ToString;
	Dog() { std::cout << "Dog() oluþtu: " << GetName() << std::endl; }
	// ": Animal(sname,sheight,sweight)" ile kopyalama olmadan class deðiþkenlerinin deðerleri atanabilir.
	Dog(std::string sname , double sheight, double sweight, std::string ssound) : Animal(sname, sheight, sweight)
	{
		std::cout << "Dog SetAll(std::string, double, double, std::string) oluþtu: " << 
			GetName() << std::endl; SetSound(ssound);
	} // Vc++ cpp dosyasýnda tanýmlamaya yardýmcý oluyor.
	~Dog() { std::cout << "~Dog() yýkýldý: " << GetName() << std::endl; }

	std::string GetSound() { return sound; }
	void SetSound(std::string ssound) { this->sound = ssound; }
	void SetAll(std::string sname, double sheight, double sweight, std::string ssound) { 
		Animal::SetAll(sname, sheight, sweight); // Ya using ... kullanýn yada açýk açýk Animal sýnýfýnýn fonksiyonunu kullandýðýnýzý belirtin.
		SetSound(ssound); // fazladan eklenen üye sound ve sound ayarlandý.
						  // Ayný zamanda static sayacýmýz çalýþýyor.
	}
	void SesCýkart() { std::cout << "Dog: " << GetName() << " says " << GetSound() << std::endl; }
	std::stringstream ToString() {
		auto ss = Animal::ToString();
		ss << " Sound: " << GetSound();
		return ss;
	}
	// printAll bir daha tanmlamaya gerek görmedim. Yeterince iyi.
};

