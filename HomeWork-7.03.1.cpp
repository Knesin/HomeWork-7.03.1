#include <iostream>
#include <string>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogConsol : public LogCommand {
public:
    void print(const std::string& message) override{
        std::cout << message << std::endl;
    }
};

class LogFile : public LogCommand {
public:
    LogFile(std::string file):file_(file) {};
    void print(const std::string& message) override {
        std::ofstream f(file_, std::ios::app);
        f << message << std::endl;
        f.close();
    };
private:
    std::string file_;
};

void print(LogCommand& comand) {
    comand.print("message");
}

int main()
{
    std::string log_file = "log.txt";
    LogConsol lc;
    LogFile lf(log_file);
    print(lc);
    print(lf);
}