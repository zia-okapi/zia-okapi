# include "Plugin.hh"

namespace okapi
{
  namespace plugins
  {
    class BasicRewrite : public okapi::Plugin
    {
      BasicRewrite(okapi::IPluginManager &pluginManager) : okapi::Plugin(pluginManager)
      {
        pluginManager.registerPlugin(*this, "basic_rewrite");
        this->registerHook(okapi::IPluginManager::ON_REQUEST);
      }

      void onRequest(http::Request &request)
      {
        std::string ext = ".html";
        std::string &url = request.getUrl(); // Retrieve a reference to he url in the request

        std::string extension = url.substr(url.size() - ext.size());

        if (extension == ".html") // If the url ends in ".html"
        {
          std::string nUrl = url.substr(0, url.size() - ext.size());
          nUrl += ".php";
          url.assign(nUrl); // Update the url, our work here is done
        }
      }
    };
  }
}

extern "C"
{
  okapi::Plugin *new_plugin(okapi::IPluginManager &pluginManager)
  {
    return (new okapi::plugins::BasicRewrite(pluginManager));
  }
}
