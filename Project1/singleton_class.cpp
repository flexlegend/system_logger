#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Logger {
public:
    // �������-���� ��� ������� � ������������� ����������
    static Logger* getInstance() {
        static Logger instance;
        return &instance;
    }

 
    void start(string str) {
        ofstream out;
        out.open("log.txt");
        out << "��������� �������� � " << str;
        out.close();
    }
    void change(string time, string str) {
        ofstream out("log.txt", std::ios::app);
        out << str << ": " << time;
        out.close();
    }
    void finish(string time) {
        ofstream out("log.txt", std::ios::app);
        out << "��������� ������� � " << time;
        out.close();

    }
    void read() {
        ifstream in ("log.txt");
        string line;
        while (getline(in, line))
        {
           cout << line << std::endl;
        }
    }

private:
    // ��������� ����������� ��������, ����� ������ ����
    // ��������� ���������� ������ �����
    Logger() { }
};