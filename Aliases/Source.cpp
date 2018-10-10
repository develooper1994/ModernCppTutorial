#include <iostream>
#include <vector>
#include <list>

// Type Alias
// Kýsacasý uzun isimleri baþka bir ad ile adlandýrmaya yarýyor.

using ULL = unsigned long long;
using LL = long long;
using VLI = std::vector<std::list<int>>;

typedef std::vector < std::list<std::string>> Names; // cannot be templatize

template<typename T>
using Names = std::vector<std::list<T>>; // can be use with template

using Names = std::vector<std::list<std::string>>;

// fonksiyon pointerleri
// return const char * , parameter type(int);
typedef const char *(*PFN)(int); // Old C/C++ language.
using FuncPoint = const char *(*)(int); // New C++ 11 version

const char * GetErrorMessage(int errorNo) {
	return "Empty";
}

void ShowError(FuncPoint pfn){
	
}

int main() {
	Names names;
	Names nnames;

	FuncPoint pfn = GetErrorMessage;
	ShowError(pfn);
	return 0;
}
