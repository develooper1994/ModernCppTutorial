#include "stdafx.h"
#include "customHeaders.h"
#include "stdheaders.h"
// Dikkat! bu header dosyasý functionalStyle.h içinde dahil edildi. Sakýn böyle birþey yapmayýn. Eðitim amaçlýdýr.
#include "functionalStyle.h"

#ifndef YararlýFonksiyonlar_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define YararlýFonksiyonlar_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif


/*
namespace functionalStyle::YararlýFonksiyonlar {
// Lambda fonksiyonlarý içine "[]" statik tanýmlý baþka bir fonksiyon alamaz.
inline auto printAll = [](auto data) -> void { // dönüþ tipi "void" olarak belirledim. artýk derleme hatasý yok.
for (auto d : data)
std::cout << d << " ";
yenisatýryaz;
};
inline auto GenerateRandVec = [](int numOfNums, int min, int max) {
std::vector<int> vecValues;
// Seed the random number generator
srand(time(NULL));
int i = 0, randVal = 0;
while (i < numOfNums) {
randVal = min + std::rand() % ((max + 1) - min);
vecValues.push_back(randVal);
i++;
}
return vecValues;
};

inline auto StringToVector = [](std::string theString, char separator) {
std::vector<std::string> vecsWords;
std::stringstream ss(theString);
std::string sIndivStr;
while (getline(ss, sIndivStr, separator))
vecsWords.push_back(sIndivStr);
return vecsWords;
};

inline std::vector<int> Range(int start, int max, int step) {
int i = start;
std::vector<int> range;
while (i <= max) {
range.push_back(i);
i += step;
}
return range;
};

inline bool IsPrime (int num) {
for (auto n : Range(2, num - 1, 1))
if ((num % n) == 0)
return false;
return true;
};
inline auto GetPrimes = [](int maxNum) {
std::vector<int> vecPrimes;
for (auto x : Range(2, maxNum, 1))
if (IsPrime(x))
vecPrimes.push_back(x);
return vecPrimes;
};

inline auto strMatches(std::string str, std::string substr) {
std::vector<int> matchingIndexes;
auto index = str.find(substr, 0);
while (index != std::string::npos) {
matchingIndexes.push_back(index);
index = str.find(substr, index + 1);
}
return matchingIndexes;
};
inline auto strReplace = [=](std::string str, std::string substr, std::string newstr) {
// lambda kuralý olarak strMatches fonksiyonunu bu [strMatches] ile lambda fonksiyonunun içine kopyaladým.
std::vector<int> matched = strMatches(str, substr); // eðer eþleþme olmazsa .size 0 gönderecek.
if (matched.size() != 0) {
auto sizeDiff = matched.size() - substr.size();
auto looped = 0;
for (auto index : matched)
str.replace(index + looped * sizeDiff, substr.size(), newstr); looped;
}
return str;
};

}
*/

int GetRandom(int);

static std::string GetTime() {
	auto nowTime = std::chrono::system_clock::now();
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
	char str[26];
	ctime_s(str, sizeof str, &sleepTime); // tavsiye edilen fonksiyon.
	return std::string(str);

	// return std::ctime(reinterpret_cast< const time_t* >((&sleepTime))); //ctime eski ve güvenli olmayan bir fonksiyon.
}

static void foo()
{
	std::cout << "foo()" << std::endl;
}

static void bar(int x)
{
	std::cout << "bar()" << std::endl;
}
static void task1(string msg)
{
	cout << "task1 says: " << msg;
}
static void printThread(int son = 20) {
	auto arr = RangePython(1, son, 1);
	auto theadid = std::this_thread::get_id();
	for (auto& d : arr)
		std::cout << theadid << ": " << d << ", ";
	yenisatýryaz;
}
static void ExecuteThread(int id) {
	/* //generateRandom.h içinde mevcut
	auto GetRandom = [](int max) {
	srand(time(NULL));
	return rand() % max;
	};*/

	// Þimdiki zaman saniye cinsinden
	auto now = std::chrono::system_clock::now();

	// iþlem yapýlabilir ve anlaþýlýr zaman tipine dönüþtürür.
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(now);

	// bilgisayar zamanýný yöresel anlaþýlabilir zamana dönüþtürür.
	tm myLocalTime;
	localtime_s(&myLocalTime, &sleepTime);
	// tm myLocalTime = *localtime(&sleepTime); // eski ve güvensiz.

	// tüm zamaný yazdýrýr.
	char str1[26];
	ctime_s(str1, sizeof str1, &sleepTime); // tavsiye edilen fonksiyon.
	std::cout << "Thread " << id << " Sleep Time : " << str1 << "\n";

	// Zamaný birimlerine ayýrýr.
	std::cout << "Ay : " << myLocalTime.tm_mon << "\n";
	std::cout << "Gün : " << myLocalTime.tm_mday << "\n";
	std::cout << "Yýl : " << myLocalTime.tm_year + 1900 << "\n";
	std::cout << "Saat : " << myLocalTime.tm_hour << "\n";
	std::cout << "Dakika : " << myLocalTime.tm_min << "\n";
	std::cout << "Saniye : " << myLocalTime.tm_sec << "\n\n";

	// thread en fazla 3 saniyeliðine durur.
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
	now = std::chrono::system_clock::now();
	sleepTime = std::chrono::system_clock::to_time_t(now);
	char str2[26];
	ctime_s(str2, sizeof str2, &sleepTime); // tavsiye edilen fonksiyon.
	std::cout << "Thread " << id << " Awake Time : " << str2 << "\n";
}

static std::mutex acctLock;
static double HesaptakiPara = 100;
static void GetMoney(int id, double paraCekme) {
	std::lock_guard<std::mutex> HesaptakiParaLock(acctLock); // otomatik eriþim korumasý.
	// HesaptakiParaLock.lock();
	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << paraCekme << " tl para çekiyorsunuz. " << GetTime() << std::endl;

	if (HesaptakiPara - paraCekme >= 0)
	{
		HesaptakiPara -= paraCekme;
		std::cout << "Hesaptaki para: " << HesaptakiPara << std::endl;
	}
	else
	{
		std::cout << "hesabýnýzda yeteri kadar para bulunmuyor. \n Þuan da bulunan miktar: " << HesaptakiPara
			<< std::endl;
	}
	//HesaptakiParaLock.unlock();
}

static void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
	// Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2) {
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) break;
			else if ((y + 1) == x) vect.push_back(x);
		}
	}
}


//static std::mutex vectLock; // global olsa iyi olur
static std::vector<unsigned int> primeVect;
static void FindPrimesWithLock(unsigned int start, unsigned int end) {
	// allocate at refered vector
	// Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2) {
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) break;
			else if ((y + 1) == x) {
				std::lock_guard<std::mutex> mulock(); // lock to senkronize
				primeVect.push_back(x);
			}
		}
	}
}

static void FindPrimesWithThreads(unsigned int start, unsigned int end, const unsigned int numThreads=2) {
	std::vector<std::thread> threadVect(numThreads);
	//std::thread threadVect[numThreads];

	// farklý asal sayýlarý hesaplamak üzere hesaplamayý threadlere paylaþtýrýyorum.
	// 10 thread var ve 1-100 arasý asal sayý elde etmek istersem
	// ilk thread 1-9, ikinci thread 10-19, ... arasýný alýr.
	unsigned int threadSpread = end / numThreads;
	unsigned int newEnd = start + threadSpread - 1;

	// her threadin hesaplayacaðý aralýðý veriyorum.
	for (unsigned int x = 0; x < numThreads; ++x) {
		threadVect.emplace_back(FindPrimesWithLock, start, newEnd); // fonksiyonu ve parametrelerini alýr sonucu vektöre kaydedir.
		//threadVect[x] = std::thread(FindPrimesWithLock, start, newEnd);
		start += threadSpread;
		newEnd += threadSpread;
	}

	// threadler ana thread ile uyumlu hale geliyor.
	for (auto& t : threadVect)
		if(t.joinable()) // yeni versiyonda bu fonksiyon kullanýlmaz ise _INVALID_ARGUMENT exception yolluyor.
			t.join();
}



#endif  // HEADER_FILE