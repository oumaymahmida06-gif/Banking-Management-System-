#include "TodaysDate.h"
#include <ctime>
#include <iomanip>
#include <sstream>

string GetTodayDate() {
    time_t now = time(nullptr);
    tm tm_info;

#ifdef _WIN32
    localtime_s(&tm_info, &now);
#else
    localtime_r(&now, &tm_info); 
#endif

    int day = tm_info.tm_mday;
    int month = 1 + tm_info.tm_mon;
    int year = 1900 + tm_info.tm_year;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << day << "-"
        << std::setw(2) << month << "-" << year;
    return oss.str();
}
