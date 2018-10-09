#include "Integer.h"
#include <iostream>
#include <string>
#include <locale>

/*

"  Perfect Forwarding "
C++ zordur ama ...
C++ di�er programlama dillerinin �n�ne ge�ti�i konu kopyalamaya kar�� korumad�r. Kopyalama say�s� program b�y�d�k�e azal�r. 
Kopyalama say�s� azald�k�a haf�za ve CPU kullan�m� azal�r. Kod k���l�r ve binary boyutu azal�r.
Bazen y�zlerce sat�r kodu derleyici 10 sat�r assembly koduna �evirebilir.

Sorun:
	Class olu�turular� yap�l�rken parametre olarak ba�ka bir class kullanmak do�al bir olayd�r.
	Fakat parametre olarak olu�turulan classlar�n yap�c� fonksiyonlar� da �al���rsa bir fonksiyon �a��rmak isterken parametre tip say�s� kadar fonksiyon �a��rm�� olaca��z.
��z�m:
	*Veri defalarca ge�ici kopyalanm�� olacak. Veri kopyalanmas�n� kald�rmak �zere std::move(object) kullan�labilir fakat baz�lar� �zellikle kopyalama olu�turucusunu �a��r�rsa
	mesela(a�a��da var): " Employee emp1{ "Mustafa", Integer{100} }; " i�te sorun var demektir. Bu durumda dahi veri tipini saklay�p ta��y�c� olu�turucuyu kullanmak i�in.
	std::forward<T1>(object) kullan�l�r.
	*Veri std::forward<T1>(object) ile kopyalanmaz sadece ta��n�r. Rust dilinden haberiniz varsa "ownership" ta��nm�� olur.
	
	Ayr�ca fonksiyonunuz oldu�unu kabul edin.
		template <typename T1, typename T2>
		void wrapper(T1& e1, T2& e2) { func(e1, e2); }
	Alaca��n�z sa�ma hatalar bunlar olacakt�r.
		wrapper(42, 3.14f);                  // error: invalid initialization of
											//        non-const reference from
											//        an rvalue

		wrapper(i, foo_returning_float());   // same error

not1: Visual Studio 2017 Integer class�n� tan�m�yor ama derleme ve hata ay�klamada sorun ��karm�yor. Bir t�r hata olsa gerek.
not2: Visual Studio 2017 C++ derleyicisi son s�r�m�nde optimizasyonu ilerletmi�ti. Bu sebeple kopyalama olu�turucular� yerine ta��y�c� olu�turucular� g�r�rseniz �a�may�n.
Derleme optimizasyonu haf�za ve h�z� en iyi hale getirmek �zerine yap�l�r. H�z konusunda optimizasyon denilen �ey asl�nda daha az i� yapt�rmak �zerinedir.
*/

class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	Employee(const std::string &name, const Integer &id) : m_Name{ name }, m_Id{ id } { // Referans kopyalay�c� olu�turucu
		std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	}
	//template<typename T1, typename T2> // Bu fonksiyon 
	//Employee(T1 &&name, T2 &&id) : m_Name{ (name) }, m_Id{ (id) } { // ta��y�c� olu�turucu. objeyi haf�za da ta��maya yarar.
	//	std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	//}
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :	m_Name{ std::forward<T2>(name) }, m_Id{ std::forward<T2>(id) } { // ta��y�c� olu�turucu. objeyi haf�za da ta��maya yarar.
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	}
};
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	setlocale(LC_ALL,"Turkish");
	std::cout << "\n--- ��te geliyor. Integer(int), Employee(std::string &&name,  Integer &&id) ---\n" << std::endl;
	std::string name = "Mustafa"; // "lvalue"
	Employee emp2{ name, 100 }; // bir kopyalama ve bir ta��ma �al��t�. 2 fonksiyon aktif. Bir nebze daha iyi. 100 "lvalue" olarak geldi.
	std::cout << "\n--- ��te geliyor. Integer(int), Integer(int&&), Employee(std::string &&name,  Integer &&id), ~Integer() ---\n" << std::endl;
	Employee emp1{ "Mustafa", Integer{100} }; // �nce kopyalad�, sonra hareket ettirdi. 4 fonksiyon �al��t�. �stenen durum de�il.
	//std::cout << "\n--- ��te geliyor. ---\n" << std::endl;
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