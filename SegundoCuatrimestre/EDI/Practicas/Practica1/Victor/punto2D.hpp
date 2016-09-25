/*!\file punto2D.hpp
   \brief Punto2D class header file.
   \author Víctor Monserrat Villatoro
   \date 16-02-2015*/

#ifndef __PUNTO2D_HPP__
#define __PUNTO2D_HPP__

#include <cassert>

/*!\namespace ds
   \brief Namespace for Data Structure subject.*/
namespace ds {
  /*!\class Punto2D
     \brief Class to define a two-dimensional point of generic type coordinates
      T.*/
  template<class T>
  class Punto2D {
    /*!\name Public functions or class methods of Punto2D:*/
    public:
      /*!\name Makers:
      @{*/
        /*!\fn Punto2D(const T &x, const T &y)
           \brief Creates a two-dimensional point of generic type coordinates T.
           \arg[in] x The memory adress of a generic type x coordinate.
           \arg[in] y The memory adress of a generic type y coordinate.
           \pre None.
           \post None.
           \sa setX(), setY()*/
      Punto2D(const T &x, const T &y) {
        x_ = x;
        y_ = y;
      }
      /*@}*/
      /*!\name Observers:
      @{*/
      /*!\fn T getX() const
         \brief Returns the x coordinate of the point.
         \pre None.
         \post None.
         \return The x coordinate of the point.*/
      inline T getX() const {return x_;}
      /*!\fn T getY() const
         \brief Return the y coordinate of the point.
         \pre None.
         \post None.
         \return The y coordinate of the point.*/
      inline T getY() const {return y_;}
      /*!\fn bool sonIguales(const Punto2D<T> &p) const
         \brief Checks if the given point is equal to the current.
         \arg[in] p The memory adress of a two-dimensional point of generic type
          coordinates T.
         \pre None.
         \post sonIguales(p) == (getX()==p.getX() && getY()==p.getY())
         \sa getX(), getY()
         \retval TRUE The given point is equal to the current.
         \retval FALSE The given point is not equal to the current.*/
      bool sonIguales(const Punto2D<T> &p) const {
        #ifndef NDEBUG
        bool returnValue = getX()==p.getX() && getY()==p.getY();

        if(returnValue) {
          assert(getX()==p.getX() && getY()==p.getY());
        }
        #endif
        return(getX()==p.getX() && getY()==p.getY());
      }
      /*@}*/
      /*!\name Modifiers:
      @{*/
      /*!\fn void setX(const T &x)
         \brief Assigns to the two-dimensional point a new value attribute x.
         \arg[in] x The memory adress of a generic type x coordinate.
         \pre None.
         \post None.*/
      inline void setX(const T &x) {x_ = x;}
      /*!\fn void setY(const T &y)
         \brief Assigns to the two-dimensional point a new value attribute y.
         \arg[in] y The memory adress of a generic type y coordinate.
         \pre None.
         \post None.*/
      inline void setY(const T &y) {y_ = y;}
      /*@}*/
    /*!\name Private attributes of the class Punto2D:*/
    private:
      /*!\var T x_
        \brief Generic type coordinate x.*/
      T x_;
      /*!\var T y_
        \brief Generic type coordinate y.*/
      T y_;
  }; /*!class Punto2D*/
} /*!namespace ds*/

#endif
