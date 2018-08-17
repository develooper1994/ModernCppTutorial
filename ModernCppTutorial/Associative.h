#include "stdafx.h"
#include "customHeaders.h"
#include "stdheaders.h"
#ifndef Associative_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define Associative_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
/*
Sequential veri tiplerinden farký bu veriler sýralý verilerdir. Sýralý olmasý aramayý kolaylaþtýrýyor
ama veri ilave etmeyi zorlaþtýrýyor çünkü tekrar ve tekrar sýralanmasý gerekiyor.
veri yapýlarýnýn çeþitli durumlardaki performanslarýni internette karþýlaþtýrýlmýþtý. lütfen bakýnýz.
lütfen https://en.cppreference.com sayfasýndan ayrýntýlarýna bakýn. Bu yapýlarý anlatmaya kalkarsam çok zaman
geçiririz.
*/

static void setTanýmý() {
	/*
	set tipi matematikteki küme sistemidir. elemanlarý otomatik sýralar. ayný elemanýn ikincisini tutmaz.
	*/
	std::set<int> set1{ 5,4,3,2,1,1 };
	std::cout << "Size : " << set1.size() << std::endl;

	// deðer ekle
	set1.insert(0);
	std::cout << "Size insert(0) sonrasý : " << set1.size() << std::endl;
	set1.insert(5); // ayný elemanýn ikincisini eklemeye çalýþýyorum ama eklemez.
	std::cout << "Size insert(5) sonrasý : " << set1.size() << std::endl; // boyut deðiþti mi? hayýr.

	// std::cout << set1[0] << "\n"; // forward_list gibi çalýþmaz. iteratör kullanabiliriz.

	// iterator kullanabiliriz.
	std::set<int>::iterator it = set1.begin();
	it++;

	std::cout << "2nd : " << *it << "\n";

	// 5 deðerini sil
	set1.erase(5);

	// son elemaný sil
	it = set1.end();
	std::advance(it, -2);
	set1.erase(it, set1.end());

	// birden fazla deðer kaydet.
	std::vector<int> arr{ 6,7,8,9 };
	set1.insert(arr.begin(), arr.end());

	// find konum yani iteratör bilgisini yollar. Sonra iteratör ile deðer çekilebilir.
	auto val = set1.find(6);
	std::cout << "Found : " << *val << "\n";

	// hafýzadaki 8. konumu verir.
	auto eight = set1.lower_bound(8);
	std::cout << "8 : " << *eight << "\n";

	// hafýzadaki 8+1. konumu verir.
	auto nine = set1.upper_bound(8);
	std::cout << "9 : " << *nine << "\n";

	// set1 ve set2 deðiþ tokuþ et.
	std::set<int> set2{ 10,11 };
	set1.swap(set2); // artýk { 10, 11 } oldu.

	// boþ mu? kontrol et.
	if (!set1.empty()) {
		printAll(set1);
	}

}

static void multisetTanýmý() {
	// ----- MULTISET -----
	// elemanlarý sýralar, ayný elemanýn ikincisini saklar ve diðer tüm özellikleri set ile aynýdýr.
	std::multiset<int> mset1{ 1,1,2,3,4 };

	// eleman ekle.
	mset1.insert(4);
	mset1.insert(0);

	if (!mset1.empty()) {
		printAll(mset1);
	}

}

static void mapTanýmý() {
	// ----- MAP -----
	// Key<->value ikilisi þeklinde saklama yapar. Ayný elemandan ikincisini kutmaz. Elemandan kastým anahtar.
	// python dictionary karþýlýðýdýr.
	/*
	pair map elemanýnýn liste olmayan halidir. Aslýnda basit bir struct yapýdýr. Kullanýþlýdýr.
		tempate<class Anahtar, class Deger>
		struct pair{
			Anahtar anahtar;
			Deger deger;
		};
	map ise bir pair listesidir ama ayný elemandan ikincisini tutmadýðýndan pair setidir.
	*/
	std::map<int, std::string> map1;

	// anahtarlarý ekle. not: Simpsons... :)
	map1.insert(std::pair <int, std::string>(1, "Bart"));
	map1.insert(std::pair <int, std::string>(2, "Lisa"));
	map1.insert(std::pair <int, std::string>(3, "Marge"));
	map1.insert(std::pair <int, std::string>(4, "Homer"));
	map1.insert(std::pair <int, std::string>(5, "Kristy"));

	// index deðil anahtarý, deðeri yazdýr. anahtar first, deðer second oluyor.
	auto match = map1.find(1); // iterator yollar.
	std::cout << match->second << "\n";

	// 1. eleman
	auto bart = map1.lower_bound(1);
	std::cout << "LB : " << bart->second << "\n";

	// 1(+1). eleman
	auto lisa = map1.upper_bound(1);
	std::cout << "UB : " << lisa->second << "\n";

	// Print elements with an iterator
	std::map<int, std::string>::iterator it2;
	for (it2 = map1.begin(); it2 != map1.end(); ++it2) {
		std::cout << "Key : " << it2->first << "\n"; // anahtar
		std::cout << "Value : " << it2->second << "\n"; // deðer
	}
	std::cout << "\n";
}

static void multimapTanýmý() {
	// ----- MULTIMAP -----
	// Ayný map gibi çalýþýr ama ayný elemandan ikincisini saklar. Elemandan kastým anahtar.
	std::multimap<int, std::string> mmap1;
	mmap1.insert(std::pair <int, std::string>(1, "Bart"));
	mmap1.insert(std::pair <int, std::string>(1, "Lisa")); // öenmli olan anahtar.
	mmap1.insert(std::pair <int, std::string>(2, "Lisa"));
	mmap1.insert(std::pair <int, std::string>(3, "Marge"));
	std::map<int, std::string>::iterator it3;
	for (it3 = mmap1.begin(); it3 != mmap1.end(); ++it3) {
		std::cout << "Key : " << it3->first << "\n";
		std::cout << "Value : " << it3->second << "\n";
	}
	std::cout << "\n";
}

// ----- CONTAINER ADAPTERS -----
// Zaten var olan veri türleri için davranýþ arayüzü sunar. Kendileri de veri türü gibi kullanýlabilir.
static void stackTanýmý() {
	// ----- STACK -----
	// LIFO(Last in First out) formatýnda veri arayüzüdür.
	std::stack<std::string> custs;
	custs.push("George");
	custs.push("Louise");
	custs.push("Florence");

	int size = custs.size(); // eleman sayýsý

	// boþ mu? kontrol et.
	if (!custs.empty()) {
		for (int i = 0; i < size; ++i) {
			std::cout << "top: "<< custs.top() << "\n"; // son elemaný verir ama silmez.
			custs.pop(); // son elemaný çýkar.
		}
	}
	std::cout << "\n";
}

static void queueTanýmý() {
	// ----- QUEUE -----
	// FIFO(First in First out) formatýnda veri arayüzüdür.

	// futurama :)
	std::queue<std::string> cast;
	cast.push("Zoidberg");
	cast.push("Bender");
	cast.push("Leela");
	int size2 = cast.size(); // eleman sayýsý

	// boþ mu? kontrol et.
	if (!cast.empty()) {
		for (int i = 0; i < size2; i++) {
			std::cout << cast.front() << "\n"; // ilk elemaný verir ama silmez.
			cast.pop(); // ilk elemaný çýkar.
		}
	}
	std::cout << "\n";
}

static void priorityQueue(){
	/* 
	Büyükten küçüðe sýralayan "queue" verisidir.
	sýralama iþlemini eleman ekleme sýrasýnda deðil.
	her yeri istendiðinde yeni maximumumu bularak yapar.
	*/
	std::priority_queue<int> nums;
	nums.push(4);
	nums.push(8);
	nums.push(5);
	auto size3 = nums.size();

	if (!nums.empty()) {
		for (int i = 0; i < size3; i++) {
			std::cout << nums.top() << "\n"; // ilk elemaný verir ama silmez.
			nums.pop(); // ilk elemaný çýkar.
		}
	}
	std::cout << "\n";
}

// ----- ENUMS -----
// programýn okunurluðunu arttýrmak üzere "integer" verilerini derleme sýrasýnda otomatik oluþturan yapýdýr.
static void enums() {
	
	enum color {red, green, blue}; // varsayýlan baþlama noktasý "0" dýr. red=0, green=1, blue=2
	enum rediculus {r=2, e=0, d=-5, c, l, s, u=7, u1, u2};
	enum day { Mon = 1, Tues, Wed, Thur, Fri = 5 }; // istenilen noktadan baþlayabilir ve devam ettirilebilir.

	enum day tuesday = Tues; // 2

	std::cout << "Tuesday is the " << tuesday << "nd day of the week\n";

	// Cycle through days
	for (int i = Mon; i <= Fri; i++)
		std::cout << i << "\n";
	std::cout << "\n";
}

#endif  // HEADER_FILE