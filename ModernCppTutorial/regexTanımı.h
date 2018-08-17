#include "stdafx.h"
#ifndef regexTanýmý_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define regexTanýmý_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
static void PrintMatches(std::string str, std::regex reg) {
	std::smatch matches;
	std::cout << std::boolalpha;
	while (std::regex_search(str,matches,reg))
	{
		ekranayaz << "eþleþme hazýr: " << matches.ready() << std::endl;
		ekranayaz << "eþleþme yok : " << matches.empty() << std::endl;
		ekranayaz << "eþleþme sayýsý : " << matches.size() << std::endl;
		ekranayaz << "matches.str(1) : " << matches.str(1) << std::endl;
		str = matches.suffix().str();
		ekranayaz << "matchler elenmiþ hali : " << str << std::endl;
	}
	yenisatýryaz;
}

void PrintMatches2(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);// ilk eþleþmeyi tutar.
	std::sregex_iterator lastMatch; // baþka varsa onlarý tutar.

	// sonuncuya eþit ise dööngüden çýkar. demekki daha yoktur.
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		std::cout << match.str() << std::endl;
		currentMatch++;
	}
	yenisatýryaz;
}

static void PrintMatches3(std::string str, std::regex reg) {
	auto words_begin = std::sregex_iterator(str.begin(), str.end(), reg);
	auto words_end = std::sregex_iterator();
	std::cout << "Bulundu:  " << std::distance(words_begin, words_end) << " words\n";

	const int N = 6;
	std::cout << N << "den uzun kelimelerin karakterleri:\n";
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		if (match_str.size() > N) {
			std::cout << "  " << match_str << '\n';
		}
	}






}

static void regex1() {
	auto regexilk = []() {
		std::string str = "The ape was at the apex";
		std::smatch matches; // string match
		/* ape ve apex yakalamak istiyorsam
		* "(" ile baþlar yani "(ape" ile baþlar.
		* "[]" eþleþecek karakterler demektir.
		* "^" not ifadesidir.
		* "[^ ]" not ifadesinden sonra bir boþluk koyuyorumki boþluk olmayanlarý eþleþtirsin.
		* "?" match için zorunlu deðildir. bu iþaret konmaz ise eþleþme yok diye geri döner.
		* "[^ ]?)" boþluk olmasýn ama þart deðil, boþlukta olabilir.
		* "(ape[^ ]?)" ape ile baþla, boþluk olmasýn ama þart deðil, boþlukta olabilir ve ")" ile iþlemi bitir.
		*/
		std::regex reg("(ape[^ ]?)"); 
		PrintMatches(str,reg);
	};

	auto regexikinci = []() {
		std::string str2 = "I picked the pickle";
		// Match (+) 1 or more of anything not a space
		/*
		* "(pick" pick ile baþla
		* "+" bir veya daha fazla
		* "([^ ]+)" bir veya daha fazla boþluk istemiyorum.
		* "([^ ]+)?)"  bir veya daha fazla boþluk istemiyorum ve þart olmasý ama þart deðil, þart da olabilir.

		*/
		std::regex reg2("(pick([^ ]+)?)");
		PrintMatches2(str2, reg2);
	};
	
	/*
	regexilk();
	regexikinci();
	*/

}


#endif  // HEADER_FILE
