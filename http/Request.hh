#ifndef   __HTTP_REQUEST_HH__
# define  __HTTP_REQUEST_HH__

///
/// \file Request.hh
///

# include <string>

# include "Body.hh"
# include "Header.hh"

///
/// \namespace okapi
///

namespace okapi
{

  ///
  /// \namespace http
  ///

  namespace http
  {

    ///
    /// \class Request
    ///

    class Request
    {
    public:

      ///
      /// \enum Status
      ///

      enum Status
      {
        // Continue the request
        CONTINUE,
        // Abort the request
        ABORT
      };

      ///
      /// \enum Method
      /// \brief Http method of the request
      ///

      enum Method
      {
        HEAD, GET, POST, PUT, DELETE, TRACE, OPTIONS, CONNECT, PATCH
      };

      Request(void);

      ///
      /// \fn Header &getHeader(void)
      /// \brief Gets the header of the request
      /// \return A reference to the header of the request
      ///

      Header &getHeader(void);

      ///
      /// \fn Body &getBody(void)
      /// \brief Gets the body of the request
      /// \return A reference to the body of the request
      ///

      Body &getBody(void);

      ///
      /// \fn Method getMethod(void)
      /// \brief Gets the HTTP method of the request
      /// \return A Method enum, the HTTP method of the request
      ///

      Method getMethod(void);

      ///
      /// \fn void setMethod(Method const method)
      /// \brief Sets the HTTP method of the request
      /// \return void
      ///

      void  setMethod(Method const method);

      ///
      /// \fn std::string &getUrl(void);
      /// \brief Returns a mutable reference to the URL field of the request
      /// \return The reference to the string containing the url of the request
      ///

      std::string &getUrl(void);

    private:

      Header _header;
      Body _body;
      Method _method;
      std::string _url;
    };

  }

}

#endif    /* __HTTP_REQUEST_HH__ */
