#include "../real.h"


void hsh3col(int la, int lb, int u, int i, real_t a1, real_t a2,
				real_t a3, real_t **a, real_t **b)
{
	real_t *allocate_real_vector(int, int);
	void free_real_vector(real_t *, int);
	void hshvecmat(int, int, int, int, real_t, real_t [], real_t **);
	real_t c,*v,d1,d2,d3,s1,s2,s3,r1,r2,r3,d;

	if (a2 != 0.0 || a3 != 0.0) {
		v=allocate_real_vector(i,i+2);
		d1=fabs(a1);
		d2=fabs(a2);
		d3=fabs(a3);
		s1 = (a1 >= 0.0) ? 1.0 : -1.0;
		s2 = (a2 >= 0.0) ? 1.0 : -1.0;
		s3 = (a3 >= 0.0) ? 1.0 : -1.0;
		if (d1 >= d2 && d1 >= d3) {
			r2=d2/d1;
			r3=d3/d1;
			d=sqrt(1.0+r2*r2+r3*r3);
			c = -1.0-(1.0/d);
			d=1.0/(1.0+d);
			v[i+1]=s1*s2*r2*d;
			v[i+2]=s1*s3*r3*d;
		} else if (d2 >= d1 && d2 >= d3) {
			r1=d1/d2;
			r3=d3/d2;
			d=sqrt(1.0+r1*r1+r3*r3);
			c = -1.0-(s1*r1/d);
			d=1.0/(r1+d);
			v[i+1]=s1*s2*d;
			v[i+2]=s1*s3*r3*d;
		} else {
			r1=d1/d3;
			r2=d2/d3;
			d=sqrt(1.0+r1*r1+r2*r2);
			c = -1.0-(s1*r1/d);
			d=1.0/(r1+d);
			v[i+1]=s1*s2*r2*d;
			v[i+2]=s1*s3*d;
		}
		v[i]=1.0;
		hshvecmat(i,i+2,la,u,c,v,a);
		hshvecmat(i,i+2,lb,u,c,v,b);
		free_real_vector(v,i);
	}
}
