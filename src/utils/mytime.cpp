#include "mytime.hpp"
/**
 * Generate a UTC ISO8601-formatted timestamp
 * and return as std::string
 */
using namespace std;
int64_t get_gmtime_us();
int64_t get_localtime_us();

int64_t get_gmtime_ms();
int64_t get_localtime_ms();

int64_t get_gmtime_s();
int64_t get_localtime_s();

std::string gmtime2localstr(int64_t time_us, const std::string &);
int64_t localstr2gmtime(const std::string &s, const std::string &);
int64_t gmtime_2_time_us(const std::string &s, const std::string &);
/**
 * Generate a local time
 * and return as std::string
 */
std::string mylocal_time();
/**
 * Generate a UTC ISO8601-formatted timestamp
 * and return as std::string
 */
std::string gmt_time();

std::string gmt_time()
{
    auto tp_now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(tp_now);

    std::ostringstream ss;
    ss << std::put_time(gmtime(&time_t_now), "%FT%TZ"); // UTC format
    return ss.str();
}
/**
 * Generate a local time
 * and return as std::string
 */
std::string mylocal_time()
{
    auto tp_now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(tp_now);

    std::ostringstream ss;
    ss << std::put_time(localtime(&time_t_now), "%Y-%m-%d %H:%M:%S"); // local time
    return ss.str();
}
// get duration microseconds
int64_t get_gmtime_us()
{
    std::chrono::system_clock clock;
    return std::chrono::duration_cast<std::chrono::microseconds>(
               clock.now().time_since_epoch())
        .count();
}

int64_t get_localtime_us()
{
    return get_gmtime_us() + HOUR_US * 8;
}

// get duration milliseconds
int64_t get_gmtime_ms()
{
    chrono::system_clock clock;
    return chrono::duration_cast<chrono::milliseconds>(
               clock.now().time_since_epoch())
        .count();
}

int64_t get_localtime_ms()
{
    return get_gmtime_ms() + HOUR_MS * 8;
}

// get duration seconds
int64_t get_gmtime_s()
{
    chrono::system_clock clock;
    return chrono::duration_cast<chrono::seconds>(
               clock.now().time_since_epoch())
        .count();
}

int64_t get_localtime_s()
{
    return get_gmtime_s() + HOUR_S * 8;
}

string gmtime2localstr(int64_t time_us, const string &fmt = "%Y-%m-%d %H:%M:%S")
{
    stringstream ss;
    time_t t = time_us / SEC_US;
    auto tm = std::localtime(&t); // gmtime() for gmtime string.
    ss << std::put_time(tm, fmt.c_str());
    return ss.str();
}

int64_t localstr2gmtime(const std::string &s, const std::string &fmt = "%Y-%m-%d %H:%M:%S")
{
    stringstream ss;
    ss << s;
    struct tm tm;
    ss >> std::get_time(&tm, fmt.c_str());
    return (int64_t)mktime(&tm) * SEC_US;
}

int64_t gmtime_2_time_us(const std::string &s, const std::string &fmt = "%Y-%m-%d %H:%M:%S") // to test
{
    stringstream ss;
    ss << s;
    struct tm tm;
    ss >> std::get_time(&tm, fmt.c_str());
    return (int64_t)mktime(&tm) * SEC_US + HOUR_US * 8; // for beijing time UTC+8
}

//  int64_t ticker=123;//your milliseconds ticker counter
//   auto ms = std::chrono::milliseconds(ticker);

//   auto tp1 = std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>(ms);
//   auto tp2 = tp1 + std::chrono::hours(8); //time point before one hour UTC+8 beijing time
//   cout << "tp1=" << tp1.time_since_epoch().count() << endl
//        << "tp2=" << tp2.time_since_epoch().count() << endl;

//   auto itt = std::chrono::system_clock::to_time_t(tp2);

//   std::ostringstream ss;
//   ss << std::put_time(gmtime(&itt), "%Y-%m-%d %H:%M:%S");

//  // ss << std::put_time(localtime(&now), "%Y-%m-%d %H:%M:%S");
//   cout << "utc to local" << ss.str() << endl;