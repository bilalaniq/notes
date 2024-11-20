//--------------------------------------loging class ----------------------------------
/*
In C++, a "log class" typically refers to a class that is
designed to handle logging functionality within a software application. Logging is the process of
recording events, messages, or information during the execution of a program. Log
messages can include debugging information, warnings, errors, status updates, and more.
*/

#include <iostream>
class Log
{
public:
    enum level
    {
        level_error = 0,
        level_warning = 1,
        level_info = 2
    };

private:
    level m_loglevel = level_info;

public:
    void setlevel(level level)
    {
        m_loglevel = level;
    }

    void warn(const char *message)
    {
        if (m_loglevel >= level_warning)
            std::cout << "[WARNING]\t" << message << std::endl;
    }

    void error(const char *message)
    {
        if (m_loglevel >= level_error)
            std::cout << "[error]\t" << message << std::endl;
    }

    void info(const char *message)
    {
        if (m_loglevel >= level_info)
            std::cout << "[info]\t" << message << std::endl;
    }
};

int main()
{
    Log log;
    log.setlevel(Log::level_error);
    log.warn("warning");
    log.info("****");
    log.error("?");

    return 0;
}