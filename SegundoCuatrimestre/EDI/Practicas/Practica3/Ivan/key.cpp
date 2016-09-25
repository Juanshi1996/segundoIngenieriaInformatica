#include "key.hpp"

namespace ds{
  Key::Key(){
    setDNI(0);
    setPosition(0);
  }
  Key::Key(int dni, int position){
    setDNI(dni);
    setPosition(position);
  }
  Key::Key(const Key& key){
    setDNI(key.getDNI());
    setPosition(key.getPosition());
  }

  Key& Key::operator=(const Key& key){
    setDNI(key.getDNI());
    setPosition(key.getPosition());
    return *this;
  }
  std::ostream& operator<<(std::ostream& out, const Key& key){
    out << key.getDNI() << ',' << key.getPosition();
    return out;
  }
  std::istream& operator>>(std::istream& in, Key& key){
    int aux;
    std::cout << "DNI: ";
    in >> aux;
    key.setDNI(aux);
    std::cout << "Position: ";
    in >> aux;
    key.setPosition(aux);
    return in;
  }
  std::ofstream& operator<<(std::ofstream& out, const Key& key){
    out << key.getDNI() << ' ' << key.getPosition();
    return out;
  }
  std::ifstream& operator>>(std::ifstream& in, Key& key){
    int aux;
    in >> aux;
    key.setDNI(aux);
    in >> aux;
    key.setPosition(aux);
    return in;
  }
}
