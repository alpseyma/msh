#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
	//polymorphism kullanılırken bir alt sınıf nesnesi üzerinden silinirse
	//eğer destructor virtual değilse Command sınıfınınki çalışır
	//memory leak e neden olabilir onu önlüyoruz
	virtual ~Command() {}

	//pure virtual fonksiyon
	//alt sınıfların bunu oluşturmasına gerek kalmaz
	//REQ3 için bu kısım gereklidir
	//her tuşa atanmış fonksiyon için execute çağırılır
	virtual void execute() = 0;
};

#endif
