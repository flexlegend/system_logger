#include <iostream>
#include <vector>
#include "Logger.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	auto instance = Logger::getInstance();
	instance->info("��������� ��������");
	cout << "������� ����� (q ��� ������)" << endl;
	vector<double> buffer;
	while (true) {
		string input;
		cin >> input;
		instance->info("������� �������� " + input);
		if (input == "q")
			break;
		try {
			double number = stod(input);
			buffer.push_back(number);
		}
		catch(const exception& e) {
			instance->error("������� ���������� ������");
			cout << "��������� ��������, ���������� ��� ���" << endl;
		}
	}
	double sum = 0;
	for (const auto& number : buffer) {
		sum += number;
	}
	auto size = buffer.size();
	double result = 0;
	if (size != 0)
		result = sum / size;
	instance->info("������� �����: " + to_string(result) );
	cout << result << endl;
	instance->info("��������� ��������� ������");
	return 0;
}