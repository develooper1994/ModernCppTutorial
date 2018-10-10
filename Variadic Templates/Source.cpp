#include <iostream>
#include "Integer.h"

//Works only for homogenous data types
template<typename T>
void Print(std::initializer_list<T> args) {
	for (const auto &x : args) {
		std::cout << x << " ";
	}
}

// Base case
void Print(){
	std::cout << std::endl;
}

//Template parameter pack
template<typename T, typename...Params>
//Function parameter pack
void Print(T &&a, Params&&... args) {
	std::cout << sizeof...(args) << std::endl;
	std::cout << sizeof...(Params) << std::endl;
	std::cout << a;
	if (sizeof...(args) != 0) {
		std::cout << ",";
	}
	//We can forward a function parameter pack
	Print(std::forward<Params>(args)...);
}

/* // Buradaki bazý yeni c++ 17 özellikleri sadece gcc ve clang son versiyonlarýnda geçerlidir. Bu yüzden fazla birþey beklemeyin.
// Qt windows üzerinde gcc 7.3.0 kullanabiliyor.
template <typename Type, Type value> constexpr Type constant = value;
constexpr auto const IntConstant42 = constant<int, 42>;

template <auto value> constexpr auto constant = value;
constexpr auto const IntConstant42 = constant<42>;

template<std::size_t SIZE>
class Foo {};

template <template<auto> class T, auto K>
auto extractSize(const T<K>&) {
	return K;
}
*/

int main() {
	Print({ 1,2,3,4 });
	Print(1, 2.5, 3, "4");
	Integer val{ 1 };
	Print(0, val, Integer{ 2 });
	return 0;

}
/*
1. Print(1, 2.5, 3, "4") ;
2. Print(2.5, 3, "4") ;
3. Print(3, "4") ;
4. Print("4") ;
5. Print() ;
*/
