#include "ShowManualCommand.h"
#include <iostream>

void ShowManualCommand::execute() {
    std::cout << "\n=== MSH Kullanım Kılavuzu (Manual) ===\n";
    std::cout << "1-5 : Mod seçimi (HOME/AWAY/NIGHT/PARTY/CINEMA)\n";
    std::cout << "6   : Tüm cihazları aç\n";
    std::cout << "7   : Tüm cihazları kapat\n";
    std::cout << "8   : Güvenliği kur (Arm)\n";
    std::cout << "9   : Güvenliği çöz (Disarm)\n";
    std::cout << "10  : Güvenlik/Dedektör testi çalıştır\n";
    std::cout << "11  : Güvenlik durumunu göster\n";
    std::cout << "-1  : Çıkış\n";
    std::cout << "=====================================\n\n";
}
