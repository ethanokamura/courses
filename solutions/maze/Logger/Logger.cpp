#include "Logger.h"

// Constants
constexpr char NEWLINE = '\n';
constexpr bool SHOW_TEST_LOGS = true;
// ANSI Color Codes
constexpr const char *RESET = "\x1B[0m";
constexpr const char *R = "\x1B[31m";
constexpr const char *G = "\x1B[32m";
constexpr const char *B = "\x1B[34m";

/// @brief Default constructor
Logger::Logger() : _showLogs(true) {}

/// @brief Value constructor
/// @param A boolean to determine if logs should be shown
Logger::Logger(bool showLogs) : _showLogs(showLogs) {}

/// @brief Formats the messages
/// @param out A reference to an output stream
/// @param color The ANSI color code.
/// @param message A reference to the message itself
void Logger::formatMessage(std::ostream &out, const char *color,
                           const std::string &message) const {
  out << color << message << RESET << NEWLINE;
}

/// @brief Informational logging
/// @param out A reference to an output stream
/// @param message A reference to the message that needs to be logged
void Logger::info(std::ostream &out, const std::string &message) const {
  if (_showLogs) formatMessage(out, B, message);
}

/// @brief Logs an error message
/// @param out A reference to an output stream
/// @param header The origin of the failure
void Logger::error(std::ostream &out, const std::string &header) const {
  out << header << ": ";
  formatMessage(out, R, "FAILURE");
}

/// @brief Logs a success message
/// @param out A reference to an output stream
/// @param header The origin of the success
void Logger::success(std::ostream &out, const std::string &header) const {
  out << header << ": ";
  formatMessage(out, G, "SUCCESS");
}

/// @brief Public setter to enable informational logging
/// @param show True if the info logs should be displayed
void Logger::showLogs(bool show) { _showLogs = show; }