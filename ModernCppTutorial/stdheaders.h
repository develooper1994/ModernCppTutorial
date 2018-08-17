#ifndef stdheaders_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define stdheaders_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif

#include "targetver.h"

// eski c dili kütüphaneleri
#include <cstdio>
#include <tchar.h>
#include <wchar.h>
#include <clocale>
#include <ctime>

//#include <Windows.h> // windows c api

// her türlü girdi çýktý ve string
#include <iostream>
#include <cstdlib>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream> // File I/O

// integer türleri ve sýnýrlarý
#include <cstdint>
#include <limits>

// çeþitli fonksiyonlar ve algoritmalar
#include <functional>
#include <algorithm>
#include <iterator>

// Sequential containers
#include <array>
#include <vector>
#include <tuple>
#include <list>
#include <deque>
#include <forward_list>

// Associative container 
#include <map>
#include <set>
#include <stack>
#include <queue>

// rastgele sayýlar ve matematik
#include <random>
#include <chrono>
#include <cmath> // math.h ayný ifade.
#include <numeric>

// thread ve araçlarý
#include <thread>
#include <mutex>
#include <future>

// ara araçlar
#include <utility>
#include <memory>

// regular expression
#include <regex>


using std::cout;
using std::endl;
using std::cin;
using std::getline;

using namespace std::string_literals;
using std::string;
using std::array;
using std::vector;
using std::tuple;


#endif  // HEADER_FILE