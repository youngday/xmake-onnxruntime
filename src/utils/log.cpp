#include "log.hpp"
#include <fstream>

using std::cout, std::endl, std::string;
void quill_init();

void quill_init() {

  auto time_str = mylocal_time();

  std::filesystem::create_directory("./log_quill/");
  string filename = "log_quill/quill-" + time_str + ".log";

  // Start the logging backend thread
  quill::start();

  // Create a rotating file handler which rotates daily at 18:30 or when the
  // file size reaches 2GB
  std::shared_ptr<quill::Handler> file_handler =
      quill::rotating_file_handler(filename, []() {
        quill::RotatingFileHandlerConfig cfg;
        cfg.set_rotation_time_daily("18:30");
        cfg.set_rotation_max_file_size(2'000'000'000);
        return cfg;
      }());
  // Everything is logged in the file
  file_handler->set_log_level(quill::LogLevel::Info);

  // Get the stdout file handler
  std::shared_ptr<quill::Handler> stdout_handler = quill::stdout_handler();
  // Set a custom formatter for this handler
  stdout_handler->set_pattern("%(ascii_time) [%(process)] [%(thread)] "
                              "%(logger_name) %(fileline:<28) - %(message)", // format
                              "%Y-%m-%d %H:%M:%S.%Qms",      // timestamp format
                              quill::Timezone::GmtTime); // timestamp's timezone
  // Enable console colours on the handler
  static_cast<quill::ConsoleHandler *>(stdout_handler.get())
      ->enable_console_colours();

  stdout_handler->set_log_level(quill::LogLevel::Info);

  // Create a logger using this handler
  logger = quill::create_logger("logger", {file_handler, stdout_handler});

  // Change the LogLevel to print everything
  logger->set_log_level(quill::LogLevel::Debug);

  // log everything up to this point before changing the handler log level
  quill::flush();

  // Log to both handlers
  // LOG_TRACE_L3(logger, "This is a log trace l3 example {}", 1);
  // LOG_TRACE_L2(logger, "This is a log trace l2 example {} {}", 2, 2.3);
  // LOG_TRACE_L1(logger, "This is a log trace l1 example {}", 3);
  LOG_DEBUG(logger, "This is a log debug example {}", 4);
  LOG_INFO(logger, "This is a log info example {}", 5);
  LOG_WARNING(logger, "This is a log warning example {}", 9);
  // LOG_ERROR(logger, "This is a log error example {}", 10);
  // LOG_CRITICAL(logger, "This is a log critical example {}", 11);
}
