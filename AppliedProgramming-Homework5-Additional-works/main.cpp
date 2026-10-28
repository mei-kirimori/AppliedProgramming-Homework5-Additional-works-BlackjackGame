#include "CardGame.h"

int main()
{
	int null;
	srand(static_cast<unsigned int>(time(0)));
	for (int i=0;i<10;++i)
	{
		cout << "==============================" << endl;
		cout << "Game " << i + 1 << endl;
		gamedirector();
	}
	
	cin >> null;
}

