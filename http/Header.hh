#ifndef   __HTTP_HEADER_HH__
# define  __HTTP_HEADER_HH__

///
/// \file Header.hh
///

# include <map>
# include <string>
# include <utility>

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
    /// \class Header
    ///

    class Header
    {
    public:
      Header(void);

      ///
      /// \fn bool hasField(std::string const &name) const;
      /// \brief Tells if the header contains a certain field
      /// \param name The name of the header field
      /// \return A boolean : true if the field is set, false otherwise
      ///

      bool hasField(std::string const &name) const;

      ///
      /// \fn bool removeField(std::string const &name);
      /// \brief Remove a header field
      /// \param name The name of the field to be removed
      /// \return A boolean : true if the field has been removed, false otherwise
      ///

      bool removeField(std::string const &name);

      ///
      /// \fn std::string const *getField(std::string const &name) const;
      /// \brief Returns the content of a field
      /// \param name The name of the feld
      /// \return A pointer to a string containing the value of the field or NULL if no such field is found
      ///

      std::string const *getField(std::string const &name) const;

      ///
      /// \fn bool setField(std::string const &name, std::string const &value);
      /// \brief Sets the content of a field
      /// \param name The name of the field
      /// \param value The value of the field that is being set
      ///

      void setField(std::string const &name, std::string const &value);


      std::string const &getHeader(void) const;
      std::map<std::string, std::string> const &getHeaderFields(void) const;

      Header &operator<<(std::string const &data);
      Header &operator<<(std::pair<std::string, std::string> const &data);

    private:
      std::map<std::string, std::string> _fields;
    };

  }

}

#endif    /* __HTTP_HEADER_HH__ */
