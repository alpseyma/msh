#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "Command.h"

class Menu {
private:
	//Command sınıfında türediği ve polymorphism kullanıldığı için
	//pointer ile farklı sınıflardan türeyen nesnelerin yerine
	//Command* konulacak
	//dynamic array kullanıyoruz denebilir
	//pointer olmasa hem abstract olduğu için sınıfı oluşturulamaz
	//hemde alt sınıfın özelliği kaybolurdu
	std::vector<Command*> commands;

public:
	Menu();
	~Menu();

	//menüye yeni komut eklemek için fonksiyon
	//daha dinamiklik sağlıyor
	void komutEkle(Command* cmd);

	//seçenekler ekrana yazdırılır
	//LLR-MEN-01 VE REQ1 sağlanmış olur
	void goruntuleme() const;

	//REQ3 de istenen kullanıcıdan menü seçimi isteği buradan yapılır
	//direk program çağrıya göre komutu çalıştırır
	void secim();

	//programın sürekli acik kalmasını sağlayan while(true) döngüsü gibidir
	//LLR-MEN-07 yi sağlar
	void akis();
};

#endif
