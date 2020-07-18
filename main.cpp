#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "");

	double seconds;
	clock_t start, stop;

	start = clock();

	func();

	stop = clock();

	seconds = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Время: " << seconds << endl << endl;

	system("pause");
	return 0;
}