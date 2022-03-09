
typedef struct {
  float real ;
  float imaginary ;
} complexe_float_t ;

typedef struct {
  double real ;
  double imaginary ;
} complexe_double_t ;

inline complexe_float_t add_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

inline complexe_double_t add_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}


/*
inline complexe_float_t mult_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{

}

inline complexe_double_t mult_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{

}


inline complexe_float_t div_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{

}

inline complexe_double_t div_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{

}
*/



