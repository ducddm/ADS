#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Complex;

Complex *init_complex(double real, double vir){
    Complex *c = malloc(sizeof(Complex));
    c->x=real;
    c->y=vir;
    return c;
}

Complex *plus(Complex *c1, Complex *c2){
    Complex *plus = malloc(sizeof(Complex));
    plus->x = c1->x + c2->x;
    plus->y = c1->y + c2->y;
    return plus;
}

Complex *minus(Complex *c1, Complex *c2){
	Complex *minus = malloc(sizeof(Complex));
    minus->x = c1->x - c2->x;
    minus->y = c1->y - c2->y;
    return minus;
}

Complex *multiply(Complex *c1, Complex *c2){
	Complex *res = malloc(sizeof(Complex));
	res->x = c1->x*c2->x - c1->y*c2->y;
	res->y = c1->x*c2->y + c1->y*c2->x;
	return res;
}

Complex *divide(Complex *c1, Complex *c2){
	Complex *conjugation = init_complex(c2->x,-c2->y);
	Complex *res = malloc(sizeof(Complex));
	res->x = (multiply(c1,conjugation)->x)/(pow(c2->x,2)+pow(c2->y,2));
	res->y = (multiply(c1,conjugation)->y)/(pow(c2->x,2)+pow(c2->y,2));
	return res;
}
int main(){
    Complex *c1 = init_complex(1,2);
    Complex *c2 = init_complex(2,3);
    Complex *p = plus(c1,c2);
    Complex *q = minus(c1,c2);
    Complex *r = multiply(c1,c2);
    Complex *s = divide(c1,c2);
    printf("%lf + %lf * i\n", p->x, p->y);
    printf("%lf + %lf * i\n", q->x, q->y);
    printf("%lf + %lf * i\n", r->x, r->y);
    printf("%lf + %lf * i\n", s->x, s->y);
    return 0;
}
    
