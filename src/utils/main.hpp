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

#include "co/all.h"
#include "mytime.hpp"
#include "nlohmann/json.hpp"
#include <yaml-cpp/yaml.h>
#include <CLI/CLI.hpp>


#define FMT_HEADER_ONLY//NOTE: need add 
#include <fmt/format.h>
#include <fmt/core.h>
#include <fmt/ranges.h>

#include "log.hpp"
inline quill::Logger *logger;

#endif // MAIN_HPP
