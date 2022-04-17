#include <iostream>
#include <vector>
#include "Logger.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	auto instance = Logger::getInstance();
	instance->info("Программа запущена");
	cout << "Введите число (q для выхода)" << endl;
	vector<double> buffer;
	while (true) {
		string input;
		cin >> input;
		instance->info("Введено значение " + input);
		if (input == "q")
			break;
		try {
			double number = stod(input);
			buffer.push_back(number);
		}
		catch(const exception& e) {
			instance->error("Введены невалидные данные");
			cout << "Ошибочное значение, попробуйте ещё раз" << endl;
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
	instance->info("Среднее число: " + to_string(result) );
	cout << result << endl;
	instance->info("Программа закончила работу");
	return 0;
}