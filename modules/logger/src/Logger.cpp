#include "Logger.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

//static instance başlatma
Logger* Logger::instance = 0;

//constructor
Logger::Logger() {
	dosyaAdi = "log.txt";

	//LLR-LOG-01 .log veya .txt uzantılı dosya oluşturma
	//std::ios::app ve out (append ve yazma modları) ile dosya ekleme modunda açılır
	// ve kayıtlar silinmez
	logDosya.open(dosyaAdi.c_str(), std::ios::out | std::ios::app);

	if (logDosya.is_open()) {
		log(BILGI, "Log dosyasi baslatildi...");
	} else {
		std::cerr << "Hata: Log dosyasi acilamadi" << std::endl;
	}
}

Logger* Logger::getInstance() {
	//LLR-LOG-02 için instance yoksa oluştur varsa döndür
	if (instance == 0) {
		instance = new Logger();
	}
	return instance;
}

void Logger::log(Level level, const std::string &message) {
	if (logDosya.is_open()) {
		//zaman damgası oluşturulacak
		time_t simdi = time(0);
		//saniye vb okunabilir string e dönüştürülecek
		//örn: "Sun Dec 14 18:00:00 2025\n"
		char* zam = ctime(&simdi);

		//ctime sonunda \n olacak yazım için o düzeltiliyor
		if (zam && std::strlen(zam) > 0) {
			if (zam[std::strlen(zam) - 1] == '\n') {
			    zam[std::strlen(zam) - 1] = '\0';
			}
		}

		std::string levelEtiketi;
		switch (level) {
			case BILGI: levelEtiketi = "[BILGI]"; break;
			case UYARI: levelEtiketi = "[UYARI]"; break;
			case HATA: levelEtiketi = "[HATA]"; break;
			default:    levelEtiketi = "[BILINMIYOR]"; break;
		}

		logDosya << "[" << zam << "] " << levelEtiketi << message << std::endl;
		//bufferdaki veriyi direk hedefe yazar
		logDosya.flush();
	}
}

void Logger::bilgi(const std::string &mesaj) {
	log(BILGI, mesaj);
}

void Logger::uyari(const std::string &mesaj) {
	log(UYARI, mesaj);
}

void Logger::hata(const std::string &mesaj) {
	log(HATA, mesaj);
}


void Logger::logKapa() {
	if (logDosya.is_open()) {
		log(BILGI, "Log dosyasi kapatiliyor");
		logDosya.close();
	}
}
