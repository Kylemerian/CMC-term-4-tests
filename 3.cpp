#include <stdio.h>

class Prism
{
    int height;
public:
    Prism(double h) : height(h) {};
    virtual ~Prism(){};
    virtual double square() const = 0;
    double volume() const{
        return square() * height;
    };
};

class Box : public Prism
{
    int side;
public:
    double square() const{
        return side * side;
    };
    Box(double a, double b) : Prism(a), side(b){};
    virtual ~Box(){}; 
};

class Cube : public Box
{
public:
    Cube(double a) : Box(a, a){};
    virtual ~Cube(){};
};

int main()
{
    const Prism *p, *q, *r;
    Box a(2, 1), b(1, 2);
    Cube c(3);
    p = &a; q = &b; r = &c;
    printf("squares: %3.3f %3.3f %3.3f\n",p->square(), q->square(), r->square());
    printf("volumes: %3.3f %3.3f %3.3f\n",p->volume(), q->volume(), r->volume());
    return 0;
}
/* output
squares: 1.000 4.000 9.000
volumes: 2.000 4.000 27.000
*/
