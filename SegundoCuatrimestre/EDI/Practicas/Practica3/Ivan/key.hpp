/*!
  \file key.hpp
  \brief
  \author Iván Portillo Leal
*/
#ifndef KEY_HPP
#define KEY_HPP

#include <iostream>
#include <fstream>

/*!\namespace ds
  \brief Namespace to the Data Structure subject
*/
namespace ds{
  /*!\class Key
     \brief Class defining a key
  */
  class Key{
    /*!\name Private part of the class Key:*/
  private:
    /*!\var int DNI_
        \brief DNI of the person
    */
    int DNI_;
    /*!\var int position_
        \brief Position of the person in the list
    */
    int position_;

    /*!\name Public part of the class Key:*/
  public:
    /*!\name Makers:
      @{*/

    /*!\fn Key()
        \brief Generates a key
        \pre Nothing
        \post Nothing
    */
    Key();
    /*!\fn Key(int dni, int position)
        \brief Generates a key
        \param dni DNI of the key
        \param position Position in the tree
        \pre Nothing
        \post Nothing
    */
    Key(int dni, int position);
    /*!\fn Key(const Key& key)
        \brief Generates a key
        \param key Key to create object
        \pre Nothing
        \post Nothing
    */
    Key(const Key& key);
    /*@}*/

    /*!\name Setters:
      @{*/

    /*!\fn void setDNI(const int &dni)
        \brief Set DNI in the key
        \param dni DNI to set
    */
    inline void setDNI(const int &dni){ DNI_ = dni; }
    /*!\fn void setPosition(const int &position)
        \brief Set Position in the key
        \param position Position to set
    */
    inline void setPosition(const int &position){ position_ = position; }
    /*@}*/

    /*!\name Getters:
      @{*/
    /*!\fn const int& getDNI() const
        \brief Get DNI of the key
        \return DNI of the key
    */
    inline const int& getDNI() const{ return DNI_; }
    /*!\fn const int& getPosition() const
        \brief Get Position of the key
        \return Position of the key
    */
    inline const int& getPosition() const{ return position_; }
    /*@}*/

    /*!\name Operators:
      @{*/
    /*!\fn bool operator<(const Key& key) const
    */
    inline bool operator<(const Key& key) const{ return (getDNI() < key.getDNI()); }
    /*!\fn bool operator>(const Key& key) const
    */
    inline bool operator>(const Key& key) const{ return (getDNI() > key.getDNI()); }
    /*!\fn bool operator==(const Key& key) const
    */
    inline bool operator==(const Key& key) const{ return (getDNI() == key.getDNI()); }
    /*!\fn bool operator<=(const Key& key) const
    */
    inline bool operator<=(const Key& key) const{ return (getDNI() <= key.getDNI()); }
    /*!\fn bool operator>=(const Key& key) const
    */
    inline bool operator>=(const Key& key) const{ return (getDNI() >= key.getDNI()); }
    /*!\fn Key& operator=(const Key& key)
    */
    Key& operator=(const Key& key);
    /*!\fn std::ostream& operator<<(std::ostream& out, const Key& key)
    */
    friend std::ostream& operator<<(std::ostream& out, const Key& key);
    /*!\fn std::istream& operator>>(std::istream& in, const Key& key)
    */
    friend std::istream& operator>>(std::istream& in, const Key& key);
    /*!\fn std::ofstream& operator<<(std::ofstream& out, const Key& key)
    */
    friend std::ofstream& operator<<(std::ofstream& out, const Key& key);
    /*!\fn std::ifstream& operator>>(std::ifstream& in, const Key& key)
    */
    friend std::ifstream& operator>>(std::ifstream& in, const Key& key);
    /*@}*/
  };
}

#endif
