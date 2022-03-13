#include "complexe.h"

complexe_float_t add_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

complexe_double_t add_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

complexe_float_t mult_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  /* 
     a implementer
  */

  r.real = 0.0 ;
  r.imaginary = 0.0 ;
  
  return r ;
}

complexe_double_t mult_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
  {
  complexe_double_t r ;

  /* 
     a implementer
  */
  
  r.real = 0.0 ;
  r.imaginary = 0.0 ;
  
  return r ;
}
  

complexe_float_t div_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  /* 
     a implementer
  */

  r.real = 0.0 ;
  r.imaginary = 0.0 ;
  
  return r ;
}

complexe_double_t div_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  /* 
     a implementer
  */

  r.real = 0.0 ;
  r.imaginary = 0.0 ;
  
  return r ;
}
