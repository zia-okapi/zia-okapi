#ifndef   __ICONNECTION_HH__
# define  __ICONNECTION_HH__

///
/// \file IConnection.hh
///

# include <string>

///
/// \namespace okapi
///

namespace okapi
{

  ///
  /// \class IConnection
  ///

  class IConnection
  {
  public:

    ///
    /// \enum Status
    ///

    enum Status
    {
      ALLOW, DISALLOW
    };

    ///
    /// \fn virtual void setIp(std::string const &ip) = 0;
    /// \brief Sets the ip of the incoming connection
    /// \param ip The ip of the incoming connection
    ///

    virtual void setIp(std::string const &ip) = 0;

    ///
    /// \fn virtual void std::string const &getIp(void) const = 0;
    /// \brief Gets the ip of the connection
    /// \return The ip of the connection
    ///

    virtual std::string const &getIp(void) const = 0;

    ///
    /// \fn virtual void setPort(unsigned short port) = 0;
    /// \brief Sets the port the remote client is connecting to
    /// \param port The port the remote client is connecting to
    ///

    virtual void setPort(unsigned short port) = 0;

    ///
    /// \fn virtual short getPort(void) const = 0;
    /// \brief Gets the port the remote client is connected to
    /// \return The port the remote client is connected to
    ///

    virtual unsigned short getPort(void) const = 0;
  };

}

#endif    /* __ICONNECTION_HH__ */
