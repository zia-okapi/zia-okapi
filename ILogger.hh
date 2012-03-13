#ifndef   __ILOGGER_HH__
# define  __ILOGGER_HH__

///
/// \file ILogger.hh
///

# include <string>

///
/// \namespace okapi
///

namespace okapi
{

  ///
  /// \class ILogger
  ///

  class ILogger
  {
  public:

    ///
    /// \enum LogLevel
    ///

    enum LogLevel
    {
      /// Log level used for debug informations
      DEBUG,
      /// Log level used for verbose informations
      VERBOSE,
      /// Log level used for fatal errors
      FATAL,
      /// Log level usef for warnings
      WARNING
    };

    ILogger(void);

    ///
    /// \fn virtual log(LogLevel level, std::string message) = 0;
    /// \brief Logs a message with a precise log level
    /// \param level The log level of the message
    /// \param message The message to be logged
    ///

    virtual void log(LogLevel level, std::string message) = 0;

    ///
    /// \fn virtual ILogger & operator<<(LogLevel level) = 0;
    /// \brief Sets the current loglevel for future operations
    /// \param level The loglevel
    /// \return A reference on the instance
    ///

    virtual ILogger & operator<<(LogLevel level) = 0;

    ///
    /// \fn virtual ILogger & operator<<(std::string message) = 0;
    /// \brief Logs a message with the current log level
    /// \param message The message
    /// \return A reference on the instance
    ///

    virtual ILogger & operator<<(std::string message) = 0;

  };
}

#endif    /* __ILOGGER_HH__ */
