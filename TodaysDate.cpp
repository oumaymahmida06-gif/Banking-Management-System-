#include "TodaysDate.h"
#include <ctime>
#include <iomanip>
#include <sstream>

string GetTodayDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;

    stringstream ss;
    ss << setw(2) << setfill('0') << day << "-"
        << setw(2) << setfill('0') << month << "-"
        << year;

    return ss.str();
}
