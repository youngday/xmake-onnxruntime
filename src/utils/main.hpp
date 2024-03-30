#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <future>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include<chrono>

#include "atomic_queue/atomic_queue.h"
#include "co/all.h"
#include "mytime.hpp"
#include "nlohmann/json.hpp"
#include <yaml-cpp/yaml.h>

#define FMT_HEADER_ONLY//NOTE: need add 
#include <fmt/format.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

#include "log.hpp"
inline quill::Logger *logger;
struct YamlParam {
  std::string userName;
  std::string passWord;
  std::string serialNum;

  std::string pcLocalIP;
  std::string pcRemoteIP;
  std::string cppLocalIP;
  std::string cppRemoteIP;
  std::string javaLocalIP;
  std::string javaRemoteIP;
  std::string PLCIP;
  std::string PLCPort;
  std::string sendPLCPort;
  std::string rcvPLCPort;
};



#endif // MAIN_HPP
