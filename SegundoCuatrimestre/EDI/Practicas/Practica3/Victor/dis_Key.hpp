#ifndef __DIS_KEY_HPP__
#define __DIS_KEY_HPP__

#include <iostream>
#include <fstream>

namespace dis {
  class Key {
  public:
    Key();
    Key(const unsigned &id, const unsigned &position);
    inline Key(const Key &k) {*this = k;};
    Key& operator=(const Key &k);
    bool operator==(const Key &k) const;
    bool operator<(const Key &k) const;
    bool operator<=(const Key &k) const;
    bool operator>(const Key &k) const;
    bool operator>=(const Key &k) const;
    friend std::ostream& operator<<(std::ostream &stream, const Key &k);
    friend std::ofstream& operator<<(std::ofstream &stream, const Key &k);
    friend std::istream& operator>>(std::istream &stream, Key &k);
    friend std::ifstream& operator>>(std::ifstream &stream, Key &k);
    inline const unsigned &getId() const {return(_id);};
    inline const unsigned &getPosition() const {return(_position);};
    inline void setId(const unsigned &id) {_id = id;};
    inline void setPosition(const unsigned &position) {_position = position;};
  private:
    unsigned _id;
    unsigned _position;
  };
};

#endif
