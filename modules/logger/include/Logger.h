//Dosya yanlışlıkla birden fazla kez include edilmesin diye kullanılır
//define ile tanımlandıktan sonra endif kadar olan kısmı atlar
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

//LLR-LOG-02 e göre Logger Singleton kullanmalı
class Logger {
public:
	//log dosyasına seviyeler vereceğiz
	enum Level {
		BILGI,
		UYARI,
		HATA
	};

	//Singleton erişim metodu
	//nesne oluşturulmadan çağırmak için static seçildi
	static Logger* getInstance();

	//dışarıdan gelen veriyi alarak o anki saati ve tarihi hesaplayacak
	//LLR-LOG-03 de belirtilen zaman damgalı log mesajı
	//parametreleri seviye olarak alıyor
	void log(Level level, const std::string& mesaj);

	//leveller için fonksiyonlar
	//& ile referans geçip optimizasyon sağlayıp tekrar tekrar hafızaya 
	//kopyalamayacağız
	//const sebebi de sadece okunsun değişmesin diye
	void bilgi(const std::string& mesaj);
	void uyari(const std::string& mesaj);
	void hata(const std::string& mesaj);

	//dosyayı kapama için
	//LLR-LOG-04 de belirtilen dosyanın güvenli kapanması
	void logKapa();

private:
	//Singleton için constructor private yapılır
	Logger();

	//bu kısım Sngleton u bozmamak için eklendi
	//logger pointer ile kopyalanabileceği için sıkıntı olabilir
	
	//bu kısım L2(L1) gibi işlemleri yasaklar
	Logger(const Logger&);

	//bu kısım L2 = L1 yasaklar
	Logger& operator=(const Logger&);

	//tekil instance tutucu
	//static ile değişkenin üretilen değişkenden bağımszı sınıfa özgü olması
	//sağlanacak yani program boyu bir tane instance pointer olacak
	static Logger* instance; 
	
       	// Dosya yazma nesnesi REQ4 için lazım
	std::ofstream logDosya; 
	std::string dosyaAdi;
};

#endif
