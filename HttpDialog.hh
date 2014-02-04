#ifndef     _HTTPDIALOG_HH_
# define    _HTTPDIALOG_HH_

///
/// \file HttpDialog.hh
///

# include   "IPluginManager.hh"
# include   "IConnection.hh"
# include   "http/Request.hh"
# include   "http/Response.hh"

///
/// \namespace okapi
///

namespace okapi
{

  ///
  /// \class HttpDialog
  ///

  class HttpDialog
  {

  public:

    ///
    /// \fn HttpDialog(IPluginManager & pluginManager)
    /// \brief Constructor
    /// \param pluginManager The plugin manager from the server
    /// \param connection The connection that the object will encapsulate.
    ///

    HttpDialog(IPluginManager & pluginManager, IConnection const & connection);
    ~HttpDialog(void);

    ///
    /// \fn bool process(void);
    /// \brief The main function of the class, used to continue the communication process
    ///

    void    process(void);

    ///
    /// \fn http::Request *getRequest(void);
    /// \brief Gets a pointer to the current request of this dialog
    /// \return A pointer to the current request of this dialog
    ///

    http::Request *getRequest(void);

    ///
    /// \fn void setRequest(http::Request *request);
    /// \brief Sets the current request of this dialog
    /// \param request The request to be set
    ///

    void setRequest(http::Request *request);

    ///
    /// \fn http::Request *getResponse(void);
    /// \brief Gets a pointer to the current response of this dialog
    /// \return A pointer to the current response of this dialog
    ///

    http::Response *getResponse(void);

    ///
    /// \fn void setResponse(http::Request *request);
    /// \brief Sets the current response of this dialog
    /// \param response The response to be set
    ///

    void setResponse(http::Response *response);

  private:
    IPluginManager &_pluginManager;
    IConnection _connection;
    htpp::Request * _request;
    http::Response * _response;

  };

}

#endif      // !_HTTPDIALOG_HH_
