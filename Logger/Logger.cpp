#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "date.h"

using namespace std;

class Logger {
public:
    /// <summary>
    /// ѕолучение экземпл€ра Singleton'а
    /// </summary>
    /// <returns>”казатель на экземпл€р логгера</returns>
    static Logger* getInstance() {
        static Logger instance;
        return &instance;
    }
    
    void info(const string& message) {
        writeMessage(message, _infoLevel);
    }

    void error(const string& error) {
        writeMessage(error, _errorLevel);
    }

private:

    string _fileName = "log.txt";

    string _infoLevel = "INFO";
    string _errorLevel = "ERROR";

    // ќбъ€вл€ем конструктор закрытым, чтобы нельз€ было
    // создавать экземпл€ры класса извне
    Logger() { }

    void writeMessage(const string& message, const string& logLevel) {
        using namespace date;
        auto time = chrono::system_clock::now();
        ofstream stream(_fileName, ios::app);
        stream << "[" << logLevel << "] " << time << ": " << message << endl;
        stream.close();
    }
};