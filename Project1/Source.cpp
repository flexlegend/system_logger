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

	cout << "�� ��������� ��������� �: " << dt << endl;
	Logger::getInstance()->start(dt);
	while (flag)
	{
		cout << "�������� ��������: \n1 - ������ ���������\n2 - ��������� ���������\n3 - ���������� ������� ���\n";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			int sw;
			cout << "�������� ���������: \n1 - �������� ������\n2 - �������� ���������\n3 - �������� ���������";
			cin >> sw;
			if (sw == 1)
			{
				time_t now = time(0);
				Logger::getInstance()->change(ctime(&now), "�������� ������");
			}				
			else if(sw == 2)
			{
				time_t now = time(0);
				Logger::getInstance()->change(ctime(&now), "�������� ���������");
			}
			else if (sw == 3)
			{
				time_t now = time(0);
				Logger::getInstance()->change(ctime(&now), "�������� ���������");
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
			cout << "\n***********************************************\n��� �� ��� ���� ����� ���������� � ����� log.txt\n***********************************************\n";
			break;
		default:
			break;
		}
	}
	cout << "\n\n\n��� ����������� ������:\n";
	Logger::getInstance()->read();
	cout << "\n***********************************************\n��� �� ��� ���� ����� ���������� � ����� log.txt\n***********************************************\n";
	return 0;
	

}