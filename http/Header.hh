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
      /// \fn bool hasField(std::string const &name) const
      /// \brief Tells if the header contains a certain field
      /// \param name The name of the header field
      /// \return A boolean : true if the field is set, false otherwise
      ///

      bool hasField(std::string const &name) const;

      ///
      /// \fn bool removeField(std::string const &name)
      /// \brief Remove a header field
      /// \param name The name of the field to be removed
      /// \return A boolean : true if the field has been removed, false otherwise
      ///

      bool removeField(std::string const &name);

      ///
      /// \fn std::string const *getField(std::string const &name) const
      /// \brief Returns the content of a field
      /// \param name The name of the feld
      /// \return A pointer to a string containing the value of the field or NULL if no such field is found
      ///

      std::string const *getField(std::string const &name) const;

      ///
      /// \fn bool setField(std::string const &name, std::string const &value)
      /// \brief Sets the content of a field
      /// \param name The name of the field
      /// \param value The value of the field that is being set
      ///

      void setField(std::string const &name, std::string const &value);

      ///
      /// \fn std::string const &getHeader(void) const
      /// \brief Gets the header content
      /// \return A reference to the header content as a string
      ///

      std::string const &getHeader(void) const;

      ///
      /// \fn std::map<std::string, std::string> const &getHeaderFields(void) const
      /// \brief Gets the header content
      /// \return A reference to the header content as a key-value map
      ///

      std::map<std::string, std::string> const &getHeaderFields(void) const;

      ///
      /// \fn Header &operator<<(std::string const &data)
      /// \brief Fills the header content with the given string
      /// \param data String to be added to the header content 
      ///

      Header &operator<<(std::string const &data);

      ///
      /// \fn Header &operator<<(std::pair<std::string, std::string> const &data)
      /// \brief Fills the header content with the given key-value entry
      /// \param data Key-value entry to be added to the header content 
      ///

      Header &operator<<(std::pair<std::string, std::string> const &data);

    private:
      std::map<std::string, std::string> _fields;
    };

  }

}

#endif    /* __HTTP_HEADER_HH__ */
