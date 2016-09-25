#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	int n, random;
	
	srand(time(NULL));
	random = (rand() % 10)+1;
	cout << "\nAdivina el número que he generado aleatoriamente. Introduzca un número del 1 al 10: ";
	cin >> n;
	while ((n<1) || (n>10))
	{
		cout << "\nIntroduzca un número del 1 al 10, por favor: ";
		cin >> n;
	}
	while (random!=n)
	{
		if (random>n)
		{
			cout << "\nIntroduzca un número mayor: ";
		}
		else
		{
			cout << "\nIntroduzca un número menor: ";
		}
		cin >> n;
		while ((n<1) || (n>10))
		{
			cout << "\nIntroduzca un número del 1 al 10, por favor: ";
			cin >> n;
		}
	}
	cout << "\nEnhorabuena, has acertado el número. Era el " << n << ".\n\n";
	return (0);
}
