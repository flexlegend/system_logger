#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "singleton_class.cpp"
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	bool flag = true;
	int a;
	time_t now = time(0);

	char* dt = ctime(&now);

	cout << "Вы запустили программу в: " << dt << endl;
	Logger::getInstance()->start(dt);
	while (flag)
	{
		cout << "Выберите действие: \n1 - Внести изменения\n2 - Завершить программу\n3 - Посмотреть текущий лог\n";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			int sw;
			cout << "Выберите изменение: \n1 - Изменить данные\n2 - Изменить настройки\n3 - изменить котировки";
			cin >> sw;
			if (sw == 1)
			{
				time_t now = time(0);
				Logger::getInstance()->change(ctime(&now), "Изменены данные");
			}				
			else if(sw == 2)
			{
				time_t now = time(0);
				Logger::getInstance()->change(ctime(&now), "Изменены настройки");
			}
			else if (sw == 3)
			{
				time_t now = time(0);
				Logger::getInstance()->change(ctime(&now), "Изменены котировки");
			}				
			break;
		}
		case 2:
			Logger::getInstance()->finish(ctime(&now));
			flag = false;
			break;
		case 3:
			cout << "\n\n";
			Logger::getInstance()->read();
			cout << "\n***********************************************\nТак же все логи можно посмотреть в файле log.txt\n***********************************************\n";
			break;
		default:
			break;
		}
	}
	cout << "\n\n\nЛог проделанной работы:\n";
	Logger::getInstance()->read();
	cout << "\n***********************************************\nТак же все логи можно посмотреть в файле log.txt\n***********************************************\n";
	return 0;
	

}