#ifndef   __HTTP_RESPONSE_HH__
# define  __HTTP_RESPONSE_HH__

///
/// \file Response.hh
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
    /// \class Response
    ///

    class Response
    {
    public:
      Response();

      ///
      /// \fn Header &getHeader(void)
      /// \brief Gets the header of the response
      /// \return A reference to the header of the response
      ///

      Header &getHeader(void);

      ///
      /// \fn Body &getBody(void)
      /// \brief Gets the body of the response
      /// \return A reference to the body of the response
      ///

      Body &getBody(void);

    private:
      Header _header;
      Body _body;
    };

  }

}

#endif    /* __HTTP_ANSWER_HH__ */
