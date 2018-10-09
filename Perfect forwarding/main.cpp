#include "Integer.h"
#include <iostream>
#include <string>
#include <locale>

/*

"  Perfect Forwarding "
C++ zordur ama ...
C++ diðer programlama dillerinin önüne geçtiði konu kopyalamaya karþý korumadýr. Kopyalama sayýsý program büyüdükçe azalýr. 
Kopyalama sayýsý azaldýkça hafýza ve CPU kullanýmý azalýr. Kod küçülür ve binary boyutu azalýr.
Bazen yüzlerce satýr kodu derleyici 10 satýr assembly koduna çevirebilir.

Sorun:
	Class oluþturularý yapýlýrken parametre olarak baþka bir class kullanmak doðal bir olaydýr.
	Fakat parametre olarak oluþturulan classlarýn yapýcý fonksiyonlarý da çalýþýrsa bir fonksiyon çaðýrmak isterken parametre tip sayýsý kadar fonksiyon çaðýrmýþ olacaðýz.
Çözüm:
	*Veri defalarca geçici kopyalanmýþ olacak. Veri kopyalanmasýný kaldýrmak üzere std::move(object) kullanýlabilir fakat bazýlarý özellikle kopyalama oluþturucusunu çaðýrýrsa
	mesela(aþaðýda var): " Employee emp1{ "Mustafa", Integer{100} }; " iþte sorun var demektir. Bu durumda dahi veri tipini saklayýp taþýyýcý oluþturucuyu kullanmak için.
	std::forward<T1>(object) kullanýlýr.
	*Veri std::forward<T1>(object) ile kopyalanmaz sadece taþýnýr. Rust dilinden haberiniz varsa "ownership" taþýnmýþ olur.
	
	Ayrýca fonksiyonunuz olduðunu kabul edin.
		template <typename T1, typename T2>
		void wrapper(T1& e1, T2& e2) { func(e1, e2); }
	Alacaðýnýz saçma hatalar bunlar olacaktýr.
		wrapper(42, 3.14f);                  // error: invalid initialization of
											//        non-const reference from
											//        an rvalue

		wrapper(i, foo_returning_float());   // same error

not1: Visual Studio 2017 Integer classýný tanýmýyor ama derleme ve hata ayýklamada sorun çýkarmýyor. Bir tür hata olsa gerek.
not2: Visual Studio 2017 C++ derleyicisi son sürümünde optimizasyonu ilerletmiþti. Bu sebeple kopyalama oluþturucularý yerine taþýyýcý oluþturucularý görürseniz þaþmayýn.
Derleme optimizasyonu hafýza ve hýzý en iyi hale getirmek üzerine yapýlýr. Hýz konusunda optimizasyon denilen þey aslýnda daha az iþ yaptýrmak üzerinedir.
*/

class Employee {
	std::string m_Name;
	Integer m_Id;
public:
	Employee(const std::string &name, const Integer &id) : m_Name{ name }, m_Id{ id } { // Referans kopyalayýcý oluþturucu
		std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl; 
	}
	//template<typename T1, typename T2> // Bu fonksiyon 
	//Employee(T1 &&name, T2 &&id) : m_Name{ (name) }, m_Id{ (id) } { // taþýyýcý oluþturucu. objeyi hafýza da taþýmaya yarar.
	//	std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	//}
	template<typename T1, typename T2>
	Employee(T1 &&name,  T2 &&id) :	m_Name{ std::forward<T2>(name) }, m_Id{ std::forward<T2>(id) } { // taþýyýcý oluþturucu. objeyi hafýza da taþýmaya yarar.
		std::cout << "Employee(std::string &&name,  Integer &&id)" << std::endl;
	}
};
template<typename T1, typename T2>
Employee *Create(T1 && a, T2 &&b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	setlocale(LC_ALL,"Turkish");
	std::cout << "\n--- Ýþte geliyor. Integer(int), Employee(std::string &&name,  Integer &&id) ---\n" << std::endl;
	std::string name = "Mustafa"; // "lvalue"
	Employee emp2{ name, 100 }; // bir kopyalama ve bir taþýma çalýþtý. 2 fonksiyon aktif. Bir nebze daha iyi. 100 "lvalue" olarak geldi.
	std::cout << "\n--- Ýþte geliyor. Integer(int), Integer(int&&), Employee(std::string &&name,  Integer &&id), ~Integer() ---\n" << std::endl;
	Employee emp1{ "Mustafa", Integer{100} }; // önce kopyaladý, sonra hareket ettirdi. 4 fonksiyon çalýþtý. Ýstenen durum deðil.
	//std::cout << "\n--- Ýþte geliyor. ---\n" << std::endl;
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