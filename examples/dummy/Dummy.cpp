
#include <iostream>
#include "Dummy.hh"

namespace okapi
{

  namespace plugins
  {

    DummyPlugin::DummyPlugin(okapi::IPluginManager &pluginManager) : Plugin(pluginManager)
    {
      // Register the plugin into the manager
      pluginManager.registerPlugin(*this, "dummy");
      this->registerHook(okapi::IPluginManager::ON_REQUEST);
    }

    DummyPlugin::~DummyPlugin(void)
    {
    }

    void DummyPlugin::onRequest(http::Request &request)
    {
      std::cout << "Watch out, we got a request over here!" << std::endl;
    }

  }

}

extern "C"
{
  okapi::Plugin *new_plugin(okapi::IPluginManager &pluginManager)
  {
    return (new okapi::plugins::DummyPlugin(pluginManager));
  }
}
