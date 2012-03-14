#ifndef   __IPLUGIN_MANAGER_HH__
# define  __IPLUGIN_MANAGER_HH__

///
/// \file IPluginManager.hh
///

# include <string>
# include <list>

///
/// \namespace okapi
///

namespace okapi
{
  class Plugin;

  ///
  /// \class IPluginManager
  ///

  class IPluginManager
  {
  public:

    ///
    /// \enum Hook
    ///

    enum Hook
    {
      /// When the plugin is loaded
      ON_LOAD,
      /// When the server is started
      ON_SERVER_START,
      /// When a connection arrives
      ON_CONNECTION,
      /// When data is read from a specific protocol
      ON_DATA_READ_PROTOCOL,
      /// When a request is completed
      ON_REQUEST,
      /// When the body is created
      ON_BODY_CREATION,
      /// Editing the header of the response
      HEADER_MODIFIER,
      /// Editing the body of the response
      BODY_MODIFIER,
      /// When the response is ready to be sent
      ON_RESPONSE_READY,
      /// When data is about to be written to a specific protocol
      ON_DATA_WRITE_PROTOCOL,
      /// When the response has been sent
      ON_RESPONSE_SENT,
      /// When the server stops
      ON_SERVER_STOP,
      /// When the plugin is unloaded
      ON_UNLOAD
    };

    typedef std::list<Plugin *> PluginsList;

    ///
    /// \fn virtual bool registerPlugin(Plugin const &plugin, std::string const &identifier)
    /// \brief Register a loaded plugin
    /// \param plugin The plugin to be registered
    /// \param identifier The unique identifier of this plugin
    /// \return true or false according on the success of the registering
    ///

    virtual bool registerPlugin(Plugin const &plugin, std::string const &identifier) = 0;

    ///
    /// \fn virtual bool unregisterPluginByIdentifier(std::string const &identifier)
    /// \brief Unregister a plugin by its identifier
    /// \param identfier The unique identifier of the plugin to be unregistered
    /// \return true or falce according on the success of the unregistering

    virtual bool unregisterPluginByIdentifier(std::string const &identifier) = 0;

    ///
    /// \fn virtual Plugin *getPluginByIdentifier(std::string const &identifier)
    /// \brief Get a plugin by its identifier
    /// \param identifier The unique identifier of the plugin we want to get
    /// \return A pointer to the plugin object or NULL if no such plugin is registered

    virtual Plugin *getPluginByIdentifier(std::string const &identifier) = 0;

    ///
    /// \fn virtual PluginsList & getPluginsList(void) = 0;
    /// \brief Get all the plugins as a list
    /// \return The list of registered plugins
    ///

    virtual PluginsList & getPluginsList(void) = 0;
  };

}

#endif    /* __PLUGIN_MANAGER_HH__ */
