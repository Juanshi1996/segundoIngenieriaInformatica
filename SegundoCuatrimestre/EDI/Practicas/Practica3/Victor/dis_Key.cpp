#include "dis_Key.hpp"
#include <iostream>
#include <fstream>

dis::Key::Key() {
  this->_id = -1;
  this->_position = -1;
};
dis::Key::Key(const unsigned &id, const unsigned &position) {
  this->_id = id;
  this->_position = position;
};
dis::Key& dis::Key::operator=(const dis::Key &k) {
  this->_id = k._id;
  this->_position = k._position;
  return(*this);
};
bool dis::Key::operator==(const dis::Key &k) const {
  return(this->_id == k._id and this->_position == k._position);
};
bool dis::Key::operator<(const dis::Key &k) const {
  if(this->_id < k._id) {
    return(true);
  } else if(this->_id == k._id) {
    return(this->_position < k._position);
  } else {
    return(false);
  }
};
bool dis::Key::operator<=(const dis::Key &k) const {
  return(*this < k or *this == k);
};
bool dis::Key::operator>(const dis::Key &k) const {
  return(not (*this <= k));
};
bool dis::Key::operator>=(const dis::Key &k) const {
  return(not (*this < k));
};
std::ostream& operator<<(std::ostream &stream, const dis::Key &k) {
  stream << k.getId() << k.getPosition() << std::endl;
  return(stream);
};
std::ofstream& operator<<(std::ofstream &stream, const dis::Key &k) {
  stream << k.getId() << k.getPosition() << std::endl;
  return(stream);
};
std::istream& operator>>(std::istream &stream, dis::Key &k) {
  unsigned aux;
  std::cout << "ID: ";
  stream >> aux;
  k.setId(aux);
  std::cout << "Position: ";
  stream >> aux;
  k.setPosition(aux);
  return(stream);
};
std::ifstream& operator>>(std::ifstream &stream, dis::Key &k) {
  unsigned aux;
  stream >> aux;
  k.setId(aux);
  stream >> aux;
  k.setPosition(aux);
  return(stream);
};
