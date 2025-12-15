#include "Menu.h"
#include "Logger.h"
#include <iostream>
#include <limits>

Menu::Menu() {
	Logger::getInstance()->log(Logger::BILGI, "Menu sistemi bastildi");
}

//menu yok ediliyor
Menu::~Menu() {
	for (size_t i = 0; i < commands.size(); i++) {
	delete commands[i];
	}
	commands.clear();
}

//dinamik array in sonuna komutu ekler
void Menu::komutEkle(Command *cmd) {
	commands.push_back(cmd);
}

void Menu::goruntuleme() const {
	std::cout << "\n MY SWEET HOME (MSH) \n" << std::endl;
	std::cout << "[1] Get Home Status (Show state and mode, information about sensors and actuators)" << std::endl;
	std::cout << "[2] Add Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V" << std::endl;
	std::cout << "[3] Remove Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V" << std::endl;
	std::cout << "[4] Power on Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V, (S)ound System" << std::endl;
	std::cout << "[5] Power off Device - (L)ight, Smoke & Gas (D)etectors, (C)amera, (T)V, (S)ound System" << std::endl;
	std::cout << "[6] Change Mode - (N)ormal, (E)vening, (P)arty, (C)inema" << std::endl;
	std::cout << "[7] Change State - (N)ormal, (H)igh Performance, (L)ow Power, (S)leep, (P)revious one" << std::endl;
	std::cout << "[8] Manual (Display manual)" << std::endl;
	std::cout << "[9] About (information about product and developers)" << std::endl;
	std::cout << "[10] Shutdown (shut down the system)" << std::endl;
	std::cout << "Secim: ";
}

void Menu::secim() {
	int sec;

	//burada tip hataları için hatalar ayıklanacak
	if (!(std::cin >> sec)) {
		//hata durumu temizlenene kadar input girisi engeller
		//bu fonksiyon onu temizler
		std::cin.clear();

		//limits kütüphanesi ile \n e kadar olan kısım bufferdan temizlenir
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Gecersiz giris! Lutfen menudeki sayilardan giriniz." << std::endl;
		Logger::getInstance()->log(Logger::HATA, "Hatali menu girisi(tip uyusmazliği)");
		return;
	}

	//liste 1 den indexleme 0 dan başladığı için hem döngü ile limit koyuyoruz
	//hemde -1 ile indexlemeyi düzeltiyoruz
	if (sec >= 1 && sec <= (int)commands.size()) {
		//LLR-MEN-06
		commands[sec - 1]->execute();
	} else {
	std::cout << "Gecersiz secim! Lutfen menudeki sayilardan giriniz." << std::endl;
	Logger::getInstance()->log(Logger::HATA, "Hatali menu girisi (gecersiz aralik)");	
	}
}

void Menu::akis() {
	bool akis = true;
	while (akis) {
		goruntuleme();
		secim();
	}
}
