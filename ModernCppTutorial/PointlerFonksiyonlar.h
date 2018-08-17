#pragma once
// ----------------- PointlerFonksiyonlar -----------------
/*
https://en.cppreference.com/w/cpp/language/storage_duration
auto - automatic storage duration. (until C++11)
register - automatic storage duration. Also hints to the compiler to place the object in the processor's register. (deprecated) (until C++17)
static - static or thread storage duration and internal linkage. ***
extern - static or thread storage duration and external linkage. ***
thread_local - thread storage duration. (since C++11)
*/

static void assignByValue(int sayý) { sayý = 11; }
static int returnByValue(int sayý) { sayý = 15; return sayý; } // return kullanýlmazsa uyarý vermeden derleme duruyor. Düzeltilecektir.
static void assignByPointer(int* sayý) { *sayý = 22; }
static void assignByRef(int& sayý) { sayý = 33; }
static void yazacak(int a) { printf("Value of a is %d\n", a); }
static bool compare(const void * a, const void * b) { return (*(int*)a == *(int*)b); }
static int search(void *arr, int arr_size, int ele_size, void *x, bool compare(const void *, const void *)) {
	char *ptr = (char *)arr;
	int i;
	for (i = 0; i<arr_size; i++)
		if (compare(ptr + i * ele_size, x)) return i; // overflow hatasý çýkmasý muhtemel. pointer kullanmak tehlikeli. derleyici uyardý.
	// eleman bulunmaz ise.
	return -1;
}
// Eski C dili.
// Yapabileceðimizin kanýtýdýr.
static std::vector<int> RangePython(int begin = 0, int end = 10, int stepper = 1)
{
	int i = begin;
	std::vector<int> range;
	while (i <= end) {
		range.push_back(i);
		i += stepper;
	}
	return range;
}
typedef std::vector<int>(*myFuncPoint)(int, int, int);
static void yazacakFunc(int be, int e, int st, myFuncPoint funp) {
	// ana fonksiyonda varsayýlan parametre ekledikten sonra yeniden varsayýlan parametre vermeyi desteklemiyor.
	auto temp = (*funp)(be, e, st);
	for (auto& i : temp)
		printf("Deðer: %d\n", i);
}
// C++ þekli
template<typename Functor>
static void f(Functor functor)
{
	cout << functor(10) << endl;
}