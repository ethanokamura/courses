#ifndef LOGGER_H
#define LOGGER_H

/**
 * @file logger.h
 * @brief declaring the member functions and variables for
 *        the path finder class
 */

#include <iostream>
class Logger {
 public:
  // Default constructor
  Logger();
  // Value constructor
  Logger(bool);
  // Default destructor (not needed)
  // ~Logger();
  // Log success
  void success(std::ostream&, const std::string&) const;
  // Log error
  void error(std::ostream&, const std::string&) const;
  // Log info
  void info(std::ostream&, const std::string&) const;
  /// @brief Public setter to enable info logging
  /// @param bool Determines if a log should be shown
  void showLogs(bool);

 private:
  bool _showLogs;
  void formatMessage(std::ostream&, const char*, const std::string&) const;
};

#endif  // LOGGER_H
