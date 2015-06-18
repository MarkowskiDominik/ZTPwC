//ZTP11 Markowski

#include "Zwierz.h"
#include "Kot.h"
#include "Pies.h"

int main()
{
	Zwierz *zwierzeta[4];
	zwierzeta[0] = new Kot("Filemon");
	zwierzeta[1] = new Pies("Azor");
	zwierzeta[2] = new Kot("Murycy");
	zwierzeta[3] = new Pies();

	for (int i = 0; i < 4; i++)
	{
		std::cout << *zwierzeta[i] << std::endl;
		delete zwierzeta[i];
	}

	system("PAUSE");
	return 0;
}