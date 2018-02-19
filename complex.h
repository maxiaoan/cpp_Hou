#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;

complex& __doapl (complex* ths, const complex& r);
complex& __doami (complex* ths, const complex& r);
complex& __doaml (complex* ths, const complex& r);

double real ( const complex & x);
double imag ( const complex & x);

class complex
{
public:
	complex (double r = 0,double i = 0): re (r) , im (i) {}
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	double real () const { return re; }
	double imag () const { return im; }

private:
	double re, im;

	friend complex& __doapl (complex* , const complex&);
	friend complex& __doami (complex* , const complex&);
	friend complex& __doaml (complex* , const complex&);	
};

inline complex& __doapl (complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
inline complex& __doami (complex* ths, const complex& r)
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths
}
inline complex* __doaml (complex* ths, const complex& r)
{
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f;
	ths->im *= r.im;
}


inline complex& complex::operator += (const complex& r)
{
	return __doapl (this, r);
}


inline complex operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y));
}

inline complex operator + (double x, const complex& y)
{
	return complex (x + real(y), imag(y));
}

inline complex operator + (const complex& x, double y)
{
	return complex (real(x) + y, imag(x));
}

inline double real ( const complex & x)
{
	return x.real ();
}

inline double imag ( const complex & x)
{
	return x.imag ();
}

#endif












