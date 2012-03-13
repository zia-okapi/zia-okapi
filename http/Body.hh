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

    ///
    /// \typedef Raw body's data
    ///

    typedef std::vector<char> RawData;

    ///
    /// \class Body
    ///

    class Body
    {
    public:

      ///
      /// \fn Body()
      /// \brief Default constructor
      ///

      Body();

      ///
      /// \fn Body(std::string const & from)
      /// \brief Constructor
      /// \param from Fills the body content with the given string
      ///

      Body(std::string const & from);

      ///
      /// \fn Body(RawData const & from)
      /// \brief Constructor
      /// \param from Fills the body content with the given data
      ///

      Body(RawData const & from);

      ///
      /// \fn Body &operator<<(std::string const &data)
      /// \brief Fills the body content with the given string
      /// \param data String to be added to the body content 
      ///

      Body &operator<<(std::string const &data);

      ///
      /// \fn Body &operator<<(RawData &data)
      /// \brief Fills the body content with the given data
      /// \param data Data to be added to the body content 
      ///

      Body &operator<<(RawData &data);

      ///
      /// \fn RawData const &extractChunk(unsigned int size = 0)
      /// \brief extract a chunk of the given size from the body content
      /// \param size Chunk size
      /// \return Extracted chunk
      ///

      RawData const &extractChunk(unsigned int size = 0);

      ///
      /// \fn RawData const &peekChunk(unsigned int size = 0) const
      /// \brief peek a chunk of the given size in the body content
      /// \param size Chunk size
      /// \return Peeked chunk
      ///

      RawData const &peekChunk(unsigned int size = 0) const;

      ///
      /// \fn unsigned int size(void) const
      /// \brief Gets the raw body size
      /// \return Body size
      ///

      unsigned int size(void) const;

    private:
      RawData _data;
    };

  }

}

#endif    /* __HTTP_BODY_HH__ */
