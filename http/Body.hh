#ifndef   __HTTP_BODY_HH__
# define  __HTTP_BODY_HH__

///
/// \file Body.hh
///

# include <vector>
# include <string>

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
    typedef std::vector<char> RawData;

    ///
    /// \class Body
    ///

    class Body
    {
    public:
      Body();
      Body(std::string const & from);
      Body(RawData const & from);

      Body &operator<<(std::string const &data);
      Body &operator<<(RawData &data);

      RawData const &extractChunk(unsigned int size = 0);
      RawData const &peekChunk(unsigned int size = 0) const;

      unsigned int size(void) const;

    private:
      RawData _data;
    };

  }

}

#endif    /* __HTTP_BODY_HH__ */
