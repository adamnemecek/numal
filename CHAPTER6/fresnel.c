#include "../real.h"


void fresnel(real_t x, real_t *c, real_t *s)
{
	void fg(real_t, real_t *, real_t *);
	real_t absx,x3,x4,a,p,q,f,g,c1,s1;

	absx=fabs(x);
	if (absx <= 1.2) {
		a=x*x;
		x3=a*x;
		x4=a*a;
		p=(((5.47711385682687e-6*x4-5.28079651372623e-4)*x4+
				1.76193952543491e-2)*x4-1.99460898826184e-1)*x4+1.0;
		q=(((1.18938901422876e-7*x4+1.55237885276994e-5)*x4+
				1.09957215025642e-3)*x4+4.72792112010453e-2)*x4+1.0;
		*c = x*p/q;
		p=(((6.71748466625141e-7*x4-8.45557284352777e-5)*x4+
				3.87782123463683e-3)*x4-7.07489915144523e-2)*x4+
				5.23598775598299e-1;
		q=(((5.95281227678410e-8*x4+9.62690875939034e-6)*x4+
				8.17091942152134e-4)*x4+4.11223151142384e-2)*x4+1.0;
		*s = x3*p/q;
	} else if (absx <= 1.6) {
		a=x*x;
		x3=a*x;
		x4=a*a;
		p=((((-5.68293310121871e-8*x4+1.02365435056106e-5)*x4-
				6.71376034694922e-4)*x4+1.91870279431747e-2)*x4-
				2.07073360335324e-1)*x4+1.00000000000111e0;
		q=((((4.41701374065010e-10*x4+8.77945377892369e-8)*x4+
				1.01344630866749e-5)*x4+7.88905245052360e-4)*x4+
				3.96667496952323e-2)*x4+1.0;
		*c = x*p/q;
		p=((((-5.76765815593089e-9*x4+1.28531043742725e-6)*x4-
				1.09540023911435e-4)*x4+4.30730526504367e-3)*x4-
				7.37766914010191e-2)*x4+5.23598775598344e-1;
		q=((((2.05539124458580e-10*x4+5.03090581246612e-8)*x4+
				6.87086265718620e-6)*x4+6.18224620195473e-4)*x4+
				3.53398342767472e-2)*x4+1.0;
		*s = x3*p/q;
	} else if (absx < 1.0e15) {
		fg(x,&f,&g);
		a=x*x;
		a=(a-floor(a/4.0)*4.0)*1.57079632679490;
		c1=cos(a);
		s1=sin(a);
		a = (x < 0.0) ? -0.5 : 0.5;
		*c = f*s1-g*c1+a;
		*s = -f*c1-g*s1+a;
	} else
		*c = *s = ((x > 0.0) ? 0.5 : -0.5);
}
