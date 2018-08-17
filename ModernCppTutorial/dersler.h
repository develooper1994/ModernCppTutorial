#ifndef dersler_H // eski ve taþýnabilir usul header korumasý. Derleyici header dosyasýný defalarca 
#define dersler_H // dahil etmesini önler. Büyük projelerde önemli sorun teþkil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
/*
 Ana dersler bu dosyada.

 Kaynaklarýmýn arasýnda
 en.cppreferance: https://en.cppreference.com/w/cpp/language // Cidden mükemmel bir kaynak
 isocpp: https://isocpp.org/
 Derek Banas: http://www.newthinktank.com/ . Derek Banas thank you.
*/
/*
Her seferinde std::cout yazmak zor geldiðinden bir takým makrolar tanýmladým.
*/

ia ilkadim(int argc, char** argv)
{   //unutmayýn biz artýk moderniz(auto) ;)

	std::cout << "Selam Millet. Türkçe karakterler: ÝÞÐÜÇýç" << std::endl;

	/*
	Sadece eskiden nasýl yapýlýyordu bu iþler göstermek üzere yapýyorum.
	Artýk python argparse gibi kütüphaneler kullanýlýyor.

	Ayrýca c/c++ ifadelerini beðenmezseniz öniþlemci ile kendinize göre
	deðiþtirin ama pek sevilen birþey deðildir.
	Akýllý þekillendiriciler ön iþlemci ile çalýþmýyor.
	*/
	if (argc != 1) ekranayaz << "komut sisteminde baðýmsýz deðiþken var." << yenisatýr bitti

		//hadi biraz döngü çalýþtýralým.
		for (size_t i = 0; i < argc; i++) basla
			std::cout << i << ". eleman= " << argv[i] << std::endl;
	bitir
}

ia temelVeriyapýlarý() {
	int g_irandNum = 0;
	const double giveMyPI = 3.142;
	bool yakýlýþlýmý = true; //modern cpp türkçe karakter kullanabiliyorum.
	char ilkharf = 'M';
	std::string biryazý = "64 bit architecture...";

	//modern c++ ile gelen literaller.
	int d = 42;
	int o = 052;
	int x = 0x2a;
	int X = 0X2A;
	int b = 0b101010; // C++14

	unsigned long long l1 = 18446744073709550592ull; // C++11
	unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14
	unsigned long long l3 = 1844'6744'0737'0955'0592uLL; // C++14
	unsigned long long l4 = 184467'440737'0'95505'92LLU; // C++14
														 //eski halleri yorumda. cstdint kütüphanesinde mevcut.
														 /*
														 signed char        int8_t;
														 short              int16_t;
														 int                int32_t;
														 long long          int64_t;
														 unsigned char      uint8_t;
														 unsigned short     uint16_t;
														 unsigned int       uint32_t;
														 unsigned long long uint64_t;
														 */
	uint16_t u16age = 44; //unsigned short int
	int16_t yarýçap = 200;
	int32_t günler = 7;
	long büyüktamsayýklar = 65241652; // :)
	float rasyonelsayý = 2.728; //float32
	double dahaRasyonelsayý = 5.96846549565496; // float iki katý
	long double çooookBüyük = 398652165.72686521465216; // hem virgülden önce hem virgülden sonra çok büyük.

	auto neolacak = true; // otomatik bool türüne dönüþtü.
	decltype(günler) neolacak2 = 777; // günler deðiþkeninin tipinde tanýmladým.

									  // std::cout fonksiyonu formatlý yazým yapmýyor.
									  // printf unicode desteklemiyor.
	printf("ilkharf=%c u16age=%d yarýçap=%5d çooookBüyük=%.3f biryazý=%s \n", ilkharf, u16age, yarýçap, çooookBüyük, "asdfg");

	// kaç byte istersen o kadar gösterir.
	std::cout << "sizeof(neolacak2)= " << sizeof(neolacak2) << std::endl;

	//Süslü parantezleri istediðiniz gibi kullanýn. Sonuçlarýný ileride anlatacaðým.
	{
		// limits kütüphanesinde hepsi var.
		std::cout << "min bool= " << std::numeric_limits<bool>::min() << std::endl;
		std::cout << "max bool= " << std::numeric_limits<bool>::max() << std::endl << std::endl;

		std::cout << "min uint16_t= " << std::numeric_limits<uint16_t>::min() << std::endl;
		std::cout << "max uint16_t= " << std::numeric_limits<uint16_t>::max() << std::endl << std::endl;

		std::cout << "min int16_t= " << std::numeric_limits<int16_t>::min() << std::endl;
		std::cout << "max int16_t= " << std::numeric_limits<int16_t>::max() << std::endl << std::endl;

		std::cout << "min int32_t= " << std::numeric_limits<int32_t>::min() << std::endl;
		std::cout << "max int32_t= " << std::numeric_limits<int32_t>::max() << std::endl << std::endl;
	}

	float32 fbig1 = 1.1111111111, fbig2 = fbig1, fbigsum = fbig1 + fbig2;
	printf(" hassasiyetle float yazdýrma= %.10f \n", fbigsum);

	float64 f64big1 = 1.11111111111111111111, f64big2 = 1.1111111111, f64bigsum = f64big1 + f64big2;
	printf(" hassasiyetle float yazdýrma= %.20f \n", f64bigsum);


}

ia stringÝþlemleri() {
	std::string biryazý("hele dur orada!"); //string tipi standart kütüphanede bulunuyor.
	fmt::printf("biryazý= %s \n", biryazý); //fmt kütüphanesi unicode destekler.

											//auto sorgu("1 sayýsýný gir"); // auto std::string objesi yerine char* tipine dönüþtürüyor.
	string sorgu("1 sayýsýný gir="), sNum1, sNum2;
	ekranayaz << sorgu;
	std::getline(std::cin, sNum1); // string olarak almayý garanti eder. belirlenen akýmdan bir satýr okur.
	ekranayaz << "2 sayýsýný gir=";
	std::getline(std::cin, sNum2);
	ekranayaz << yenisatýr;

	// stoi == string to integer ;). tahmin etmek zor deðil.
	auto nNum1 = std::stoi(sNum1),
		nNum2 = std::stoi(sNum2);

	yenisatýryaz;

	// kusura kalmazsanýz biraz matematik.
	printf("%d + %d= %d \n", nNum1, nNum2, nNum1 + nNum2);
	printf("%d - %d= %d \n", nNum1, nNum2, nNum1 - nNum2);
	printf("%d * %d= %d \n", nNum1, nNum2, nNum1 * nNum2);
	printf("%d / %d= %f \n", nNum1, nNum2, (float)nNum1 / (float)nNum2);
	printf("%d %% %d= %d \n", nNum1, nNum2, nNum1 % nNum2);

	{
		//ilk problem
		// km=mil*1.60934
		// kullanýdan mili alýp km çevirecek.

		std::string inputmil;
		double cMil, cKm;
		ekranayaz << "  --- Mil -> Km --- " << yenisatýr;
		ekranayaz << "Mil: " << yenisatýr;
		getline(std::cin, inputmil);
		cMil = std::stod(inputmil);
		ekranayaz << "Km: " << cMil * 1.60934 << yenisatýr;
	}


}

ia kararÝþlemleri() {
	std::string yaþ = "0";
	std::cout << "Yaþýný yaz= " << std::endl;
	getline(std::cin, yaþ);
	auto iyaþ = std::stoi(yaþ);

	if (iyaþ >= 1 and iyaþ <= 10) ekranayaz << "önemli doðum günü" << yenisatýr;
	else if (iyaþ >= 10 and iyaþ <= 20) ekranayaz << "daha az önemli doðum günü" << yenisatýr;
	else if (iyaþ >= 20 and iyaþ <= 50) ekranayaz << "önemli olmayan doðum günü" << yenisatýr;
	else if (iyaþ >= 50) ekranayaz << "olmasa da olur \n";
	else ekranayaz << "D'oh \n";
}

ia diziÝþlemleri() {
	/*
	Diziler boyutu tanýmlanýrken verilir ve deðiþmez
	fakat içindeki veriler deðiþtirilebilir(const deðilse)
	Her elemanýn tipi aynýdýr.

	Aslýnda dizi bir pointer tipidir. *(arrNum2+index*sizeof(decltype(arrNum2[0])))
	gibi bir eriþim saðlanabilir ama tavsiye edilmez. Derleyici arrNum3[index]
	kullanýmýnda bir takým kontroller yapabilir.

	STL array tipiyle dizi için gerekli iþlemleri toplamýþtýr.
	*/
	int arrNum[10] = { 1 };
	int arrNum2[] = { 1,2,3 };
	int arrNum3[5] = { 8,9 };

	std::cout << "1. value : " << arrNum3[0] << yenisatýr;
	arrNum3[0] = 5;
	std::cout << "1. value : " << arrNum3[0] << yenisatýr;
	//std::cout << "1. value : " << arrNum3[7] << yenisatýr; //hata vermez ama hatadýr.
	std::cout << "1. value : " << *(arrNum3 + 0 * sizeof(int)) << yenisatýr;
	//sizeof(arrNum3)/ sizeof(int) // dizi tipi her zaman int olmaz.
	std::cout << "Array size:" << sizeof(arrNum3) / sizeof(*arrNum3) << "\n"; //ilk elemanýnýn boyutunu kontrol eder.
	std::cout << "Array size(decltype):" << sizeof(arrNum3) / sizeof(decltype(arrNum3[0])) << "\n"; //ilk elemanýnýn tipinin boyutunu kontrol eder. Sanki daha iyi.

																									/*
																									* Modern c++ özelliklerini kullanabilmemizi saðlar.
																									* Otomatik paralleleþtirme yapabilmeyi mümkün kýlar.
																									* array.at() fonksiyonuyla sýnýr kontrolü gerçekleþtirebilir. Daha güvenli.
																									*/

																									//iteratörler ve stl üzerinde daha sonra üzerine konuþacaðýz.
	{
		typedef std::array<int, 5> defalarca;
		defalarca arr;
		arr.fill(3);
		arr[2] = 8;
		arr.at(4) = -2; // "bound check" sýnýr kontrolü. Güvenli eriþim
		arr[3] = 5;
		// arr.assign() // böyle bir fonksiyon yok.
		defalarca::pointer ptr = arr.data();
		std::cout << "arr.data():  " << *ptr << std::endl;
		defalarca::iterator it = arr.begin(); // normal iteratör
		std::cout << "const_iterator arr.begin(): " << *it << std::endl;
		defalarca::const_iterator it2 = arr.cbegin() + 2; // 2. eleman. constant iteratör
		std::cout << "const_iterator arr.begin()+2: " << *it2 << std::endl;

		// iteratörlerde azaltmaya girerseniz hata alýrsýnýz.
		// xutils kütüphanesi içinde azaltma iþlemi yasaklanmýþtýr.
		// tersten eriþim için ..._reverse_iteratörleri kullanýn.
		for (defalarca::const_reverse_iterator it3 = arr.rbegin(); it3 != arr.rend(); ++it3)
			std::cout << "rbegin ve rend: " << *it3 << std::endl;
		// crbegin ve crend constant reverse iteratör.
		// yani tersten eriþim.
	}
	{
		std::array<int, 3> a1{ { 1, 2, 3 } }; // double-braces required in C++11 (not in C++14)
		std::array<int, 3> a2 = { 1, 2, 3 };  // never required after =
		std::array<std::string, 2> a3 = { std::string("a"), "b" };

		// container operations are supported
		std::sort(a1.begin(), a1.end());
		std::reverse_copy(a2.begin(), a2.end(),
			std::ostream_iterator<int>(std::cout, " "));

		std::cout << '\n';

		// ranged for loop is supported
		for (const auto& s : a3)
			std::cout << s << ' ';
	}

	// Çok Boyutlu Diziler.
	int64_t eski[2 * 3 * 2] = {
		000,001, 010,011, 020,021, // [0*(3*2) + blok*3 + iç*2]
		100,101, 110,111, 121,122, // [1*(3*2) + blok*3 + iç*2]
	};

	int64_t klasik[2][3][2] = {
		{ { 000,001 },{ 010,011 },{ 020,021 } }, // [0][][]
	{ { 100,101 },{ 110,111 },{ 121,122 } }, // [1][][]
	};

	// dizilerin aslen pointer olduðunun kanýtýdýr.
	std::cout << std::endl << " ---Hepsi Ayný Deðer--- \n";
	std::cout << "eski[9]: " << eski[9] << std::endl; // satýr*(3*2) + blok*3 + iç*2
	std::cout << "klasik[1][1][1]: " << klasik[1][1][1] << std::endl;
	// Birkaç kez adres eriþimine baþvurulduðundan iþlemleri yavaþlattýðý düþünülüyor.
	// Yeni derleyiciler bunun üstesinden geldiðini duydum.
	std::cout << "*(klasik[1][1] + 1): " << *(klasik[1][1] + 1) << std::endl;
	std::cout << "*(*(klasik[1] + 1) + 1): " << *(*(klasik[1] + 1) + 1) << std::endl;
	std::cout << "*(*(*(klasik + 1) + 1) + 1): " << *(*(*(klasik + 1) + 1) + 1) << std::endl;

}

ia vectorÝþlemleri() {
	/*
	* Vector tipi c++ dilinin itibarýnýn simgesidir. :)
	* Gelmiþ geçmiþ en hýzlý veri yapýsýdýr(tabi kullanabilene).
	* Array tipinin üzerine inþa edilmiþtir. Ýstenirse array gibi davranabilir.
	* Stack yapýsýyla çalýþýr.
	* Boyutu her 1 eleman geldikçe kendi kendine geniþleyebilir. Ayarlanýrsa n elemanda bir geniþler.
	böylece hafýzayý sil ve yeniden daha geniþlemiþ olarak doldur döngüsünün iþlem yükü azalmýþ olur.
	*/
	std::vector<int> vecNums(2); // iki elemanlý tek boyutlu dizi olarak baþladý.
	vecNums[0] = 2;
	vecNums.at(1) = 4; // yine sýnýr kontrolü ile atama yapýlabilir.
	vecNums.push_back(8); // dizi olarak baþlamasýna raðmen geniþledi.
	std::cout << "Son eleman: " << vecNums[vecNums.size() - 1] << std::endl;

	std::for_each(vecNums.begin(), vecNums.end(),
		[](auto& i) { std::cout << i << std::endl; });

	//std::vector<auto> au; // error
	std::vector<int> dolduriçini(8);
	std::iota(dolduriçini.begin(), dolduriçini.end(), 0); // std::for_each(dolduriçini.begin(), dolduriçini.end(), [](auto& i) {++i}); // karþýlýðý
														  // baþlangýç elemandan baþlayarak son elemana kadar doldur.
														  // doldurma þekli baþlangýç 0 sonrasýnda +1 arttýrarak doldur.
	std::cout << "iota: " << std::endl;
	std::for_each(dolduriçini.begin(), dolduriçini.end(),
		[](auto& i) { std::cout << i << std::endl; });

	/* Yukarýdakinin eþiti
	for (size_t i = 0; i < dolduriçini.size(); i++) {
	std::cout << dolduriçini.at(i) << std::endl;
	}
	for (auto i : dolduriçini) std::cout << dolduriçini.at(i) << std::endl;
	*/

	// tüm vektördeki çift sayýlarý kontrol et. biraz daha fonksiyonel yaklaþým.
	std::for_each(dolduriçini.begin(), dolduriçini.end(),
		[](auto& i) { if (not (i % 2)) std::cout << i << std::endl;   });

	// cümleyi boþluklarla ayýracaðýz.
	std::string cumle = "arap ihsan efendi";
	char bosluk = ' ';
	auto kelimeler = functionalStyle::StringToVector(cumle, bosluk); // içindeki diðer ifadelere sonra deðineceðim.

	for (size_t i = 0; i < kelimeler.size(); ++i) { //size_t c dilinden geliyor ve bir takým avantajlarý var.
		std::cout << kelimeler.at(i) << std::endl;
	}

	{
		using std::vector;
		using std::string;
		//klasik uygulama. Hesap makinesi
		// input: 1 - 5
		// output: -4
		auto num1 = 0.0, num2 = 0.0; // 5(num1) - 9(num2)
		string strCalc = std::string(" "); // girdinin olacaðý string
		vector<string> vecCalc; // girdi ayrýþtýrýlacak ve içine eklenecek.
		auto bosluk = ' '; // boþluk görünce ayrýþtýrýlacak.

		std::cout << "Hesaplamak istediðiniz ifade nedir? (boþluk býrakaraj yazýn. Exp: 4 * 7)" << std::endl;
		getline(std::cin, strCalc);

		std::stringstream ss(strCalc); // ayrýþtýrmaya yarýyor.
		string ayrýldý; // anlýk ayrýlan ifade

		while (getline(ss, ayrýldý, bosluk)) {
			vecCalc.push_back(ayrýldý);
		}

		num1 = std::stod(vecCalc[0]);
		num2 = std::stod(vecCalc[2]);

		auto operate = vecCalc[1];

		// iyi deðil. þimdilik iþimizi görüyor.
		if (operate == "+")
		{
			ekranayaz << num1 + num2 << std::endl;
		}
		else if (operate == "-")
		{
			ekranayaz << num1 - num2 << std::endl;
		}
		else if (operate == "*")
		{
			ekranayaz << num1 * num2 << std::endl;
		}
		else if (operate == "/")
		{
			ekranayaz << num1 / num2 << std::endl;
		}
		else
		{
			std::cout << "lütfen doðru girin. +,-,*,/" << std::endl;
		}

	}

}

ia pointlerFonksiyonlar() {
	/*
	* Ýþaretçiler nesneye direkt eriþmek yerine adresini tutar ve istendiðinden adresten veriyi alýr.
	* pointer->|adres|->veri
	* Büyük miktarda verilerin defalarca kopyalamak yerine hafýzada baþladýðý noktayý iþaret etmek akýllýcadýr.
	*
	* C dilinden gelen iþaretçilere ek olarak c++ referans objesini kullanýr.
	* Referans yani baþvuru objesi nesneye fiziksel olarak eriþmek yerine daha hýzlý bir yöntem kullanýr.
	* Þimdilik referanslarýn kullanýþlý olduðunu bilin yeter. Hadi baþlayalým.
	*
	* Fonksiyonlar birden fazla tekrarlanan kalýplarý gruplamakta kullanýlýr.
	* Program çalýþmaya baþladýðýnda veriler gibi fonksiyonlarda hafýza da yer kaplar ancak
	gömülü sistem programcýsýysanýz dikkat edersiniz. Yürütülebilir dosya boyutunu içindeki veri ve fonksiyonlar etki eder.
	* Yine büyük fonksiyonlarý kullanmak üzere yada geri çaðýrým fonksiyonu yazmak üzere pointer alabilir.
	fakat Modern C++ <function> objesi ve lambda fonksiyonlarý sayesinde iþleri basitleþtirmiþtir.
	*/

	{
		// pointer kullanýmý
		int sayý = 1;
		std::cout << "ram üzerindeki adresi(yeri): " << &sayý << std::endl;
		int* point = &sayý;
		std::cout << "pointer: " << *point << std::endl;
		*point = 5;
		std::cout << "pointer changed: " << *point << std::endl;

		// dizi pointer kullanýmý
		int arr[] = { 1,2,3,4 };
		int* Parr = arr;
		std::cout << "1.eleman: " << *Parr << " ,adres: " << Parr << std::endl;
		Parr += 2;
		std::cout << "3.eleman: " << *Parr << " ,adres: " << Parr << std::endl;
		Parr--;
		std::cout << "2.eleman: " << *Parr << " ,adres: " << Parr << std::endl;
		Parr++;
		std::cout << "3.eleman: " << *Parr << " ,adres: " << Parr << std::endl;

		// referans kullanýmý
		int program = 45;
		int& refp = program;
		std::cout << "refp: " << refp << std::endl; // söylemiþtim bu bir pointer deðil.

													// fonksiyon atamalarý
		assignByValue(sayý);
		std::cout << "assignByValue: " << sayý << std::endl; // Parantezlerin baþlangýcý yýðýnýn baþladýðý,
															 // parantezin sonu yýðýnýn yaþam süresinin bittiði yerdir. 

		std::cout << "returnByValue: " << returnByValue(sayý) << std::endl; // fonksiyon dýþýna çýktý. return deðeri dýþarý attý.

		assignByPointer(&sayý);
		std::cout << "assignByPointer: " << sayý << std::endl; // fonksiyon dýþýna çýktý. yýðýn olarak geçmemiþti.

		assignByRef(sayý);
		std::cout << "assignByRef: " << sayý << std::endl; // fonksiyon dýþýna çýktý. deðer gibi görünüyor ama deðil. 
														   // iþte referansýn gücü.

	}
	yenisatýryaz;
	{
		// fonksiyon iþaretçisi
		// basitçe
		void(*fun_ptr)(int) = &yazacak;
		(*fun_ptr)(10);

		//biraz daha ileri taþýlayým.
		int arr[] = { 2, 5, 7, 90, 70 };
		int n = sizeof(arr) / sizeof(arr[0]);
		int x = 7;
		printf("Dönen index %d \n", search(arr, n, sizeof(int), &x, compare));


		std::vector<int> range = RangePython(1, 10, 2);
		for (auto& i : range) std::cout << "range: " << i << ", ";
		yenisatýryaz;
		// YADA
		// Eski C dili.
		myFuncPoint ptrFunc = RangePython;
		yazacakFunc(1, 10, 2, ptrFunc);

		// C++ þekli
		auto lambda = [](int x) { cout << x * 50 << endl; return x * 100; };
		f(lambda); //pass lambda


	}
	yenisatýryaz;
	{
		// yýllýk %1 para artýþýna göre 10 sene sonra ne kadar paran olur?
		double paramVar = 0.0; double kar = 0.0; //varsayýlan deðerleri verdim.
		ekranayaz << "Baþlangýçta ne kadar paran var? : "; std::cin >> paramVar; yenisatýryaz;
		ekranayaz << "Ne kadar kârýn var? : "; std::cin >> kar; yenisatýryaz;
		kar *= .01; // yüzdeliðe göre hesaplanmasýný saðladým.
		for (auto& i : RangePython(1, 10, 1))
			paramVar += paramVar * kar;
		std::cout << "10 yýl sonra elde edeceðin miktar: " << paramVar << yenisatýr;

		std::cin.get();
	}
}

ia özeldurumlarVEDöngüler() {
	// lambda fonksiyonlarýnýn normal fonksiyonardan nerdeyse farký yok.
	// kullanýmý oldukça basit ve deðiþken deðeri gibi kullanýlabiliyor.
	auto loop = []() {
		/*
		* Görev çam aðacý !
				 #			->
				###			->
			   #####		->
			  #######		->
			 #########		->
				 #			->
		* Gerçekleþtirmek istediðimiz þekil budur.
		* Biraz bekleyeceðim deneyin.
		*/
		std::cout << "üçgenin uzunluðu kaç olsun?: ";
		auto boy = 0, bosluk = 0, hash = 1, stumpbosluðu = 0;
		std::cin >> boy;
		bosluk = boy - 1;
		stumpbosluðu = boy - 1;

		while (boy != 0) /* boy<0 daha iyi olabilir */ {
			for (auto i : RangePython(1, bosluk, 1))
				std::cout << " ";
			for (auto i : RangePython(1, hash, 1))
				std::cout << "#";
			yenisatýryaz;
			--bosluk;
			hash += 2;
			--boy;
		}
		for (auto i : RangePython(1, stumpbosluðu, 1))
			std::cout << " ";
		std::cout << "#";
		std::cin.get();

	};

	auto özelDurum = []() {
		double num1, num2 = 0; // modern c++ ;)
		ekranayaz << "sayý bir: " << yenisatýr;
		std::cin >> num1;
		ekranayaz << "sayý iki: " << yenisatýr;
		std::cin >> num2;

		try {
			if (num2 == 0)
				throw("sýfýr ile bölüm hatasý"); // çalýþma zamaný hatasý gönderir. derleme zamaný hatasýný göreceðiz.
			else
			{
				printf("%.1f/%.1f=%.2f", num1, num2, num1 / num2);
			}
		}
		catch (const std::string exp) /* Hatayý throw ile göndermiþtik ve catch ile yakaladýk. Bir yere kaçmýyor :) */ {
			// hatanýn ne olduðunu biz bilmiyorsak; sadece ekrana yazarýz.
			std::cout << "hata: " << exp << std::endl;
		}
		std::cin.get();
	};

	auto özelDurum2 = []() {
		double num1, num2 = 0; // modern c++ ;)
		ekranayaz << "sayý bir: " << yenisatýr;
		std::cin >> num1;
		ekranayaz << "sayý iki: " << yenisatýr;
		std::cin >> num2;

		try {
			std::cout << "Hata gönderiyoruz..." << yenisatýr;
			throw std::runtime_error("hatalar oluþtu amanýýýn!");
			std::cout << "Ekrana hata gelecek mi? Catch kullan.";
		}
		catch (std::exception& exp) {
			// hatanýn ne olduðu biz bilmeden hatayý yakaladýk.
			std::cout << "hata yakalandý. yuppii : " << exp.what() << std::endl;
		}
		catch (...) {
			// hatanýn ne olduðunu bilgisayardaki veri tabaný da bilmiyorsa...
			std::cout << "varsayýlan hata yakalayýcý. Her þeyi yakalar." << std::endl;
		}
		std::cin.get();
	};

	auto rastgele = []() {
		srand(time(NULL));
		auto tahminEdilecek = std::rand() % 11; // max=10
		auto tahmin = 0;
		// do-while farký sorgusuz bloðun içindekini bir kere yapar.
		do
		{
			std::cout << "aklýmdakini tahmin et." << std::endl;
			std::cin >> tahmin;
			if (tahmin > tahminEdilecek) std::cout << "büyük oldu" << std::endl;
			if (tahmin < tahminEdilecek) std::cout << "küçük oldu" << std::endl;
		} while (tahminEdilecek != tahmin);
		/*
		// Yukarýdakinin aynýsý
		while (true)
		{
			std::cout << "aklýmdakini tahmin et." << std::endl;
			std::cin >> tahmin;
			if (tahmin > tahminEdilecek) std::cout << "büyük oldu" << std::endl;
			if (tahmin < tahminEdilecek) std::cout << "küçük oldu" << std::endl;
			if (tahminEdilecek == tahmin) break; // döngüden çýkmak üzere gerekli.
		}
		*/


		std::cout << "Tebrikler tahmin ettiniz." << std::endl;
		std::cin.get();
	};

	//loop();
	özelDurum();
	özelDurum2();
	rastgele();
}

ia stringMath() {
	char cString[] = { 'A','B','C','D','E','\0' }; // \0 "null" karakteri olmazsa program hata verip kapanýr.
	// cstring ifadelerini iþlemek zordur.
	std::cout << "Array size: " << sizeof(cString) << std::endl;

	// Modern c++ string ifadesini artýk daha derinlemesine iþleyeceðim.
	auto stringÝfadesi = []() {
		std::vector<std::string> vecStr(10);
		std::string str("Benim adým string");
		vecStr[0] = str;

		//unutmayýn index '0''dan baþlýyor.
		std::cout << "front: " << str.front() << ", back: " << str.back() << std::endl; //front= 'B' , Back= 'g' 
		std::cout << "Uzunluk: " << str.length() << std::endl;
		std::string str2(str); // kopyaladýk.
		vecStr[1] = str2;
		std::string str3(str2, 4); // 4. indexten itibaren kopyadýk.
		vecStr[2] = str3;
		std::string str4(5, 't'); // t 5 kez tekrarlandý.
		vecStr[3] = str4;
		vecStr[4] = str4.append(" demiþtim."); // standart kütüphane ile
		str += "str ekleniyor."; // operatör desteklerse.
		str.append(str, 10, 13); // 10. indexten itibaren 13 tane.
		vecStr[5] = str;
		str.erase(13, str.length() - 1); // 13. indexten itibaren "str.length() - 1" tane siliniyor.
		vecStr[6] = str;
		str.erase(str.begin() + 5, str.end() - 3);
		vecStr[7] = str;

		auto bul = str.find("string");
		if (bul != std::string::npos) // npos evrenselleþtirilmiþ son string ifadesidir. 32 ve 64 bitte farklý sayýlarý ifade eder.
			std::cout << "1st index" << bul << std::endl;

		std::cout << "substr: " << str.substr(6, 6) << std::endl; // 6. indexten itibaren 6 tane
		std::reverse(str.begin(), str.end());
		std::cout << "reversed: " << str << std::endl;

		//transform	  inputBaþlangýç, inputBitiþ, outputBaþlangýç, iþlem . Þeklinde çalýþýr.
		std::transform(str.begin(), str.end(), str.begin(), ::toupper); // varsayýlan namespace std olduðundan tanýdý.
		std::cout << "toupper: " << str << std::endl;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::cout << "tolower: " << str << std::endl;

		// string içinden c dilinin string ifadesini çýkarmak için.
		std::cout << "cstr: " << str.c_str() << std::endl;

		/*
		Ascii karakterlerin sayýsal karþýlýklarý...
		* a-z : 97-122
		* A-Z : 65-90
		*/

		char c = 'G';
		int ii = c;
		// eski hali (int)'c' . c++ dilinde static_cast derleme zamanýnda tip güvenliði saðladýðýndan tavsiye ederim. 
		std::cout << "c ascii code: " << static_cast<int>('c') << std::endl;
		// sayýlarý string ifadelerine çevirmek istiyoruz.
		std::string numstr = std::to_string(5 - 8);
		std::cout << "sayý -> string dönüþümü: " << numstr << std::endl;


		auto i = 0;
		for (auto v : vecStr) {
			ekranayaz << i << ". " << v << yenisatýr; ++i;
		}

		std::cin.get();
	};

	auto cümleyiÞifrele = []() {
		std::string normal, gizli = "";

		std::cout << "Þifrelemek istediðiniz ingilizce ifadeyi girin." << std::endl;
	std:cin >> normal;

		// þifrele. aslýnda ascii kodlarýný yazdýrýyor.
		/*
		Ascii karakterlerin sayýsal karþýlýklarý...
		* a-z : 97-122 // üç basamaklý da olabiliyor. Geri çevrilemez.
		* A-Z : 65-90 // iki basamaklý sayýlar olduðu kesin. iþimize yarayacak ;)
		en az 23 çýkarýlýrsa edinecelecek maximum sayý 123 - 23= 99 olur ve iki basamaklýdýr.
		*/
		auto kodla = [](auto& normal) {
			std::string gizli = "";
			for (auto ch : normal)
				// iki basamaklý saý olduðunu garanti ediyoruz.
				gizli.append(std::to_string(static_cast<int>(ch - 23))); //gizli.append(std::to_string(static_cast<int>(ch))); // 
			std::cout << "Þifre: " << gizli << std::endl;
			return gizli;
		};
		gizli = kodla(normal);

		auto kodçöz = [](auto& gizli) {
			// eski haline döndür.
			std::string normal = "";
			for (size_t i = 0; i < gizli.length(); i += 2)
			{
				std::string sCharCode = "";
				// int ifadesiylede yapýlabilir ama uzun cümlelerde string ile 
				// taþma hatasý yaþamayýz.
				sCharCode += gizli[i];
				sCharCode += gizli[i + 1]; // üç basamaklý sayý ise sistem çalýþmaz. iki basamaklý olmak zorunda.

				int nCharCode = std::stoi(sCharCode);
				// þifrelemeyi tersine çevirebilmek üzere 23 çýkarmýþtýk. fakat asýl karakterleri
				// elde edebilmek için ayný sayý tekrar eklenmeli.
				char chCharCode = nCharCode + 23; //char chCharCode = nCharCode;
				normal += chCharCode;
			}
			std::cout << "Orjinal: " << normal << std::endl;
			return normal;
		};
		normal = kodçöz(gizli);





		std::cin.get(); // ekran hemen kapanmasýn istiyorum.
	};

	auto matematik = []() {
		// c dilindeki matematik ifadeleri aynen kullanýlabilir.
		// fazladan ileri matematik ifadeleri eklenmiþtir.
		// ileri göstereceðim parallel hesaplamaya uygun ifadelerdir.

		std::cout << "abs(-10) = " << std::abs(-10) << "\n";

		std::cout << "max(5,4) = " << std::max(5, 4) << "\n";

		std::cout << "min(5,4) = " << std::min(5, 4) << "\n";

		std::cout << "fmax(5.3,4.3) = " << std::fmax(5.3, 4.3) << "\n";

		std::cout << "fmin(5.3,4.3) = " << std::fmin(5.3, 4.3) << "\n";

		// e ^ x
		std::cout << "exp(1) = " << std::exp(1) << "\n";

		// 2 ^ x
		std::cout << "exp2(1) = " << std::exp2(1) << "\n";

		// e * e * e ~= 20 so log(20.079) ~= 3
		std::cout << "log(20.079) = " << std::log(20.079) << "\n";

		// 10 * 10 * 10 = 1000, so log10(1000) = 3
		std::cout << "log10(1000) = " << std::log10(1000)
			<< "\n";

		// 2 * 2 * 2 = 8
		std::cout << "log2(8) = " << std::log2(8)
			<< "\n";

		// 2 ^ 3
		std::cout << "pow(2,3) = " << std::pow(2, 3)
			<< "\n";

		// Returns what times itself equals the provided value
		std::cout << "sqrt(100) = " << std::sqrt(100)
			<< "\n";

		// What cubed equals the provided
		std::cout << "cbrt(1000) = " << std::cbrt(1000)
			<< "\n";

		// Hypotenuse : SQRT(A^2 + B^2)
		std::cout << "hypot(2,3) = " << std::hypot(2, 3)
			<< "\n";

		std::cout << "ceil(10.45) = " << std::ceil(10.45)
			<< "\n";

		std::cout << "floor(10.45) = " << std::floor(10.45)
			<< "\n";

		std::cout << "round(10.45) = " << std::round(10.45)
			<< "\n";

		// Dahasý da var; sin, cos, tan, asin, acos, atan, atan2,
		// sinh, cosh, tanh, asinh, acosh, atanh


	};
	//stringÝfadesi();
	//cümleyiÞifrele();
	matematik();

}

static std::string operator*(const std::string& s, size_t n)
{
	std::string result;
	result.reserve(s.size()*n);
	for (size_t i = 0; i < n; ++i) {
		result += s;
	}
	return result;
}
ia Alistirmalar() {
	// boþluk ve özel karakterleri silmek üzere kullanýlan trim fonksiyonu c++ stl içinde yok. Hadi yapalým.
	auto trimKarakter = [](std::string str) {
		std::string boslukKarakterleri(" \t\f\v\n\r"); // bosluk ve string formatlama karakterleri var.
		const auto& last = str.find_last_not_of(boslukKarakterleri);
		str.erase(last + 1); // 
		const auto& first = str.find_first_not_of(boslukKarakterleri);
		str.erase(0, first);
		return str;
	};
	std::string asd("   Cat runner gets the skinner   ");
	std::cout << "trimden önce(size):" << asd.size() << std::endl;
	const std::string& trimed = trimKarakter(asd);
	std::cout << "trimden sonra(size):" << trimed.size() << std::endl;
	std::cout << "trimed: " << trimed << std::endl;
	yenisatýryaz;

	// python benzeri string çarpma iþlemini nasýl yapacaðýz?
	// burada operator aþýrý yüklemesi yaptýðýmýzdan yukarýda static olarak tanýmlanmalý.
	std::cout << (std::string("=+") * 5) << std::endl;

	// string içinde istenen ifade var mý, yok mu?(find substring matches)
	auto strMatches = [](std::string str, std::string substr) {
		std::vector<int> matchingIndexes;
		int index = str.find(substr, 0);
		while (index != std::string::npos) {
			matchingIndexes.push_back(index);
			index = str.find(substr, index + 1);
		}
		return matchingIndexes;
	};
	std::string strTest = " direkte leylek yuvasý var.";
	std::string substrTest = "lek";
	std::vector<int> matched = strMatches(strTest, substrTest);
	for (auto& v : matched) std::cout << v << std::endl;
	yenisatýryaz;
	// bulunan tüm eþleþmeleri istenen string ile deðiþ tokuþ et.
	// std içineki index bazlý hesaplama yapýyor ve kullanýmý rahat deðil.
	auto strReplace = [strMatches](std::string str, std::string substr, std::string newstr) {
		// lambda kuralý olarak strMatches fonksiyonunu bu [strMatches] ile lambda fonksiyonunun içine kopyaladým.
		std::vector<int> matched = strMatches(str, substr); // eðer eþleþme olmazsa .size 0 gönderecek.
		if (matched.size() != 0) {
			int sizeDiff = matched.size() - substr.size();
			auto looped = 0;
			for (auto index : matched)
				str.replace(index + looped * sizeDiff, substr.size(), newstr); looped;
		}
		return str;
	};
	std::string degistokus = "lak";
	std::cout << "strReplace: " << strReplace(strTest, substrTest, degistokus) << std::endl;
	yenisatýryaz;

	auto isFonksiyonlarý = []() {
		char harf = 'k';
		char sayý = '5';
		char bosluk = ' ';

		std::cout << "Is k a letter or number " <<
			isalnum(harf) << "\n";
		std::cout << "Is k a letter " <<
			isalpha(harf) << "\n";
		std::cout << "Is k uppercase " <<
			isupper(harf) << "\n";
		std::cout << "Is k lowercase " <<
			islower(harf) << "\n";
		std::cout << "Is 5 a number " <<
			isdigit(sayý) << "\n";
		std::cout << "Is space a space " <<
			isspace(bosluk) << "\n";
	};
	isFonksiyonlarý();

	// rastgele sayýlardan oluþan vektör oluþturalým.
	auto GenerateRandVec = [](int numOfNums, int min, int max) {
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
	std::vector<int> vecVals = GenerateRandVec(10, 5, 50);
	for (auto x : vecVals)
		std::cout << x << "\n";
	yenisatýryaz;

	// range fonksiyonunu önceden yapmýþtým ama hadi bir daha yapalým fakat asal sayý üreteci olsun ;)
	auto Range = [](int start, int max, int step) {
		int i = start;
		std::vector<int> range;
		while (i <= max) {
			range.push_back(i);
			i += step;
		}
		return range;
	};
	auto IsPrime = [Range](int num) {
		for (auto n : Range(2, num - 1, 1)) {
			if ((num % n) == 0)
				return false;
		}
		return true;
	};
	auto GetPrimes = [Range, IsPrime](int maxNum) {
		std::vector<int> vecPrimes;
		for (auto x : Range(2, maxNum, 1)) {
			if (IsPrime(x))
				vecPrimes.push_back(x);
		}
		return vecPrimes;
	};
	int num = 0;
	std::cout << "Number to Check : ";
	std::cin >> num;
	std::cout.setf(std::ios::boolalpha);// Shows bool values as true or false
	std::cout << "Is " << num << " Prime: " << IsPrime(num) << "\n";
	std::cout << "Generate Primes up to ";
	int maxPrime;
	std::cin >> maxPrime;
	std::vector<int> primeList = GetPrimes(maxPrime);
	for (auto x : primeList)
		std::cout << x << "\n";
	yenisatýryaz;
	std::cin.clear(); // kontrol bayraklarýný siler ve yoluna devam eder.
	// io operasyonlarýný ayrýntýsýyla anlatmadým ama eðerki çok fazla cin kullanýrsanýz 
	// bir süre sonra ihmal edilir. Bu sorununun üstesinden gelmek için clear kullanabilirsiniz.

	// algebratik fonksiyon çözücü
	// denklem örneði; x + 4 = 9 -> x için çöz
	// x daima 1. dereceden olacak. 
	auto StringToVector = [](std::string theString, char separator) {
		std::vector<std::string> vecsWords;
		std::stringstream ss(theString);
		std::string sIndivStr;
		while (getline(ss, sIndivStr, separator))
			vecsWords.push_back(sIndivStr);
		return vecsWords;
	};
	auto SolveForX = [StringToVector](std::string equation) {
		std::vector<std::string> vecEquation =
			StringToVector(equation, ' ');
		// Convert strings to int
		int num1 = std::stoi(vecEquation[2]);
		int num2 = std::stoi(vecEquation[4]);
		int xVal = num2 - num1;
		std::cout << "x = " << xVal << "\n";
	};
	std::cout << "Enter an equation to solve ";
	std::string equation = "";
	// io operasyonlarýný ayrýntýsýyla anlatmadým ama eðerki çok fazla cin kullanýrsanýz 
	// bir süre sonra ihmal edilir. Bu sorununun üstesinden gelmek için özellikle getline kullanmak üzere ignore kullanabilirsiniz.
	// std::cin.ignore(256,' ');   // 256 karakter umursama taki boþluk karakteri gelene kadar.
	cin.ignore(); // eski girdileri umursamadan yoluna devam eder. 
	getline(std::cin, equation); // cin.getline(equation,50); // sadece 50 karakter alacak.
	//std::cin >> equation;
	SolveForX(equation);

}

ia yinelemeliVEasýrýYüklemeli() {
	// yinelemeli fonksiyonlarýndaki en büyük tehlike "stack overflow" yani ayrýlan hafýzanýn yetmemesidir.
	// hata ayýklamasý zordur.
	// genelde yavaþ çalýþýr fakat bazen tek çözüm yoludur. Yeni çýkan programlama dillerinde oldukça hýlandýrýlmýþ bir iþlemdir.
	// lambda fonksiyonlarý yinelemeli kullanmak üzere önceen std::functional olarak tanýmlanmalý ve ykalama listesine referans olarak eklenmelidir.

	/*
	 Neden bu kadar çok lambda kullandým? https://stackoverflow.com/q/13722426/341970
	 Lambda fonksiyonlar normal fonksiyonlardan daha iyi optimize edilir.
	 Kendileri birer nesne olarak görülür ve inline yapmak daha da kolaylaþýr. çaðrý yýðýnlarý azalýr ve program hýzlanýr.
	*/
	std::cout << "--- yinelemeliVEasýrýYüklemeli fonksiyonu ---" << std::endl;
	auto counter = []() {
		std::function<void(int)> count = [&count](int c) {
			if (c == 0)
				return;
			// else demeye gerek görmedim.
			cout << "hello" << c << endl;
			count(--c);
			cout << c << endl;
			return;
		};
		std::cout << "--- counter fonksiyonu ---" << std::endl;
		count(5);
	};

	auto somefunc = []() {
		auto doubler = [](int a)->int {
			return a * a;
		};

		auto inc = [](int a)->int {
			return ++a;
		};
		std::function<int(int, int)> sum; // lambda deðeri yakalama listesine girmesi için bir deðiþken olarak tanýmlanmalýdýr. yoksa yinelemeli lambda fonksiyonu derlenemez.
		sum = [doubler, inc, &sum](int a, int b)->int {
			return a > b ? 0 :
				doubler(a) + sum(inc(a), b); // if-elseden daha az kod üretiliyor. Daha hýzlý olmasý muhtemel.
		};
		std::cout << "--- somefunc fonksiyonu ---" << std::endl;
		std::cout << sum(1, 10) << std::endl; // 385
		std::cout << sum(25, 7) << std::endl; // 0
	};

	auto sumrec = []() {
		std::cout << "--- sumrec fonksiyonu ---" << std::endl;

		vector<int> v(10);
		std::iota(v.begin(), v.end(), 3);
		std::function<int(int)> sum2;
		sum2 = [&v, &sum2](int x)->int {
			return v.back() + sum2(v.back() - 1);
		};
		for (auto&& i : v) std::cout << i << ", ";
		yenisatýryaz;
	};

	auto morerec = []() {
		std::cout << "--- morerec fonksiyonu ---" << std::endl;
		int n = 4;
		std::function<int(int)> factorial;
		factorial = [&factorial](int n) {
			return n > 1 ? (n * factorial(n - 1)) : 1;
		};
		cout << "Factorial of " << n << " = " << factorial(n) << std::endl;

		std::function<int(int)> sumto;
		sumto = [&sumto](int n) {
			return n > 1 ? n + sumto(n - 1) : 1;
		};
		cout << "sumto of " << n << " = " << sumto(n) << std::endl;
		/* n=1 -> 1
		 n=2 -> 2
		 n=3 -> 6
		 n=4 -> 10 */

		 // template konusuna gelince bu fonksiyon üzerinde tekrar duracaðým.
		std::function<int(int)> fibonacci;
		fibonacci = [&fibonacci](int n) {
			return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
		};
		cout << "fibonacci of " << n << " = " << fibonacci(n) << std::endl;

		std::function<bool(int)> isPrime;
		isPrime = [&isPrime](int p) { // ikinci parametreyi 
			std::function<bool(int, int)> Prime;
			Prime = [&Prime](int kontroledilen, int kontrolbaslangýcý = 3) {
				return kontrolbaslangýcý * kontrolbaslangýcý > kontroledilen ? true : // aslýnda karekökünden küçük olmasýný kpntrol ediyoruz.
					kontroledilen % kontrolbaslangýcý == 0 ? false : // tam bölüm ifadesini temsil ediyor.
					Prime(kontroledilen, kontrolbaslangýcý + 2); // 2 dýþýnda çift sayý yoktur.
			/*if (kontrolbaslangýcý * kontrolbaslangýcý > kontroledilen) return true;
			else if (kontroledilen % kontrolbaslangýcý == 0) return false;
			return Prime(kontroledilen, kontrolbaslangýcý + 2); */
			};
			return p == 2 ? true : Prime(p, 3);
			/*if (p == 2) return true; // sadece 2 sayýsý asaldýr.
			return Prime(p,3);*/
		};
		/*
		std::boolalpha	 -> false -> 0
		std::noboolalpha -> true  -> 1
		*/
		int primex = 47;
		cout << "is prime? " << primex << " = " << std::boolalpha << isPrime(primex) << std::noboolalpha << std::endl;
	};

	auto sortrec = []() {
		/*
		* c++ stream iþlemlerinde varsayýlan þekilde hafýzayý sýnýrlar.
		* performans sebeplerinden eðer stdout çýktý hafýzasý dolarsa c++ otomatik olarak "std::cout.flush();" komutunu çalýþtýrýr.
		* sorunun üstesinden gelmek üzere stdout buffering(hafýzaya almak) iþlemini durdurmak gerekir.
		* "setvbuf" c++ stream bufferlarýný ayarlamaya yarayan fonksiyondur. http://www.cplusplus.com/reference/cstdio/setvbuf/
		* dosya okumakurken, ekrana yazdýrýrken ve kullanýcýdan veri alýrken buffering iþleminde kullanýlýr.
		* _IONBF = buffering yok demektir.
		*/
		/*
		* http://www.cplusplus.com/reference/cstdio/setvbuf/
		FILE *pFile;
		pFile=fopen ("myfile.txt","w");
		setvbuf ( pFile , NULL , _IOFBF , 1024 ); // 1024 byte peþin peþin ayrýldý.
		 // File operations here
		fclose (pFile);

		*/
		std::setvbuf(stdout, NULL, _IONBF, 0); // performans sebeplerinden ötürü gerekmedikçe uygulanan bir yöntem deðildir.
		// son alýþtýrma; bubble sort
		/*
		// Iterative Bubble Sort
		bubbleSort(arr[], n)
		{
		//for (i = 0; i < n-1; i++) // iþte buradaki döngü fadesini kaldýrýp yinelemeli fonksiyon haline getirmemiz gerekiyor.

		// Last i elements are already in place
		for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
		swap(arr[j], arr[j+1]);
		}
		*/
		std::cout << "--- sortrec fonksiyonu ---" << std::endl;
		auto bubbleSort = [](std::vector<int>& vec) { // eðerki fonksiyon ...(n-1) ifadesiyle gidiyorsa kullanýmý basitleþtirmek üzere  böyle bir yönteme baþvurulabilir.
			auto swapedCount = 0; // Tüm dizi tarandý ve swap iþlemine gerek kalmadýysa, dizi sýralanmýþ ise döngü devam etmesin.
			std::function<void(std::vector<int>&, int)> bubbleSort_n;
			bubbleSort_n = [&swapedCount, &bubbleSort_n](std::vector<int>& vec, int n) {
				if (n == 1)	return; // temel durum ifadesi
				const auto& loopMax = n - 1;
				for (auto&& i = 0; i < loopMax; ++i) { // bubble sort için bir geçiþ. en büyük eleman sýrasýna girdi. bu geçiþten sonra recursif olacak.
					auto& ilk = vec.at(i);
					auto& sonraki = vec.at(i + 1);
					if (ilk > sonraki) {
						std::swap(ilk, sonraki);
						swapedCount = 0;
					}
					else { // swap(deðiþ-tokuþ) iþlemi gerçekleþmez ise sýralama bitmiþ demektir.
						++swapedCount;
						if (swapedCount == loopMax) return;
					}
				}
				bubbleSort_n(vec, n - 1); // son eleman
			};
			bubbleSort_n(vec, vec.size());
		};
		auto printArray = [](auto vec) -> void { // dönüþ tipi "void" olarak belirledim. artýk derleme hatasý yok.
			for (int v : vec)
				printf("%d ", v);
			printf("\n");
		};
		std::vector<int> vec(10); //vec= { 64, 34, 25, 12, 22, 11, 90 };
		size_t min = 10;
		size_t max = 100;
		//srand(static_cast <unsigned> (time(0))); // eski versiyon
		// https://en.cppreference.com/w/cpp/numeric/random
		// modern c++ ile rastgele sayý üretmek. Yeni versiyonla birden fazla daðýlýmda beslemede yüksek hýzlý rastgele sayý üretebiliyoruz.

		// bütün kodlarý Uret.h içinde topladým.
		//std::random_device rd; // 
		//std::default_random_engine er(rd());
		//std::uniform_int_distribution<int> dis(min, max);
		//std::generate(vec.begin(), vec.end(), [&min,&max,&er,&dis]() {
		//	//std::mt19937 rng;
		//	//rng.seed(std::random_device()());
		//	////rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		//	//std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
		//	//
		//  //min + std::rand() % ((max + 1) - min);
		//  //
		//	//return min + static_cast <int> (std::rand()) / (static_cast <int> (RAND_MAX / (min - max))); // min <= randomNumber => max sayý üretir.
		//	//random_number = std::experimental::randint(min, max); // deneysel yöntem.
		//	//
		//	// tam olarak istenilen rastgelelik saðlanmýyor.
		//	//static std::default_random_engine e;
		//	//static std::uniform_int_distribution<int> dis(min, max); // min <-> max
		//	//return dis(e)%rand();
		//	//
		//	//auto e = initialize_twister(); // initialize_twister.h içindeki fonksiyon
		//	//std::uniform_int_distribution<int> dis(min, max);
		//	//return dis(e);
		//	return dis(er);
		//});
		rastgeleUret<int>(vec, 10, min, max);

		// "type safety" olarak bilinen ilkeyi atlamýþ oluyoruz.
		// c++ standart kütüphanesi bizi bu yanlýþtan kurtarýyor. std::array
		// int n = sizeof(vec) / sizeof(vec[0]); // Hemen hemen tüm kaynaklarda bu þekilde boyut bulmaya çalýþýyor ama yanlýþ.
		bubbleSort(vec);
		printf("Sorted array : \n");
		printArray(vec);
	};

	auto vectorGuzelYaz = []() {
		fonksiyonuyaz("vectorGuzelYaz");
		/* Yinelemeli deðil ama güzel çalýþma
		// ----- PROBLEM PRINT ARRAY HORIZONTALLY -----
		Example:
			------------------
			|  0  |  1  |  2  | -> indexes
			------------------
			| 10  |  8  |  2  | -> values
			------------------
		*/
		auto PrintHorzVector = [](std::vector<int>& theVec) {
			int dashes = std::ceil(theVec.size() * 6);
			for (int n = 0; n < dashes; n++)
				std::cout << "-";
			yenisatýryaz;

			for (int n = 0; n < theVec.size(); n++)
				printf("| %2d  ", n);
			std::cout << "|\n";

			for (int n = 0; n < dashes; n++)
				std::cout << "-";
			yenisatýryaz;

			for (int n = 0; n < theVec.size(); n++)
				printf("| %2d  ", theVec[n]);
			std::cout << "|\n";

			for (int n = 0; n < dashes; n++)
				std::cout << "-";
			yenisatýryaz;
		};

		std::vector<int> theVec(12);  //{ 10,8,2,5,9,11,6,14 };
		size_t min = 0; size_t max = 20;
		rastgeleUret<int>(theVec, 12, min, max);

		PrintHorzVector(theVec);
	};

	// hepsini test et.
	counter();
	somefunc();
	sumrec();
	morerec();
	sortrec();
	vectorGuzelYaz();
}

ia lambdaDerinlemesine() {
	// Burada Lambda fonksiyonlarý ve biraz stl ile c++ fonksiyonel programlamaya deðineceðim.
	// Lütfen algorithm kütüphanesini kullanýn.
	// Lambda fonksiyonlarýný stl ve fonksiyonel programlamada oldukça önemli yeri vardýr.
	// Lambda fonksiyonlarý içine "[]" statik tanýmlý baþka bir fonksiyon alamaz.
	/*
	 * Lambda fonksiyonlarý tanýtýmý
	 auto lambdaFonksiyonu = [lambda olduðunu ifade eder](parametre listesi) -> (dönüþ tipi)
	 { <kodlar buraya yazýlýr.>
	 };
	 ** <Yakalama Kurallarý "[]">
	 * lambda fonksiyonu "[]" ifadesiyle baþlar. eðer lambda dýþýndan bir deðeri yakalamak istiyorsanýz [var1,var2] diye içine yazmalýsýnýz.
	 * "[=]" içine yazýlan "=" ifadesi dýþýndaki tüm verileri içine kopyalar.
	 * "[&]" içine yazýlan "&" ifadesi dýþýndaki tüm verileri içine referans olarak alýr.
	 * "[var1,&]" içine yazýlan "&" ifadesi dýþýndaki tüm verileri içine referans olarak alýr -> fakat var1 deðerini kopyalar.
	 * "[&var1,=]" içine yazýlan "&" ifadesi dýþýndaki tüm verileri içine kopyalar -> fakat var1 deðerini referans olarak alýr.
	 * C++17 ifadeleriyle artýk oop ifadelerindeki "this" iþaretçisi de içine alýnabilir.
	 ** </Yakalama Kurallarý "[]">
	 *
	 ** "()" ifadesi normal fonksiyonlar gibi her türlü parametreyi tanýmlamakta kullanýlýr.
	 * Lambda fonksiyonlarý "Template" ile kullanýlmaz. Template yerine kýsýtlýda olsa parametre türleri "auto" sözcüðü kullanýlabilir.
	 *
	 ** "-> ()" ok ifadesinden sonra dönüþ tipi belirtilir. fakat genelde gerekli deðildir. C++17 dönüþ tipini birçok durumda derleme zamanýnda belirleyebilir.
	 *
	 ** "{}" kodlar süslü parantez içine yazýlýr.
	 *
	 ** Lambda fonksiyonlarý static, extern, inline, ...const, [[noreturn]], vb. fonksiyonlarýn aldýðý takýlarý alabilir.
	 *
	 ** Lambda fonksiyonlarýný tipi "std::function<dönüþ tipi(parametre tip listesi)>"
	 *
	 ** Lambda fonksiyonlarý derleyici nezlinde birer nesne türündedir. Çok daha iyi optimize etmesi muhtemeldir.
	 * Fakat uzun ifadeler için yinede normal fonksiyonlarý kullanmanýzý tavsiye ederim. Böylece meta programlama kullanabilirsiniz ve
	 derleme zamaný özelliklerinden daha fazla yararlanýrsýnýz.
	 *
	*/
	auto asc = [](auto ilk, auto sonraki) { return ilk < sonraki; }; // ascending , artan
	auto desc = [](auto ilk, auto sonraki) { return ilk > sonraki; }; // descending , azalan

	auto sýrala = [=]() {
		fonksiyonuyaz("<sýrala>");
		auto theVec = rastgeleUret<int>(12, 20, 50);
		ekranayaz << "before sort:"; /* => */ printAll(theVec);
		std::sort(theVec.begin(), theVec.end(), asc);
		ekranayaz << "after sort:"; /* => */ printAll(theVec);
		yenisatýryaz;
		fonksiyonuyaz("</sýrala>");
	};

	auto copyIf = [=]() {
		fonksiyonuyaz("<copyIf>");
		// baþlangýç noktasý, bitiþ noktasý, copyalanacak baþlangýç noktasý ve kopyalama þartý lambda
		auto theVec = rastgeleUret<int>(12, 20, 50);
		std::vector<decltype(theVec)::value_type> evenNums; // value_type == int
		ekranayaz << "before copy_if:"; /* => */ printAll(theVec);
		std::copy_if(theVec.begin(), theVec.end(), std::back_inserter(evenNums), [](auto even) {return !(even % 2); });
		ekranayaz << "after copy_if:"; /* => */ printAll(evenNums);
		yenisatýryaz;
		fonksiyonuyaz("</copyIf>");
	};

	auto fOrEaCh = []() {
		auto theVec = rastgeleUret<int>(12, 20, 50);
		auto sum = 0;
		ekranayaz << "before copy_if:"; /* => */ printAll(theVec);
		std::for_each(theVec.begin(), theVec.end(), [&sum](auto x) {return sum += x; });
		ekranayaz << "sum: " << sum;
		yenisatýryaz;
	};

	auto bolunenleriTopla = []() {
		yenisatýryaz;
		fonksiyonuyaz("<bolunenleriTopla>");

		auto theVec = rastgeleUret<int>(15, 20, 50);
		std::vector<decltype(theVec)::value_type> bolunenler; // value_type == int
		// Girilen N sayýsýna bölünenlerin listesini çýkart
		ekranayaz << "bolen ile bölünenlerin listesi: ";
		auto bolen = 1;
		std::cin >> bolen;
		yenisatýryaz;
		ekranayaz << "theVec: "; /* => */ printAll(theVec);
		std::copy_if(theVec.begin(), theVec.end(), std::back_inserter(bolunenler), [bolen](auto sayý) {return !(sayý % bolen); });
		ekranayaz << "bolunenler: "; /* => */ printAll(bolunenler);
		yenisatýryaz;
		// bolunenler listesindeki elemanlarýn toplamý
		auto sum = 0;
		std::for_each(bolunenler.begin(), bolunenler.end(), [&sum](auto x) {return sum += x; });
		ekranayaz << "sum: " << sum;
		yenisatýryaz;

		fonksiyonuyaz("</bolunenleriTopla>");
	};

	auto doubler = []() {
		fonksiyonuyaz("<doubler>");
		auto theVec = rastgeleUret<int>(12, 10, 100);
		std::vector<decltype(theVec)::value_type> doubleee;
		std::cout << "iki ile çarpýlmadan önce: "; printAll(theVec);
		std::for_each(theVec.begin(), theVec.end(), [&](auto& vec) {doubleee.push_back(vec); });
		std::cout << "iki ile çarpýldýktan sonra: "; printAll(doubleee);
		fonksiyonuyaz("</doubler>");
	};

	auto vectorleriTopla = []() {
		/*
		for_each, for_each_n, apply, transform benzerdir ama farklarý vardýr.
		Bu fonksiyon kullanýmý garip gelebilir.
		girdinin baþlangýcý, girdinin bitiþi, çýktý baþlangýcý ve fonksiyon
		yada
		1. girdinin baþlangýcý, 1. girdinin bitiþi, 2. girdinin baþlangýcý, çýktý baþlangýcý ve fonksiyon

		*/
		fonksiyonuyaz("<vectorleriTopla>");
		auto vec1 = rastgeleUret<int>(5, 10, 100);
		std::vector<decltype(vec1)::value_type> vec2 = { 1,2,3,4,5 };
		std::vector<decltype(vec1)::value_type> sumdepola(vec1.capacity());
		std::transform(vec1.begin(), vec1.end(), vec2.begin(), sumdepola.begin(),
			[](auto x1, auto x2) { return x1 + x2; });
		std::cout << "sum: "; printAll(sumdepola);
		fonksiyonuyaz("</vectorleriTopla>");
	};

	sýrala();
	copyIf();
	fOrEaCh();
	bolunenleriTopla();
	doubler();
	vectorleriTopla();
	auto fibgene = fibUret<int>(10);
	std::cout << "generated fibonacci series: "; printAll(fibgene);

	std::cin.get();
}

ia oops() {
	/*
		Üç farklý çok bilinen temel programlama þekli vardýr. imperative, functional, oops
		Bu programlama stillerinden hiçbirinin bilgisayar için farký yoktur, hepsi derlendiðinde ikili koda derlenir.
		Sadece bazý problemlerin çözümünde bazý programlama tarzlarý kolaylýk saðlar.
		* C++ üç tarzda programlamayý destekler. Yeni versiyonlar geldikçe fonksiyonel programlama öðeleri artmaktadýr.
	* oop = object oriented programing
	bu þekildeki programlamada nesne içine gerekli tüm deðiþkenler ve bu deðiþkenlerin davranýþlarýný
	belirleyen fonksiyonlar yazýlýr. Gerekli veriler ve fonksiyonlar tek çatý altýnda toplandýðýndan kullanýmý
	kolaylaþýr. Nesne tasarýmý ile hem hafýza hemde iþlev organizasyonu kolaylaþýr.
	Polimorphizm, inheritance, class, object, vb. kavramlar bu tarzýn öðeleridir.

	Günümüze kadar oops tabanlý diller revaþtaydý fakat veri iþlemede fonksiyonel tarzýn kullanýmýnýn daha kolay
	olduðu görüldü. Çok çekirdekli iþlemciler fonksiyonel tarz ile programlamak daha anlaþýlýrdýr.
	*/
	auto basitClass = []() {
		// buradaki deðiþkenler, fonksiyonlar ve tanýmlar "Classlar" filtresindedir.
		// Animal.h ve Animal.cpp dosyasýna bakýn
		Animal animal1; // varsayýlan oluþturucu çalýþacak.
		animal1.PrintAll(true); // "", 0, 0 yazýrmasý bekliyorum.
		animal1.SetName("maymum");
		animal1.SetHeight(50);
		animal1.SetWeight(20);
		animal1.PrintAll(true); // ayarlanmýþ haliyle 

		Animal animal2("fil", 200, 800);
		auto numAnimals = Animal::GetNumOfAnimals();
		std::cout << "Kaç tane Animal var? " << numAnimals << std::endl;

		// Dog oluþturucu
		Dog kopek("atýl kurt", 38, 15, "wooof"); // dog ayný zamanda Animal classýný oluþturur.
		kopek.PrintAll(true);
		//Dog oluþtuktan sonra acaba kaç tane Animal oluþtu.
		numAnimals = Animal::GetNumOfAnimals();
		std::cout << "Kaç tane Animal var? " << numAnimals << std::endl;

		// tüm classlar yýkýcýlar tarafýndan oluþturulmaz sýrasýnýn tersi ile yýkýlýr.
		// yýkýlma sýrasý: ~dog(atýl kurt), ~animal(atýl kurt), ~animal(fil), ~animal(maymum)
	};

	auto savaþMeydaný = []() {
		class savascý {
		private:
			int attkMax;
			int blockMax;
		public:
			std::string name;
			int can;
			savascý(std::string name, int can, int attkMax, int blockMax) {
				this->name = name; this->can = can;
				this->attkMax = attkMax; this->blockMax = blockMax;
			}
			int boostRand() {
				// ufak bir eklenti.
				// matematiksel þart saðlanýrsa blok ve atak artacak.
				auto& a = this->attkMax;
				auto& b = this->blockMax;
				auto norm2 = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
				auto sart = norm2 > 35; // berbat bir çözüm
				return sart ? std::rand() % static_cast<uint64_t>(std::ceil(norm2)) : 0;
			}

			// The attack and block amount will be random
			int Attack() {
				return std::rand() % this->attkMax;
			}
			int Block() {
				return std::rand() % this->blockMax;
			}
		};

		class CenkMeydani {
		public:
			// savaþ savaþçýlarýn caný "can < 0" þartý saðlanana kadar devam edecek.
			static void Fight(savascý& savascý1, savascý& savascý2) {
				while (true) {
					// string karþýlaþtýrma sonucu ayný çýktýðýnda "null" yani 0 verir ama asmde ...==0 daha fazla kod üretiyor.
					if (!CenkMeydani::GetAttackResult(savascý1, savascý2).compare("Oyun Sonu")) {
						std::cout << "--- Oyun Sonu ---\n"; break;
					}
					if (!CenkMeydani::GetAttackResult(savascý2, savascý1).compare("Oyun Sonu")) {
						std::cout << "--- Oyun Sonu ---\n"; break;
					}
				}
			}

			static std::string GetAttackResult(savascý& savascýA, savascý& savascýB) {
				// Get random attack & block amounts and calculate damage
				auto savascýAboost = savascýA.boostRand(); int savascýAAttkAmt = savascýA.Attack() + savascýAboost;
				auto savascýBboost = savascýB.boostRand(); int savascýBBlockAmt = savascýB.Block() + savascýBboost;
				int damage2savascýB = ceil(savascýAAttkAmt - savascýBBlockAmt);

				// Change can total if > 0 and output changes
				damage2savascýB = (damage2savascýB <= 0) ? 0 : damage2savascýB;
				savascýB.can = savascýB.can - damage2savascýB;
				printf("%s saldýrýr %s %d hasar alýr.\n", savascýA.name.c_str(), savascýB.name.c_str(), damage2savascýB);
				printf("%s -> %d caný\n", savascýB.name.c_str(), savascýB.can);
				printf("%s aldýðý boost %d\n", savascýA.name.c_str(), savascýAboost);

				// "can < 0" þartý bir kez saðlandý mý "Oyun Sonu" dönüþüyle biter.
				if (savascýB.can <= 0) {
					printf("%s öldü %s kazandý\n", savascýB.name.c_str(), savascýA.name.c_str());
					return "Oyun Sonu";
				}
				else { return "Yeniden Savaþ"; /* Gerek yok ama hiçbir þey dönmemesi hataya sebep olabilir. */ }
			}
		};

		srand(time(NULL)); // Rastgelelik saðlanýyor.
		// Savaþçýlarýn isimleri ve özellikleri verilir.
		savascý Batman("Batman", 100, 35, 15);
		savascý Superman("Superman", 125, 25, 10);
		// Savaþ bitene kadar devam eder.
		CenkMeydani::Fight(Batman, Superman);

	};

	auto structYapýsý = []() {
		struct shape // struct, class ile çok benzer. veriler varsayýlan olarak "public" tir.
		{ // Teknik ayrýntýlarýný en.cppreferance sitesinden okuyabilirsiniz.
			double lenght, witdh;
			shape(double le = 1, double wi = 1) : lenght{ le }, witdh{ wi } // fonksiyon gövdesine gerek kalmadý.
			{}
			double area() { return lenght * witdh; }
		private: // private olabiliyor. 
			int id;
		};
		struct circle : shape // varsayýlan olarak "public" dir.
		{
			circle(double wi) { this->witdh = wi; }
			double area() { return std::_Pi * std::pow((witdh / 2.0), 2.0); }
		};

		shape þekil(10, 20);
		std::cout << "þekil alaný: " << þekil.area() << std::endl;
		shape dikdörtgen{ 15,22 };
		std::cout << "dikdörtgen alaný: " << dikdörtgen.area() << std::endl;

		circle daire(5);
		std::cout << "daire alaný: " << daire.area() << std::endl;
	};

	auto friendClass = []() {
		class musteri {
		private:
			friend class veriCek; // "private" olsa da friend olduðundan eriþim saðlanabilir.
			std::string name; // "private" olduðu için eriþim saðlanamaz.
		public:
			musteri(std::string sname) : name{ sname } {}
		};

		class veriCek
		{
		public:
			static std::string GetName(musteri& must) { return must.name; }
		};

		musteri m{ "selami" };
		veriCek v;
		std::cout << "Name: " << v.GetName(m) << std::endl;
	};

	auto Polimorphizm = []() {
		/*
		Çok biçimlilik java ve C# dillerinde daha iyi ifade edilse de c++ aþaðý kalýr yaný yok.
		Temel kelime "virtual" kelimesidir.

		*/
		class shape
		{
		protected:
			double height, witdh;
		public:
			shape() = default; // bu kelime "shape daire()" þeklindeki boþ kullanýmda derleyicinin yapýcýyý otomatik oluþturmasýný saðlar.
			shape(double he) : height{ he }, witdh{ he } {}
			shape(double he, double wi) : height{ he }, witdh{ wi } {}
			// virtual kelimesiyle artýk shape::area() yada using shape::area ullanmak pek gerekli deðil.
			// pratikte tekrar tekrar fonksiyonu tanýmlayabilmemizi saðlar.
			// virtual kelimesiyle tanýmlanan fonksiyonlar binary içinde "V table" ile kaydedilir.
			// sadece taban(base) class içine yazýlmasý yeterlidir.
			virtual double area() { return height * witdh; }
		};
		class circle : public shape
		{
		public:
			circle(double rad) : shape(rad) {}
			double area() { return std::_Pi * std::pow(witdh / 2, 2); }
		};

		auto GetTheShape = [](shape& sh) { std::cout << "area: " << sh.area() << std::endl; };
		//Polimorphizm baþlýyor dikkaaat!
		shape kare(10, 10);
		GetTheShape(kare);
		circle daire(15);
		GetTheShape(daire);


	};

	auto fullVirtualPolimorphizm = []() {
		// Teþekkür ederim. Çok iyi bir örnek
		// http://www.newthinktank.com/2018/04/c-tutorial-11-2/
		// override kullanmanýzý tavsiye ederim.
		class Shape {
		public:
			// java ve c# interface kelimesinin karþýlýðý olarak "full virtual class" oluþturulur ve
			// fonksiyon gövdeleri sorunsuz dekilde tekrardan yazýlabilir yoksa linker hatalarý alabilirsiniz.
			virtual double Area() = 0; // tam anlamýyla sanal bir sýnýf.
		};

		class Circle : public Shape {
		protected:
			double width;
		public:
			Circle(double w) : width{ w } {}
			// Override Area()
			// override ile temel sýnýfýn virtual olduðunu kontrol eder.
			double Area() override { return 3.14159 * std::pow((width / 2), 2); }
		};

		class Rectangle : public Shape {
		protected:
			double height, width;
		public:
			Rectangle(double h, double w) : height{ h }, width{ w } {}
			// Override Area()
			// override ile temel sýnýfýn virtual olduðunu kontrol eder.
			double Area() override final { return height * width; }
		};

		class Square : public Rectangle {
		public:
			Square(double h, double w) : Rectangle(h, w) {}
			/* // Rectangle temel sýnýf olmadýðýndan derleme hatasý
			double Area() override{
			return height * 2;
			}
			*/
		};

		// doðru Area() otomatik kullanýlýr.
		auto ShowArea = [](Shape& shape) { std::cout << "Area : " << shape.Area() << "\n"; };

		Rectangle rectangle(10, 5);
		Circle circle(10);
		ShowArea(rectangle);
		ShowArea(circle);

		Square square(10, 10);
		ShowArea(square);

	};

	basitClass();
	savaþMeydaný();
	structYapýsý();
	friendClass();
	Polimorphizm();
	fullVirtualPolimorphizm();

}

ia overloadFileIO() {
	auto overload = []() {
		/*
		<h1> Operator overload, File I/O iþlemleri </h1>

		* "Overload" yani aþýrý yükleme nedir ve nasýl yapýlýr? Overload ile Override karýþtýrýlmamalýdýr.
		* "Override" ayný girdi, çýktý ve fonksiyon isimle tekrardan yazmak manasýna gelir.
		Derleyici hata yada uyarý mesajý verebilir. Bu yüzden Modern C++ ile virtual,overload,final kelimeleri gelmiþtir.
		* Aþýrý yükleme iþlemi, ismi ayný olan fonksiyonlarý veya operatorleri farklý giriþ çýkýþlarla farklý
		görevlerde kullanmak üzere yeniden yazmaktýr. Fazladan tanýmlayýcý kelimeye ihtiyaç duymadan
		derleyici uygun fonksiyonu seçerek kullanabilir.
		*/
		kutucuk kutu1(5, 5, 5), kutu2(10, 10, 10);
		auto pre = ++kutu1;
		std::cout << "pre-increment before: " << pre << std::endl; //operator const char*() sayesinde
		std::cout << "pre-increment after: " << kutu1 << std::endl; //operator const char*() sayesinde
		auto post = kutu1++;
		std::cout << "post-increment before: " << post << std::endl; //operator const char*() sayesinde
		std::cout << "post-increment after: " << kutu1 << std::endl; //operator const char*() sayesinde

		kutu2.operator++(); // aynýsý.
		std::cout << "operator const char*() sayesinde" << kutu2.operator const char *() << std::endl;

		std::cout << "kutu1 + kutu2= " << kutu1 + kutu2 << std::endl;
		std::cout << "kutu2.lenght" << kutu2[0] << std::endl; // operator fonksiyonuna dikkat!
		std::cout.setf(std::ios::boolalpha); // bool veri yazdýrsýn.
		// "<<" operatorünü aþýrý yüklemediðim için parantez olmadan derlenmez. 
		std::cout << "kutular eþit mi?" << (kutu1 == kutu2) << std::endl;
		std::cout << "kutu1 küçük mü?" << (kutu1 < kutu2) << std::endl;
		std::cout << "kutu1 büyük mü?" << (kutu1 > kutu2) << std::endl;

		kutucuk kutu3 = kutu1;
		std::cout << "kutu3 ataný mý? " << kutu3 << std::endl;
	};

	auto fileIO = []() {
		/*
		<h1> File I/O == Dosya sistemi Giriþ/Çýkýþ </h1>

		* Dosya sisteminden kastým sadece klasörler ve ofis dosyalarýnýz deðil tüm giriþ ve çýkýþlar.
		* Dosya sistemi disklere ve diðer bellek türlerine ve tüm giriþ çýkýþlarý yöneten bir birimdir.
		* Her iþletim sisteminde farklý bir dosya sistemi kullanýlýyor. Windows ntfs, Linux exfat(1,2,3,4)
		* Dosya giriþ ve çýkýþ hýzý iþletim sistemine ve bilgisayara baðlýdýr, programlama diline deðil.
		programlama dili iþletim sistemine komutu verir ve sonucu alýr.
		* Usb ve monitor giriþ çýkýþýda ayný komutlarla saðlanabilir fakat windows iþletim sisteminde win32api yada .net
		kullanýlmasý tavsiye ederim.

		* Tabi amacým bu temel Modern c++ sonrasýnda Qt anlatmak olacak ve Qt ile genelde baþka frame ihtiyacý duyulmuyor.
		* Qt ile giriþ çýkýþ iþlemi daha kolay.

		* Türkçe karakter kaydetmek ve okumak uzun iþ o yüzden þimdilik es geçeceðim.

		*/

		const std::string& dosyaAdý = "birDosya.txt";
		/*
		* dosya çýkýþýnýn manasý ram yada baþka bir bellekten verilerin alýnýp
		dosyanýn oluþturulup içine veri kaydedilmesidir.*/
		std::ofstream writeToFile; // dosya çýkýþ akýmý
		std::string txtToFile;

		writeToFile.open(dosyaAdý, std::ios::out | std::ios::trunc); // çýkýþ ve eðer veri varsa üzerine yaz.
		if (writeToFile.is_open()) {
			writeToFile << "Merhaba Dosya" << std::endl <<
				"Günün hayýr olsun." << std::endl <<
				"Yazdýklarýn Burada:\n";
			std::cout << "Dosya hazýr, yazmaya baþlayabilirsin." << std::endl;
			std::getline(std::cin, txtToFile);
			writeToFile << txtToFile;
			writeToFile.close();
		}
		else {
			std::cout << "dosya açýlamadý." << std::endl;
		}


		/* *dosya giriþi dosyadaki verilerin alýnmasý ve ram yada baþka bir belleðe kaydedilmesidir.*/
		std::ifstream readFromFile; // dosya giriþ akýmý
		std::string fileToText;

		readFromFile.open(dosyaAdý, std::ios::in);
		if (readFromFile.is_open()) {
			while (readFromFile.good()) { //good yani iþler iyi gittii sürece, 
				getline(readFromFile, txtToFile);
				std::cout << txtToFile << std::endl;
				// challenge from derek banas :)
				std::vector<std::string> cümle = functionalStyle::StringToVector(txtToFile, ' ');
				auto satýrdakiKelime = cümle.size();
				std::cout << "Satýrdaki kelime sayýsý: " << satýrdakiKelime << std::endl;
				auto karakterSayacý = 0;
				for (auto kelime : cümle)
					for (auto karakter : kelime)
						++karakterSayacý;
				auto ortKelimeUzunluk = karakterSayacý / satýrdakiKelime;
				std::cout << "Satýrdaki ortalama kelime uzunluðu: " << ortKelimeUzunluk << std::endl;

			}
			readFromFile.close();
		}




	};

	overload();
	fileIO();
}

ia ileriFonksiyonlar() {
	/*
	<h1> fonksiyonel programlama, fonksiyon parametreleri, vector fonksiyonlarý </h1>

	* Aslýnda bu zamana kadar hep fonksiyonlarý kulandýk. ancak daha ileri konularý göreceðiz.
	* fonksiyonel prograglamlama idiomunu daha önceden oops içinde anlatmýþtým. lütfen inceleyin.
	* c dilindeki fonksiyon iþaretçilerinin aksine c++da fonksiyon objesi bulunuyor. std::function<...(...)>
	*/
	// fonksiyonlar.cpp
	auto fonksiyonel = []() {
		// 1. You can store functions as variables
		auto times2 = MultBy2;
		std::cout << "5 * 2 = " << times2(5) << "\n";

		// 2. Pass a function into a function
		std::cout << "6 * 2 = " << DoMath(times2, 6) << "\n";

		// 3. You can store functions in a vector
		// Create a vector using the function parameters
		// and then load the functions into the vector
		std::vector<std::function<double(double)>> funcs(2);
		funcs[0] = MultBy2;
		funcs[1] = MultBy3;
		std::cout << "2 * 10 = " << funcs[0](10) << "\n";

		// 4. ----- PROBLEM -----
		// Create a function that receives a list and a function
		// The function passed will return True or False if a list
		// value is odd.
		// The surrounding function will return a list of odd
		// numbers
		std::vector<int> listOfNums{ 1,2,3,4,5 };
		std::vector<int> oddList = ChangeList(listOfNums, IsItOdd);
		std::cout << "List of Odds\n";
		for (auto i : oddList) {
			std::cout << i << "\n";
		}
		// ----- 4. END OF PROBLEM -----

		// ----- 5. PROBLEM -----
		// Rastgele toplamda 100 tane karakter listesindeki karakterleri üret ve kaç tane üretildiðini say.!
		std::vector<char> possibleValues{ 'H', 'T' };
		auto N = 100;
		std::vector<char> hAndTList = GetHAndTList(possibleValues, N);
		const auto& HeadNumbers = GetNumberOfMatches(hAndTList, 'H'); // Tekrar tekrar kodun çalýþtýrýlmasý hoþuma gitmiyor.
		const auto& TailNumbers = N - HeadNumbers;
		std::cout << "Number of Heads : " << HeadNumbers << "\n";
		std::cout << "Number of Tails : " << TailNumbers << "\n";
		// ----- 5. END OF PROBLEM -----
	};
	fonksiyonel();
}

template<typename type> // template ;)
type doubler(type num) { return num * 2; }
ia templateVeItarator() {
	fonksiyonuyaz("templateVeItarator");
	/*
	<h1> Dýþarýdan dosya dahil etmek, ön iþlemci, "TEMPLATE"(iskelet), iterator,... </h1>

	* Dýþarýdan header yada cpp dosyalarýný dahil etmeyi zaten sürekli yapýyoruz.
	#include <> yada #include "" ile baþlýk dosyalarý derleme zamanýnda dahil ediliyor. Oldukça basit.
	Program yapýmýný parçalara ayýrabilmemizi saðlýyor böylece kodlar daha anlaþýlýr oluyor.

	* ön iþlemci= derleme zamanýnda yapýlan iþlemleri yapan iþlemcidir.
	derleme zamanýnda kod kontrolü -> #ifdef-#endif, #ifndef-#endif
	derleme zamaný sabit ve fonksiyon tanýmlama yada ad deðiþtirme -> #define(pek sevilmiyor ve eskide kaldý. constexpr yerini aldý.)
	derleme zamaný dosya dahil etmek -> #include
	derleme zamanýnda derleyiciye özel komut iletmek -> #pragma(buradaki komutlar her derleyicide deðiþebilir.)

	* Template(iskelet) yine derleme zamaný yapýlan bir takým iþlemlerdir. Fonksiyonlarý her defasýnda farklý
	veri tiplerine uygun yazmaktan kurtarýr. Bir fonksiyon iskeleti hazýrlanýr ve istenilen veri tipleriyle
	kullanýlýr ve derleyici fonksiyonu kullanýlan her veri tipi için üretir. Derleme hýzýný azaltýr ama
	kod yazma hýzýný arttýrýr.

	* Iterator veri dizisi üzerinde dolaþmaya yarayan araçtýr. Modern C++ ile varsayýlan bir özellik olmuþtur.
	iteratorler stl içindeki hemen hemen tüm "container" saklayýcýlar için standarttýr. Yani hafýzaya eriþimi
	tüm tutucular için standartlaþtýrmýþ oluyoruz.

	*/

	auto headerKorumasý = []() {
		fonksiyonuyaz("headerKorumasý");
		/*
		Header dosyalarýný tanýmlarken þunlara dikkat edin!
		* .h, .hpp,.hxx gibi dosya türlerini include ile kullanmayýn. ön iþlemci dosya tðrðne bakmadan dahil eder.
		* eðer projenizde iki baþlýk dosyasý birbirleirne baðlý ise ilkini ikincisine ikincisini ilkine
		dahil etmeyin. Böle bir davranýþ program çalýþsa bile ve Modern derleyici ile çalýþýyor olsanýz bile
		bile büyük sorunlara yol açabilir. Sorunun adý "cyclic referance" olarak geçiyor.
		SORUNUN ÖRNEÐÝ "YararlýFonksiyonlar.h" ve "functionalStyle.h" ARASINDA BELÝRTTÝM.
		* ikinci sorunla baþ etmenin en iyi yollarýndan biri "baþlýk korumasý"dýr.
		*/
		// Animal classý Animal.h içindedir
#include "Animal.h" // header korumasý derleme sýrasýnda birkaç kez dahil etmeyi önler.
#include "Animal.h"
#include "Animal.h"

		Animal spot = Animal();
		spot.SetName("spot");
		std::cout << "Lan! Animal " << spot.GetName() << " arabayý ne biçim sürüyorsun?" << std::endl;
	};

	auto defineTanýmý = []() {
		fonksiyonuyaz("defineTanýmý");
#define PI 3.14159265358979323846264338327950288L
#define Alaný(r) PI*std::pow(r,2)
		std::cout << "Dairenin alaný: " << Alaný(7) << std::endl;
	};

	auto templateDurumu = []() {
		fonksiyonuyaz("templateDurumu");
		/*
		fonksiyonlar.cpp dosyasýnda MultBy2 fonksiyonunu kullandým.
		* Lambda fonksiyonlarý template ile kullanýlamýyor hala ama template yerine auto sözcüðü iþ görüyor.
		*/
		// eski versiyon
		std::cout << "MultBy2<int>(5)= " << doubler<int>(5) << std::endl;
		std::cout << "MultBy2<double>(5)= " << doubler<double>(6.86) << std::endl;
		// yeni versiyon
		std::cout << "MultBy2(5)= " << doubler(8) << std::endl;
		std::cout << "MultBy2(5.5)= " << doubler(7.6) << std::endl;

		/* visual c++ yeni þekil tanýmlamayý pek sevmiyor.
		 cpp içinde tanýmlayýp header içine prototip yerleþtirirseniz lnk2001 hatasýný veriyor yani linker hatasý
		ÇÖZÜM;
		class sorununun çözümü: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
		1) header içinde, ayný dosyada yada class olarak tanýmlamak.
		2) header içinde extern olarak tanýmlamak: https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
		sadece fonksiyon prototipinde extern tanýmlamak. extern gerçekten iþe yarýyor.
		3) Modern c++ export kelimesi: https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl-export-keyword
		derleyici destekelemek zorunda ve daha tam olarak standart bir kelime deðil.

		*/
		std::cout << " 5 + 7 = " << Add(5, 7) << std::endl;
		std::cout << " 5.7 + 7.5 = " << Add(5.7, 7.5) << std::endl;

		std::cout << " 4 < 6 " << Max(4, 6) << std::endl;
		std::cout << " 'B' < 'N' " << Max('B', 'N') << std::endl; // sadece python içinde mi var :D
		std::cout << " Bana < Nine " << Max("Bana", "Nine") << std::endl; // sadece python içinde mi var :D


	};

	auto templateClass = []() {
		fonksiyonuyaz("templateClass");
		Person<double, int> mikeTyson(5.83, 216);
		mikeTyson.GetData();
		std::cout << "Number of people : " << mikeTyson.numOfPeople << "\n";
	};

	auto Iteratorler = []() {
		fonksiyonuyaz("Iteratorler");
		/*
		* itaratör bir sayaçtýr. veri dizileri üzerinde gezinmemizi saðlar. Tek farký bazen biraz daha
		hýzlý eriþim saðlayabilir ve performansý arttýrabilir.
		* Fonksiyonel programlamada çok iþe yarar.
		* c++ stl hazýr veri yapýlarý kütüphanelerinde hazýr iteratörler mevcuttur.
		daha önceden sýkça kullandým. ileriki aþamalarda class tanýmlarken iterator tanýmlayacaðýz
		ama þimdilik hazýrlarý kullanalým.
		*/

		// deque "double ended que" yani std::list tek ileriye baðlý liste ise deque hem ileri hem geriye baðlý listedir.
		std::deque<int> nums = { 1,2,3,4 };
		nums.push_front(0);
		nums.push_back(5);
		printAll(nums);

		// Böyle eriþim mümkün fakat içeriðini bilmeyenler için performans sorunu oluþturabilir.
		std::cout << nums[0] << "\n";

		// ----- ITERATORS -----
		// itr num2 vektörü hafýzada nerede kayýtlýysa oraya iþaret eder.
		std::vector<int> nums2 = { 1,2,3,4 };

		// veri ile ayný tipte olmalý
		std::vector<int>::iterator itr;

		// vektörün baþlangýç ve bitiþ noktalarýna iþaret edebiliriz.
		for (itr = nums2.begin(); itr < nums2.end(); itr++) {
			std::cout << *itr << std::endl; // pointer olduðunu söylemiþtim.
		}

		// vekörün baþlangýç noktasý yani nums[0]
		std::vector<int>::iterator itr2 = nums2.begin();

		// 2 tane ilerle yani 2 tane ileriye iþaret et
		advance(itr2, 2);
		std::cout << *itr2 << yenisatýr;

		// 1 tane daha ilerler fakat dönüþte iterator tipini geri yollar. pythona çok benziyor.
		auto itr3 = next(itr2, 1);
		std::cout << *itr3 << "\n";

		// 1 tane geri gider fakat dönüþte iterator tipini geri yollar. pythona çok benziyor.
		auto itr4 = prev(itr2, 1);
		std::cout << *itr4 << "\n";

		// belli indexlerden itibaren birleþtirme yapabilirsin..
		std::vector<int> nums3 = { 1,4,5,6 };
		std::vector<int> nums4 = { 2,3 };
		auto itr5 = nums3.begin();
		advance(itr5, 2);

		// std::inserter(data, data-iterator) // data-iterator belirtilen konumda aktarmaya baþlar.
		// iterator index gibi davranmaz.
		// copy( kopyalanacak.begin, kopyalanacak.end, inserter(kopyalanan, kaçýncýsýndan itibaren) );
		copy(nums4.begin(), nums4.end(), std::inserter(nums3, itr5));
		copy(nums4.begin(), nums4.end(), std::inserter(nums3, std::next(nums3.begin()))); // 2.seçenek

		printAll(nums3);

	};

	headerKorumasý();
	defineTanýmý();
	templateDurumu();
	templateClass();
	Iteratorler();
}

ia SmartPointers_PolymorphicTemplates() {
	auto eskihafýzaAyýr = []() {
		// c dilindeki hafýza ayýrma tekniði. idare etmesi büyük projelerde zorlaþýyor.
		int amtToStore;
		std::cout << "How many numbers do you want to store : ";
		std::cin >> amtToStore;
		int * pNums;

		// int türünde olduðuna emin ol.
		pNums = (int *)malloc(amtToStore * sizeof(int));

		// hafýza ayrýldý mý kontrol et.
		if (pNums != NULL) {
			int i = 0;

			// depola
			while (i < amtToStore) {
				std::cout << "Enter a Number : ";
				std::cin >> pNums[i];
				i++;
			}
		}

		std::cout << "You entered these numbers\n";
		for (int i = 0; i < amtToStore; i++) {
			std::cout << pNums[i] << "\n";
		}

		delete pNums; // hafýzayý sil



	};

	auto yenihafýzaAyýr = []() {
		/*
		* autoptr, scopeptr, uniqueptr, sharedptr, weakptr,... gibi çokça akýllý iþaretçi üzerine 20 senedir
		çalýþýyor. hemen hemen her framework kendi iþaretçi kütüphanesini oluþturmuþ durumda. stl olaný anlatacaðým.
		* Temel özelliði RAII(resourse aqcusition is initialization) ile bir tür otomatik hafýza silme sistemi.
		Bu özelliði saðlarken de olasý aksaklýklara ve hafýza açýklarýna karþý koruma saðlamak.
		*/
		int amtToStore;
		std::cout << "How many numbers do you want to store : ";
		std::cin >> amtToStore;
		// hafýza otomatik ayrýlýp parantez çýkýþýnda silinecektir.
		std::unique_ptr<int[]> pNums(new int[amtToStore]);

		// unique_ptr kopyalanamaz. sadece bir sahipliðe sahiptir.
		// std::unique_ptr<int[]> pNums2 = pNums;

		if (pNums != NULL) {
			int i = 0;
			// depola
			while (i < amtToStore) {
				std::cout << "Enter a Number : ";
				std::cin >> pNums[i];
				i++;
			}
		}

		std::cout << "You entered these numbers\n";
		for (int i = 0; i < amtToStore; i++) {
			std::cout << pNums[i] << "\n";
		}


	};

	auto cokBicimliTemplate = []() {
		// unique_ptr gerek kalmadýðý "pizzaOrders" nesnesini siler
		std::vector<std::unique_ptr<Pizza>> pizzaOrders;

		// vector referanslarý emplace_back ile depolar.
		// derleme zamanýnda pizza çeþitlerini çok biçimlilik sayesinde oluþturur.
		// Önemli! en son dahil edilen yani en içerdeki en son çaðýrýlýr.
		pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
		pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

		// pizzalar servis edilir :)
		for (auto &pizza : pizzaOrders) {
			pizza->MakePizza();
		}

	};

	eskihafýzaAyýr();
	yenihafýzaAyýr();
	cokBicimliTemplate();

	std::cin.get();
}

ia threadVeZamanlama() {
	/*
	<h1> Threads, zamanlama, dinamik bellek, paylaþýlan kaynaklarýn korunmasý ve örnekler </h1>

	* Thread denenþey bilgisayarýn birden fazla çekirdeðini kullanabilmemizi saðlar.
	Þimdiye kadar yaptýðýmýz yazýlýmlar sadece bir çekirdeði kullanabiliyordu. Çoðunlukla performans
	ve daha akýcý programlar yapmak üzere kullanýlýr.
	** Thread her sistemde farklý þekilde baþlatýlabilir yada her sistemin kendisine has özellikleri olabilir.
	bunlarý açýklamak zorunda kalýrsam yada araþtýr dersem lütfen araþtýrýn.

	* zamanlama yani süre tutma, süreleri karþýlaþtýrma ve programý veya threadi belli bir süre uyutmak

	* paylaþýlan kaynaklarýn korunmasý. threadler ayný anda ayný veriye eriþmeye çalýþtýðýnda program bozulur.
	bu sorunun üstesinden gelmeye çalýþacaðýz.

	*/

	/*threadBasic * taskPtr = new threadBasic();
	std::thread th1(&threadBasic::ExecuteThread, taskPtr, "Thread1");
	th1.join();

	std::thread th2(&threadBasic::ExecuteThread, taskPtr, "Thread2");
	th2.join();

	delete taskPtr;*/

	auto veryBasicThread = []() {
		// fonksiyonlar YararlýFonksiyonlar.h ve generateRandom.h içinde mevcut.
		fonksiyonuyaz("veryBasicThread");
		std::thread first(foo);     // yeni thread foo() fonksiyonunu çaðýrýyor.
		std::thread second(bar, 0); // yeni thread bar(0) fonksiyonunu çaðýrýyor.

		std::cout << "main, foo and bar þimdi yürütülüyor...\n";

		// synchronize threads:
		first.join();                // ilki bitene kadar bekler
		second.join();               // ikincisi bitene kadar bekler

		std::cout << "foo and bar tamamlandý.\n";

		// Diðer örnek ve zamanlama fonksiyonlarý
		fonksiyonuyaz("zamanlama fonksiyonlarý");
		std::thread th1(task1, "hello thread");
		th1.join();
		std::thread th2(printThread, 15);
		th2.join();

	};

	auto Thread1 = []() {
		fonksiyonuyaz(" Thread1 -> ExecuteThread");
		std::thread th1(ExecuteThread, 1);
		th1.join();
		std::thread th2(ExecuteThread, 2);
		th2.join();
	};

	auto paraçek = []() {
		std::thread threads[10]; // thread dizisi oluþturdum.

		for (int i = 0; i < 10; ++i) {
			threads[i] = std::thread(GetMoney, i, 15);
		}

		for (int i = 0; i < 10; ++i)
			if (threads[i].joinable()) // yeni versiyonda bu fonksiyon kullanýlmaz ise _INVALID_ARGUMENT exception yolluyor.
				threads[i].join();

	};

	auto primeNums = []() {
		fonksiyonuyaz("primeNums");
		std::cout.flush();
		std::setvbuf(stdout, NULL, _IONBF, 0); // performans sebeplerinden ötürü gerekmedikçe uygulanan bir yöntem deðildir.
		// ekrana çkan buffer sýnýrýný ortadan kaldýrýr ve yazma sayýsý sýnýrlanmaz.
		auto primeNumsThreadYok = []() {
			fonksiyonuyaz("    primeNumsThreadYok");
			//std::vector<unsigned int> primeVect;

			// zamaný ölçmek istiyorum tic-toc
			int startTime = clock();
			std::vector<unsigned int> primeVect;
			FindPrimes(1, 100000, primeVect);
			for (auto i : primeVect)
				std::cout << i << "\n";

			// en sornunda ne kadar zaman geçti
			int endTime = clock();

			// saniye cinsine çevir
			std::cout << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
		};

		auto primeNumsThreadVar = []() {
			fonksiyonuyaz("primeNumsThreadVar");
			int startTime = clock();
			FindPrimesWithThreads(1, 100000, 3);
			int endTime = clock();

			for (auto i : primeVect)
				std::cout << i << "\n";

			std::cout << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
		};
	
		// hýzý anlamak için "release" versiyonunda çalýþtýrýn.
		primeNumsThreadYok();
		primeNumsThreadVar();
	};

	

	//veryBasicThread();
	//Thread1();
	//paraçek();
	primeNums();
}

ia sequenceContainer() {
	/*
	<h1> Tüm liste veri tipleri(list, deque, forward_list) </h1>

	vector en hýzlý ve en temel liste tipidir ama bazý problemlerde farký liste tiplerine de ihtiyaç vardýr.
	* list: vektor gibi ama daha fazla yer kaplýyor. oldukça etkili
	* deque: vektor gibi ama hem ileri hem geri baðlý liste
	* forward_list: sadece ileriye baðlý liste ve bazý durumlarda çok hýzlý çalýþabiliyor ama sýnýrlarý var.
	* 
	*/
	auto ciftmi = [](auto sayý) { return sayý % 2 == 0;	};
	auto dequeTanýmý = []() {
		fonksiyonuyaz("dequeTanýmý");
		std::deque<int> deq1;
		deq1.assign({45,32});
		deq1.push_back(15);
		deq1.push_back(16);
		std::cout << "size deq1: " << deq1.size() << std::endl;
		std::cout << "deq1[0]: " << deq1[0] << std::endl;
		std::cout << "deq1[2]: " << deq1[2] << std::endl;

		auto itdeq1 = deq1.begin() + 1;
		deq1.insert(itdeq1, 3);
		int tempArr[5] = { 6,7,8,9,10 };
		deq1.insert(deq1.begin(), tempArr, tempArr + 5);
		std::cout << "size deq1: " << deq1.size() << std::endl;
		auto ee = deq1.end()-2;
		deq1.erase(ee);
		auto deqbegin = deq1.begin();
		deq1.erase(deqbegin, deqbegin + 2);// ilk iki elemaný sil
		deq1.pop_front();// ilk elemaný listeden at.
		deq1.pop_back();// son elemaný listeden at.
		std::deque<int> deq2(2, 50);// 2 elemaný 50 olan liste
		deq1.swap(deq2);// deðiþ tokuþ
		
		printAll(deq1);

		deq1.clear();// her þeyi siler
	};
	auto listTanýmý = [ciftmi]() {
		fonksiyonuyaz("listTanýmý");
		// herhangi bir konumdan eklemede, nesneleri hareket ettirmede, nesnelere eriþmede en etkili elemandýr.
		//int arr[5]{1,2,3,4,5};
		std::array<int, 5> arr{1,2,3,4,5};
		std::list<int> ll;
		ll.assign({8,85,852,258});
		ll.insert(ll.begin(),arr.begin(),arr.end());
		ll.push_back(10);
		ll.push_back(77);
		std::cout << "size list: " << ll.size() << std::endl;
		// ekranayaz << "ll[0]" << ll[0] << std::endl; // böyle eriþim yok ama...
		// iteratörer iþimizi görecektir.
		auto itll = ll.begin();
		std::advance(itll,3);
		std::cout << "3. eleman: " << *itll << std::endl;
		printAll(ll);

		auto itll2 = ll.begin(); // index 0
		ll.insert(itll2,44);
		ll.erase(ll.begin());
		printAll(ll);

		auto it1 = ll.begin();
		std::advance(it1,2); // index 2
		ll.erase(itll2,it1); // 0 ve 2 arasýný silecek
		printAll(ll);
		ll.pop_front();
		ll.pop_back();

		ll.assign({ 85,47,14,41,417 });
		ll.sort();
		ll.reverse();
		ll.unique(); // ayný deðerden birden fazla olanlarý siler ve bir tane býrakýr.
		ekranayaz << "unique: "; printAll(ll);
		ll.remove(41); // bu index deðil deðer. verilen tüm deðerden kaç tane varsa hepsini siler.
		ll.remove_if(ciftmi); // koþullu silme. parametre türü fonksiyondur.

		std::list<int> list1 = { 5,9,0,1,3,3,3 }; list1.sort();
		std::list<int> list2 = { 8,7,2,6,4,4,4 }; list2.sort();
		list1.merge(list2); // sýralý olmak zorunda
		list1.unique(); // ayný elemanlarý sildi.

		ekranayaz << "ll: "; printAll(ll);
		ekranayaz << "list1: "; printAll(list1);
	};
	auto forwardListTanýmý = [ciftmi]() {
		fonksiyonuyaz("forwardListTanýmý");
		// bu listede geri diye birþey yok.
		std::forward_list<int> fl1;
		fl1.assign({5,2,14,5,5,5,59,8563});
		fl1.push_front(0);
		fl1.pop_front();
		ekranayaz << "front: " << fl1.front() << std::endl;
		auto itfl = fl1.begin();
		itfl = fl1.insert_after(itfl ,5); // iþlemden sonra iteratör 5 olarak deðiþir.
		itfl = fl1.erase_after(fl1.begin()); // ilk eleman silinir ve iteratör 1 artar.
		fl1.emplace_front(6); // ilk yere 6 yerleþtirdi.
		fl1.remove(5); // 5 deðerini sil.
		fl1.remove_if(ciftmi);

		std::forward_list<int> fl2;
		fl2.assign({ 9,8,7,6,6 });
		fl2.unique(); // ayný olanlarý sil.
		fl2.sort(); // sýrala
		fl2.reverse(); // tersine çevir.

		ekranayaz << "before merge: "; printAll(fl1);
		fl1.sort();
		fl2.sort();
		fl1.merge(fl2); // sýralý olmak zorunda ikisini birleþtir.
		ekranayaz << "after merge: "; printAll(fl1);
		
		printAll(fl1);
		printAll(fl2);

		fl1.clear(); // ne varsa sil

	};
	dequeTanýmý();
	listTanýmý();
	forwardListTanýmý();
}

ia Associative(){
	/*
	<h1> Associative(iliþkisel) Saykalayýcýlar(Containers), Saykalayý(Container) arazyüzleri, enums </h1>

	* Associative Containers: 
		set, multiset, map, multimap
	* Container Adapters:
		stack, queue, priority_queue
	*/

	setTanýmý();
	multisetTanýmý();
	mapTanýmý();
	multimapTanýmý();
	stackTanýmý();
	queueTanýmý();
	priorityQueue();
	enums();
}

ia regularExpressions() {
	/*
	<h1> regular expressions: arama, çýkan sonuçlarý birleþtirme, iteratörler ve diðerleri </h1>
	
	* regular expressions yani kýsa adýyla regex perl programlama diliyle beraber hayatýmýza iyice girdi.
	string iþlemek üzere kullanýlan ufak bir programlama dili davranýyor.
	temel iþlevi: string üzerinde arama ve eþlþtirmedir.(hemde çok iyi)
	iþletim sistemlerinde dosyalar arasýnda gezinmeyi kolaþlaþtýrýr.
	çok kýsa ifadelerle uzun uzun yazýlacak programlarýn iþlevlerini yerine getirebilir.
	bazen yavaþ olabilir ama öðrenenen piþman olmuyor :)

	* regex debug derlemede çalýþmýyor. bu büyük bir sorun biliyorum ama yapabileceðim birþey yok.
	https://docs.microsoft.com/tr-tr/cpp/error-messages/tool-errors/linker-tools-error-lnk2038
	*/
	
	regex1();



}

// ceia customHeaders.h içinde constexpr olarak belirlenmiþtir. Sonra üzerinde duracaðým.
ceia temelDerslerMain(int argc, char** argv) {
	constexpr auto hangibölüm = 1; // sonradan global tanýmla
	switch (hangibölüm) // yeni programlama dillerinde match durumu daha iyi ama þimdilik elimizde bu var. match test aþamasýnda...
	{
	case 1: ilkadim(argc, argv); break;
	case 2: temelVeriyapýlarý(); break;
	case 3: stringÝþlemleri();  break;
	case 4: kararÝþlemleri();  break;
	case 5: diziÝþlemleri(); break;
	case 6: vectorÝþlemleri();  break;
	case 7: pointlerFonksiyonlar();  break;
	case 8: özeldurumlarVEDöngüler();  break;
	case 9: stringMath();  break;
	case 10: Alistirmalar();  break;
	case 11: yinelemeliVEasýrýYüklemeli();  break;
	case 12: lambdaDerinlemesine();  break;
	case 13: oops(); break;
	case 14: overloadFileIO();  break;
	case 15: ileriFonksiyonlar();  break;
	case 16: templateVeItarator();  break;
	case 17: SmartPointers_PolymorphicTemplates(); break;
	case 18: threadVeZamanlama(); break;
	case 19: sequenceContainer();  break;
	case 20: Associative(); break;
	case 21: regularExpressions();  break;
	default: break;
	}


}
	/*
		* Tebrikler Temel Modern c++ bitmiþtir. Yeni Ýhtiyaç olan birþey olursa ekleyerek devam ederim.
		
		* Daha ayrýntýlý bilgi için https://en.cppreference.com/w/cpp/language sitesine baþvurabilirsiniz.
		* c++ dilinde çok sayýda farklý derleyici ve kütüphane bulunuyor ve hepsini indirip kulanamýyorsanýz
		https://godbolt.org/ sayfasý kodlarýnýzý assembly kodlarýna dönüþtürecektir.
		* Farklý veri yapýlarýný karþýlaþtýrmak için http://quick-bench.com sitesini kullanabilirsiniz.
		* Bir ara derleyici, linker, assembler, LLVM, çok kullanýlan ve populerleþen derleyicileri tanýtacaðým.
		* Sonraki dersler c++QT5/QML ve c++Opencv diye gidecektir. Qt5/QML ingilizce de bile
		kaynak az olduðundan ingilizce anlatabilirim.
		* Qt5 tam olarak c++ stl veri yapýlarýyla uygun deðildir. Qt5 temel bilgisini http://zetcode.com/gui/qt5/
		sitesinden anlatacaðým.
		* Qml için ilk tanýmda http://zetcode.com/gui/qtquick/ sitesinden yararlanacaðým.
		Sonra https://qmlbook.github.io/ yararlanacaðým. Qml ile guilerin tasarlanma ve çalýþma hýzlarýna þaþýracaksýnýz.


		*** Beni takip etmeye devam edin :) ***
	*/

#endif  // HEADER_FILE