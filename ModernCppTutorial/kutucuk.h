#pragma once
/*
<h1>Operator overload nedir ve nasýl yapýlýr? </h1>

* Operator denilen þey aslýnda bir fonksiyondur. Yeni bir operator tanýmlarken girdisi ve çýktýsý belli olan
fonksiyonlar tanýmlanýr. 
* c++ temel türler(int, float, double, char,...) türlerini kullanabilmek üzere hazýr operatorleri vardýr.
Eðerki yeni bir tür tanýmlarsak derleyici bu tür ile operatorleri eþleþtiremez. O zaman bu operatorleri
programcý tanýmlamalýdýr. Hemen hemen tüm programlama dillerinde özellikle oops destekli dillerde yapýlan
temel iþlemlerden biridir.
* Tüm operatorler aþýrý yüklenemez. https://en.cppreference.com/w/cpp/language/operators
* Matematiksel, mantýksal, karþýlaþtýrma I/O ve hafýzaya eriþim([],->,*(pointer dereferance)) ile ilgli operatorler aþýrý yüklenebilir.
* Aþýrý yükleme sorucunda operator çaðrýldýðýnda tanýmlanan operator fonksiyonu çalýþtýrýlýr ve sonuç alýnýr.

* operatorleri aþýrý þekilleri https://en.cppreference.com/w/cpp/language/operators içinde tanýmlýdýr.
* burada yapacaðým þeyler eðitim amaçlýdýr. Daha sonra ayrýntýlý anlatacaðm.
*/

class kutucuk
{
	// operator aþýrý yüklemesi yapmak üzere kullanýyorum.
private:
	double length, width, breadth;
	std::string name;
public:
	kutucuk() : length{ 1 }, width{ 1 }, breadth{ 0 }, name{ "" } {
	}
	kutucuk(double l, double w, double b) : length{ l }, width{ w }, breadth{ b } {
	}
	kutucuk(double l, double w, double b, std::string n) : length{ l }, width{ w }, breadth{ b }, name{ n } {
	}
	double getVolume(void) { // içindeki void parametre almayacaðýný belirtiyor.
		return length * breadth * width;
	}
	// C# set-get karþýlýðý
	void setLength(double len) {
		length = len;
	}
	double getLength() {
		return length;
	}
	void setBreadth(double bre) {
		breadth = bre;
	}
	double getBreadth() {
		return breadth;
	}
	void setWidth(double wi) {
		width = wi;
	}
	double getWidth() {
		return width;
	}
	
	// ++a operatörünü aþýrý yükleme
	kutucuk& operator ++() {
		// ++a operatörü önce arttýrma sonra atama yapar.
		++length; ++width; ++breadth; return *this;
	}
	// a++ operatörünü aþýrý yükleme
	kutucuk operator ++(int) {
		// a++ operatörü önce atama sonra arttýrma yapar.
		kutucuk temp(*this); //kopyala
		operator++(); // pre-increment(++a) // Bu operatör önceden tanýmlanmýþtý. Derleyici fonksiyonu tanýr.
		return temp; // eski deðeri gönder.
	}

	// c string göstericisi
	operator const char*() {
		std::ostringstream oss;
		oss << "kutucuk: " <<
			length << "," <<
			width << "," <<
			breadth;
		name= oss.str();
		return name.c_str();
	}

	kutucuk operator +(const kutucuk& kutu2) {
		/*
		kutucuk kutu1, kutu2;
		auto toplam=kutu1 + kutu2;
		buradaki iþlemde ilk parametre varsayýlan olarak kutu1 olduðundan ikinci parametreyi yazmaya ihtiyaç yok.
		*/
		kutucuk kutu;
		kutu.length = length + kutu2.length;
		kutu.width = width + kutu2.width;
		kutu.breadth = breadth + kutu2.breadth;
		return kutu;
	}
	double operator [](int sayý) { // kutu[sayý]. parametremiz sayý.
		return sayý == 0 ? length : sayý == 1 ? width : sayý == 2 ? breadth : 0;
	}
	bool operator == (const kutucuk& kutu2) {// toplam operatörüyle ayný kural geçerli
		return (length == kutu2.length) && (width == kutu2.width) && (breadth == kutu2.breadth);
	}
	bool operator < (const kutucuk& kutu2) {
		auto hacim1 = this->getVolume();
		auto hacim2 = kutu2.length*kutu2.width*kutu2.breadth;
		return hacim1 < hacim2; // true yada false diye kendisi artýk belirleyebilir.
	}
	bool operator > (const kutucuk& kutu2) {
		auto hacim1 = this->getVolume();
		auto hacim2 = kutu2.length*kutu2.width*kutu2.breadth;
		return hacim1 > hacim2; // true yada false diye kendisi artýk belirleyebilir.
	}
	void operator = (const kutucuk& copyKutu2) { // aslýnda hatalý. sonra üzerinde duracaðým.
		length = copyKutu2.length;
		width = copyKutu2.width;
		breadth = copyKutu2.breadth;
	}
	// "<<" operatorünü aþýrý yüklemediðim için parantez olmadan derlenmez. 



	~kutucuk()=default; // varsayýlan yýkýcýyý otomatik oluþturur.
};
