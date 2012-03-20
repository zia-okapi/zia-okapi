#ifndef   __PLUGIN_HH__
# define  __PLUGIN_HH__

///
/// \file Plugin.hh
///

# include <string>
# include <vector>

# include "IPluginManager.hh"
# include "IConnection.hh"
# include "http/Request.hh"
# include "http/Response.hh"

///
/// \namespace okapi
///

namespace okapi
{

  ///
  /// \class Plugin
  /// \brief This is the class every plugin MUST inherit from, please note that you have to
  /// create your own extended class since this class has pure virtual methods
  ///
  /// Your plugin class MUST have a "new_plugin" function that returns a pointer to the plugin ( See Dummy.cpp )
  ///

  class Plugin
  {
  public:

    ///
    /// \fn Plugin(IPluginManager &)
    /// \brief Constructor
    /// \param pluginManager The plugin manager of the zia
    ///

    Plugin(IPluginManager & /* pluginManager */) {}
    virtual ~Plugin(void) {}

    ///
    /// \fn virtual bool registerHook(IPluginManager::hooks::Hook hook) = 0;
    /// \brief Used to indicate that a particular hook is registered
    /// \param hook The hook that is registered
    ///

    virtual void registerHook(IPluginManager::Hook hook) = 0;

    ///
    /// \fn virtual bool hasHook(IPluginManager::hooks::Hook hook) = 0;
    /// \brief Used to check if a plugin is registered on a particular hook
    /// \param hook The hook that we want to check if it is registered
    ///

    virtual bool hasHook(IPluginManager::Hook hook) = 0;

    ///
    /// \fn virtual bool canHandle(std::string const& protocol)
    /// \brief return true if the plugin can handle a specific protocol like HTTPS (or IRC ... )
    /// \param protocol the protocol acronym
    /// \return true only if the plugin can handle the protocol
    ///

    virtual bool canHandle(std::string const & /* protocol */) { return (false); }

    ///////////////////////////
    //         Hooks         //
    ///////////////////////////

    ///
    /// \fn virtual void onLoad(void)
    /// \brief This hook is called each time the plugin is loaded
    ///

    virtual void onLoad(void) {}

    ///
    /// \fn virtual void onServerStart(void)
    /// \brief This hook is called when the server is started
    ///

    virtual void onServerStart(void) {}

    ///
    /// \fn virtual api::IConnection::Status onConnection(api::IConnection &)
    /// \brief This hook is called when an incoming connection is received
    /// \param connection The incoming connection
    /// \return The status of the connection, this allows the plugin to accept or deny the connection
    ///

    virtual IConnection::Status onConnection(IConnection const & /* connection */) { return IConnection::ALLOW; }

    ///
    /// \fn virtual void onDataRead(std::string const &, std::vector<char> &)
    /// \param connection The connection object so we know where this data come from
    /// \param protocol The name of the protocol that is being handled or 'none'
    /// \param data The raw data that has been received on the socket, modify it as you wish
    ///

    virtual void onDataRead(IConnection const & /* connection */, std::string const & /* protocol */, std::vector<char> & /* data */) {}

    ///
    /// \fn virtual void onRequest(http::Request const &)
    /// \brief This hook is called just after a request is received by the zia server
    /// \param request The http request object that has been received
    /// \return The status of the request being generated, this allows to continue or abort the request
    ///

    virtual http::Request::Status onRequest(http::Request const & /* request */) { return http::Request::CONTINUE; }

    ///
    /// virtual void onBodyCreation(http::Body &)
    /// \brief This hook is called when the body is about to be generated
    /// \param body The body that is to be generated
    /// \param header The header of this request
    /// \return The status of the request being generated, this allows to continue or abort the request
    ///

    virtual http::Request::Status onBodyCreation(http::Body & /* body */, http::Header & /* header */) { return http::Request::CONTINUE; }

    ///
    /// \fn virtual void headerModifier(http::Header &)
    /// \brief This hook is called during the generation of the header when sending a response to the client
    /// \param header The header object that is being generated
    /// \return The status of the request being generated, this allows to continue or abort the request
    ///

    virtual http::Request::Status headerModifier(http::Header & /* header */) { return http::Request::CONTINUE; }

    ///
    /// \fn virtual void bodyModifier(http::Body &)
    /// \brief This hook is called during the generation of the body when sending a response to the client
    /// \param body The body object that is being generated
    /// \return The status of the request being generated, this allows to continue or abort the request
    ///

    virtual http::Request::Status bodyModifier(http::Body & /* body */) { return http::Request::CONTINUE; }

    ///
    /// \fn virtual void onResponseReady(http:Response &)
    /// \brief This hook is called when a response is ready to be sent
    /// \param response The http response object to be treated
    ///

    virtual void onResponseReady(http::Response & /* response */) {}

    ///
    /// \fn virtual void onDataWrite(std::string const &, std::vector<char> &)
    /// \param connection The connection object so we know where this data is to be sent
    /// \param protocol The name of the protocol that is being handled or 'none'
    /// \param data The raw data that is going to be sent, modify it as you wish
    ///

    virtual void onDataWrite(IConnection const & /* connection */, std::string const & /* protocol */, std::vector<char> & /* data */) {}

    ///
    /// virtual void onResponseSent(http::Response const &)
    /// \brief This hook is called right after a response is sent by the server to a client
    /// \param response The http reponse object that has been sent
    ///

    virtual void onResponseSent(http::Response const & /* response */) {}

    ///
    /// \fn virtual void onServerStop(void)
    /// \brief This hook is called just before the server stops
    ///

    virtual void onServerStop(void) {}

    ///
    /// \fn virtual void onUnload(void)
    /// \brief This hook is called just before the plugin is unloaded
    ///

    virtual void onUnload(void) {}

  };
}

#endif    /* __PLUGIN_HH__ */
