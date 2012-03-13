#ifndef   __HTTP_REQUEST_HH__
# define  __HTTP_REQUEST_HH__

///
/// \file Request.hh
///

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
	  CONTINUE, ABORT
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

    private:

      Header _header;
      Body _body;
    };

  }

}

#endif    /* __HTTP_REQUEST_HH__ */
