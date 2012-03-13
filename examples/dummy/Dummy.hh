#ifndef   __DUMMY_HH__
# define  __DUMMY_HH__

# include "Plugin.hh"

namespace okapi
{

  namespace plugins
  {

    class DummyPlugin : public okapi::Plugin // This obviously won't compile since we need to extend a base plugin class
    {
    public:
      DummyPlugin(okapi::IPluginManager &pluginManager);
      ~DummyPlugin(void);

    protected:
      void onRequest(http::Request &request);
    };

  }

}

#endif    /* __DUMMY_HH__ */
