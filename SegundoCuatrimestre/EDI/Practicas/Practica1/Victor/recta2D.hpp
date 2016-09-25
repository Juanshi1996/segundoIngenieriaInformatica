/*!\file recta2D.hpp
   \brief Recta2D class header file.
   \author Víctor Monserrat Villatoro
   \date 16-02-2015*/

#ifndef __RECTA2D_HPP__
#define __RECTA2D_HPP__

#include "punto2D.hpp"
#include <cassert>
#include <cstdlib>
#include <cmath>

/*!\namespace ds
   \brief Namespace for Data Structure subject.*/
namespace ds {
  /*!\class Recta2D
     \brief Class to define a two-dimensional line of generic type parameters
      T.*/
  template<class T>
  class Recta2D {
    /*!\name Public functions or class methods of Recta2D:*/
    public:
      /*!\name Makers:
      @{*/
        /*!\fn Recta2D(const T &a, const T &b, const T &c)
           \brief Creates a a line using the implicit equation ax + ​​by + c = 0.
           \arg[in] a The memory adress of a generic type a parameter at
            equation.
           \arg[in] b The memory adress of a generic type b parameter at
            equation.
           \arg[in] c The memory adress of a generic type c parameter at
            equation.
           \attention Overloaded function.
           \pre None.
           \post None.
           \sa setA(), setB(), setC()*/
      Recta2D(const T &a, const T &b, const T &c) {
        a_ = a;
        b_ = b;
        c_ = c;
      }
        /*!\fn Recta2D(const Punto2D<T> &p, const Punto2D<T> &q)
           \brief Creates a line through the generic type point p and q.
           \arg[in] p The memory adress of a two-dimensional point of generic
            type coordinates T.
           \arg[in] q The memory adress of a two-dimensional point of generic
            type coordinates T.
           \attention Overloaded function.
           \pre not p.sonIguales(q)
           \post None.
           \sa setA(), setB(), setC(), Punto2D::getX(), Punto2D::getY()*/
      Recta2D(const Punto2D<T> &p, const Punto2D<T> &q) {
        assert(!p.sonIguales(q));
        a_ = q.getY() - p.getY();
        b_ = p.getX() - q.getX();
        c_ = -p.getX() * q.getY() + p.getY() * q.getX();
      }
      /*@}*/
      /*!\name Observers:
      @{*/
      /*!\fn T getA() const
         \brief Returns the a value in the parametric equation ax + by + c = 0
         \pre None.
         \post None.
         \return The a value in the parametric equation ax + by + c = 0*/
      inline T getA() const {return a_;}
      /*!\fn T getB() const
         \brief Returns the b value in the parametric equation ax + by + c = 0
         \pre None.
         \post None.
         \return The b value in the parametric equation ax + by + c = 0*/
      inline T getB() const {return b_;}
      /*!\fn T getC() const
         \brief Returns the c value in the parametric equation ax + by + c = 0
         \pre None.
         \post None.
         \return The c value in the parametric equation ax + by + c = 0*/
      inline T getC() const {return c_;}
      /*!\fn T distancia(const Punto2D<T> &p) const
         \brief Calculate the minimum distance from the point p to the line.
         \arg[in] p The memory adress of a two-dimensional point of generic type
          coordinates T.
         \pre None.
         \post None.
         \return The minimum generic type distance from the point p to the
          line.
         \sa getA(), getB(), getC(), Punto2D::getX(), Punto2D::getY()*/
      T distancia(const Punto2D<T> &p) const {
        return(fabs(getA() * p.getX() + getB() * p.getY() + getC()) /
        sqrt(pow(getA(), 2) + (pow(getB(), 2))));
      }
      /*@}*/
      /*!\name Modifiers:
      @{*/
      /*!\fn void setA(const T &a)
         \brief Returns the a value in the parametric equation ax + by + c = 0
         \arg[in] a The a value in the parametric equation ax + by + c = 0
         \pre None.
         \post None.*/
      inline void setA(const T &a) {a_ = a;}
      /*!\fn void setB(const T &b)
         \brief Returns the a value in the parametric equation ax + by + c = 0
         \arg[in] b The b value in the parametric equation ax + by + c = 0
         \pre None.
         \post None.*/
      inline void setB(const T &b) {b_ = b;}
      /*!\fn void setC(const T &c)
         \brief Returns the c value in the parametric equation ax + by + c = 0
         \arg[in] c The c value in the parametric equation ax + by + c = 0
         \pre None.
         \post None.*/
      inline void setC(const T &c) {c_ = c;}
      /*@}*/
    /*!\name Private attributes of the class Recta2D:*/
    private:
      /*!\var T a_
        \brief Generic type parameter a.*/
      T a_;
      /*!\var T b_
        \brief Generic type parameter b.*/
      T b_;
      /*!\var T c_
        \brief Generic type parameter c.*/
      T c_;
  }; /*!class Recta2D*/
} /*!namespace ds*/

#endif
