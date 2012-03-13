#ifndef			_HTTPDIALOG_HH_
# define		_HTTPDIALOG_HH_

# include		"IPluginManager.hh"
# include		"IConnection.hh"
# include		"http/Request.hh"
# include		"http/Response.hh"

///
/// \namespace okapi
///

namespace okapi
{

  ///
  /// \class HttpDialog
  ///

  class			HttpDialog
  {

  public:

    ///
    /// \fn CommunicationPlugin(IPluginManager & pluginManager)
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

    void		process(void);

  private:
    IPluginManager &	_pluginManager;
    IConnection		_connection;
    htpp::Request *	_request;
    http::Response *	_response;

  };

}

#endif			// !_HTTPDIALOG_HH_
