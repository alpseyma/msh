#ifndef DISPLAY_MANUAL_COMMAND_H
#define DISPLAY_MANUAL_COMMAND_H

#include "Command.h"
#include "Logger.h"
#include <ios>
#include <iostream>
#include <limits>

class DisplayManualCommand : public Command {
public:
	void execute() {
		//LLR-LOG-03
		Logger::getInstance()->log(Logger::BILGI, "Kullanim kilavuzu acildi");

		std::cout << "\n==================================================" << std::endl;
        std::cout << "          MY SWEET HOME (MSH) - KULLANIM KILAVUZU       " << std::endl;
        std::cout << "==================================================" << std::endl;

        std::cout << "\n[GENEL KULLANIM]" << std::endl;
        std::cout << " * Menuden islem yapmak icin ilgili rakama (1-10) basin ve Enter'i tuslayin" << std::endl;
        std::cout << " * Yanlis bir tusa basarsaniz sistem uyari verecektir" << std::endl;

        std::cout << "\n[CIHAZ YONETIMI (Add/Remove/Power)]" << std::endl;
        std::cout << " * [2] Add Device: Sisteme yeni cihaz (Isik, Kamera, TV, Dedektor) ekler" << std::endl;
        std::cout << "   - Cihaz Tipi Secimi: (L)ight, (C)amera, (T)V, (D)etector" << std::endl;
        std::cout << "   - Coklu Ekleme: Ayni ayarlarla birden fazla cihaz ekleyebilirsiniz" << std::endl;
        std::cout << " * [3] Remove Device: Cihazlari ID numarasina gore kaldirir" << std::endl;
        std::cout << " * [4-5] Power On/Off: Cihazlari acip kapatir" << std::endl;
        std::cout << "   ! DIKKAT: Dedektorler ve Alarm 'Kritik Cihaz'dir, kapatilamaz!" << std::endl;

        std::cout << "\n[MODLAR VE DURUMLAR]" << std::endl;
        std::cout << " * [6] Change Mode: Evin atmosferini degistirir" << std::endl;
        std::cout << "   - Secenekler: (N)ormal, (E)vening, (P)arty, (C)inema" << std::endl;
        std::cout << " * [7] Change State: Sistemin enerji/performans durumunu degistirir" << std::endl;
        std::cout << "   - Secenekler: (N)ormal, (H)igh Performance, (L)ow Power, (S)leep" << std::endl;
        std::cout << "   - (P)revious: Bir onceki duruma geri doner" << std::endl;

        std::cout << "\n[GUVENLIK VE ALGILAMA]" << std::endl;
        std::cout << " * Sistem; duman, gaz veya hareket algiladiginda otomatik devreye girer" << std::endl;
        std::cout << " * Alarm caldiginda durdurmak icin ekrandaki yonergeleri izleyin" << std::endl;
        std::cout << " * Acil durumda sistem otomatik olarak Polis veya Itfaiyeyi arar" << std::endl;

	//LLR-MEN-04 de denilen bir tuşa basılmasını bekleme
        std::cout << "==================================================" << std::endl;
        std::cout << "Ana menuye donmek icin Enter'a basin..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get(); //bekleme
	}
};

#endif
