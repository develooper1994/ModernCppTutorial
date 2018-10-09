#include "Integer.h"
#include <iostream>
#include <string>
#include <locale>

/*
Sorun:
	Class olu�turular� yap�l�rken sorunlar parametre olarak ba�ka bir class kullanmak do�al bir olad�r.
	Fakat parametre olarak olu�turulan classlar�n yap�c� fonksiyonlar� da �al���rsa bir fonksiyon �a��rmak isterken parametre tip say�s� kadar fonksiyon �a��rm�� olaca��z.
	Veri defalarca kopyalanm�� olacak. Veri kopyalanmas�n� kald�rmak �zere std::move(object) kullan�labilir fakat. Employee

*/

class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	Employee(const std::string &name, const Integer &id) : m_Name{ name }, m_Id{ id } { // Referans kopyalay�c� olu�turucu
		std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	}
	template<typename T1, typename T2>
	Employee(T1 &&name, T2 &&id) : m_Name{ (name) }, m_Id{ (id) } { // ta��y�c� olu�turucu. objeyi haf�za da ta��maya yarar.
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	}
	//template<typename T1, typename T2>
	//Employee(T1 &&name,  T2 &&id) :	m_Name{ std::forward<T1>(name) }, m_Id{ std::forward<T2>(id) } { // ta��y�c� olu�turucu. objeyi haf�za da ta��maya yarar.
	//	std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	//}
};
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	setlocale(LC_ALL,"Turkish");
	std::cout << "\n--- ��te geliyor. Integer(int), Integer(int&&), Employee(std::string &&name,  Integer &&id), ~Integer() ---\n" << std::endl;
	Employee emp1{ "Mustafa", Integer{100} }; // �nce kopyalad�, sonra hareket ettirdi. 4 fonksiyon �al��t�. �stenen durum de�il.
	std::string name = "Umar"; // "lvalue"
	//std::cout << "\n--- ��te geliyor. ---\n" << std::endl;
	std::cout << "\n--- ��te geliyor. Integer(int), Employee(std::string &&name,  Integer &&id) ---\n" << std::endl;
	Employee emp2{ name, 100 }; // bir kopyalama ve bir ta��ma �al��t�. 2 fonksiyon aktif. Bir nebze daha iyi. 100 "lvalue" olarak geldi.
	std::cout << "\n--- ��te geliyor. Integer(int) ---\n" << std::endl;
	Integer val{ 100 }; // Integer kopyalama
	std::cout << "\n--- ��te geliyor. Integer(const Integer&), Employee(std::string &&name,  Integer &&id) ---\n" << std::endl;
	Employee emp3{ std::string{"Mustafa"}, val }; // referans kopyalama
	std::cout << "\n--- ��te geliyor. Integer(int), Integer(int&&), Employee(std::string &&name,  Integer &&id), ~Integer() ---\n" << std::endl;
	auto emp = Create("Mustafa", Integer{ 100 });

	std::getchar();
	return 0; 
}// ��k��ta bir daha Integer val{ 100 }; gelen y�k�c� �al��acak.
// Ayr�ca y�k�c�s� �al��mam�� di�er objelerin y�k�c�s� �al��acak.