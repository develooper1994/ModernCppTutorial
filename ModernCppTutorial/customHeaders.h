#ifndef customHeaders_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define customHeaders_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
#include <fmt/printf.h>
/*
The two int variables are defined in the header file. This means that every source file which includes the header will contain their definition (header inclusion is purely textual). The of course leads to multiple definition errors.
You have several options to fix this.
Make the variables static (static int WIDTH = 1024;). They will still exist in each source file, but their definitions will not be visible outside of the source file.
Turn their definitions into declarations by using extern (extern int WIDTH;) and put the definition into one source file: int WIDTH = 1024;.
Probably the best option: make the variables const (const int WIDTH = 1024;). This makes them static implicitly, and also allows them to be used as compile-time constants, allowing the compiler to use their value directly instead of issuing code to read it from the variable etc.
*/

// Sakýn define ile sayý ile niteleme yapmayýn
// #define 2 ' //yanlýþþþþ
#define ekranayaz std::cout //eski ama hala iþe yarýyor.
#define yenisatýr std::endl // "\n" ayný iþi görse de her sistemde farklý olabilir. programý evrenselleþtirmek üzere kullanýyorum.
#define yenisatýryaz ekranayaz << yenisatýr
#define fonksiyonuyaz(fonk) std::cout << "---"<< fonk <<" fonksiyonu ---" << std::endl
#define boolyaz(ifade) std::boolalpha << ifade << std::noboolalpha
#define strend std::string::npos

// bool found = (std::find(my_list.begin(), my_list.end(), my_var) != my_list.end()); // python "in" karþýlýðý
// stl veri yapýlarýyla çalýþýlýr.
#define varmý(data,aranan) (std::find(data.begin(), data.end(), aranan) != data.end())
#define ThreadSleep(sec) std::this_thread::sleep_for(std::chrono::seconds(sec));

// Yararlý fonksiyonlar.
template<typename T>
inline auto printAll (T data) -> void { // dönüþ tipi "void" olarak belirledim. artýk derleme hatasý yok.
	for (auto& d : data)
		std::cout << d << " ";
	yenisatýryaz;
};

template<typename T>
void JoinAll(T threadVect) {
	for (auto& t : threadVect)
		if (t.joinable()) // yeni versiyonda bu fonksiyon kullanýlmaz ise _INVALID_ARGUMENT exception yolluyor.
			t.join();
}

// begin ve end stl içinde tanýmlý özel adlardýr. Böyle özel adlarý kullanmak
// derleme hatasýna sebep olur.
#define basla {
#define bitir }
#define bitti ;
#define inn :

// mantýksal operatorler
#define and &&
#define or ||
#define not !

// artýr <-> azalt
#define increase ++
#define decrease --

// döngü ifadeleri
#define looper while(true)
#define foreverer loop

// typedef olacak tipler
#define ia inline auto //typedef aksine # define satýr dýþý nitelemeye izin verir.
#define isa inline static auto
#define iea inline extern auto

// typedef olacak constexpr tipler
#define ceia constexpr inline auto
#define ceisa constexpr inline static auto
#define ceiea constexpr inline extern auto

// rasyonel sayý tipleri
#define float32 float 
#define float32_t float
#define lfloat32 long float
#define lfloat32_t long float
#define lfloat long float
#define lfloat_t long float

#define float64 double 
#define float64_t double
#define lfloat64 long float
#define lfloat64_t long float

using intVec = std::vector<int32_t>;


// iþte benim tanýmladýðým baþlýk dosyalarý
// baþlýk dosyalarýna istediðinizi yazabilirsiniz. basitçe dahil edilecektir.
// main dosyasý sadeleþti.
#include "PointlerFonksiyonlar.h" // include iþlemi text bazýnda oldukça basit bir iþlemdir. Bende konfigürasyonu basit tuttum.
#include "functionalStyle.h"
using functionalStyle::MultBy2;
using functionalStyle::DoMath;
using functionalStyle::MultBy3;
using functionalStyle::IsItOdd;
using functionalStyle::ChangeList;
using functionalStyle::GetHAndTList;
using functionalStyle::GetNumberOfMatches;
#include "pipeStyle.h"
#include "initialize_twister.h"
#include "generateRandom.h"

// classlar
#include "Animal.h"
#include "Dog.h"
#include "kutucuk.h"
#include "polyTemplateClass.h"
// #include "threadBasic.h"

// Templates
#include "TemplateStyle.h"

// diðer derslerin kodlarý
#include "Associative.h"
#include "regexTanýmý.h"

#include "dersler.h"


#endif  // HEADER_FILE