#ifndef SHUTDOWN_COMMAND_H
#define SHUTDOWN_COMMAND_H

#include "Command.h"
#include "Logger.h"
#include <cstdlib>
#include <iostream>

class ShutdownCommand : public Command {
public:
	void execute() {
		//LLR-LOG-04 a göre sistem kapanırken log kapatılmalı
		Logger::getInstance()->log(Logger::BILGI, "Sistem kapatiliyor");
		Logger::getInstance()->logKapa();

		std::cout << "Sistem kapatiliyor" << std::endl;
		exit(0); //programı sonlandır
	}
};

#endif
