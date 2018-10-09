#include "Integer.h"
#include <iostream>
#include <string>
#include <locale>

/*
Sorun:
	Class oluþturularý yapýlýrken sorunlar parametre olarak baþka bir class kullanmak doðal bir oladýr.
	Fakat parametre olarak oluþturulan classlarýn yapýcý fonksiyonlarý da çalýþýrsa bir fonksiyon çaðýrmak isterken parametre tip sayýsý kadar fonksiyon çaðýrmýþ olacaðýz.
	Veri defalarca kopyalanmýþ olacak. Veri kopyalanmasýný kaldýrmak üzere std::move(object) kullanýlabilir fakat. Employee

*/

class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	Employee(const std::string &name, const Integer &id) : m_Name{ name }, m_Id{ id } { // Referans kopyalayýcý oluþturucu
		std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	}
	template<typename T1, typename T2>
	Employee(T1 &&name, T2 &&id) : m_Name{ (name) }, m_Id{ (id) } { // taþýyýcý oluþturucu. objeyi hafýza da taþýmaya yarar.
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	}
	//template<typename T1, typename T2>
	//Employee(T1 &&name,  T2 &&id) :	m_Name{ std::forward<T1>(name) }, m_Id{ std::forward<T2>(id) } { // taþýyýcý oluþturucu. objeyi hafýza da taþýmaya yarar.
	//	std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	//}
};
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	setlocale(LC_ALL,"Turkish");
	std::cout << "\n--- Ýþte geliyor. Integer(int), Integer(int&&), Employee(std::string &&name,  Integer &&id), ~Integer() ---\n" << std::endl;
	Employee emp1{ "Mustafa", Integer{100} }; // önce kopyaladý, sonra hareket ettirdi. 4 fonksiyon çalýþtý. Ýstenen durum deðil.
	std::string name = "Umar"; // "lvalue"
	//std::cout << "\n--- Ýþte geliyor. ---\n" << std::endl;
	std::cout << "\n--- Ýþte geliyor. Integer(int), Employee(std::string &&name,  Integer &&id) ---\n" << std::endl;
	Employee emp2{ name, 100 }; // bir kopyalama ve bir taþýma çalýþtý. 2 fonksiyon aktif. Bir nebze daha iyi. 100 "lvalue" olarak geldi.
	std::cout << "\n--- Ýþte geliyor. Integer(int) ---\n" << std::endl;
	Integer val{ 100 }; // Integer kopyalama
	std::cout << "\n--- Ýþte geliyor. Integer(const Integer&), Employee(std::string &&name,  Integer &&id) ---\n" << std::endl;
	Employee emp3{ std::string{"Mustafa"}, val }; // referans kopyalama
	std::cout << "\n--- Ýþte geliyor. Integer(int), Integer(int&&), Employee(std::string &&name,  Integer &&id), ~Integer() ---\n" << std::endl;
	auto emp = Create("Mustafa", Integer{ 100 });

	std::getchar();
	return 0; 
}// çýkýþta bir daha Integer val{ 100 }; gelen yýkýcý çalýþacak.
// Ayrýca yýkýcýsý çalýþmamýþ diðer objelerin yýkýcýsý çalýþacak.