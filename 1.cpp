#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class badAddition
{
    int x1;
    int x2;
    int y1;
    int y2;
public:
    badAddition(int a, int b, int c, int d)
    {
        x1 = a; y1 = b; x2 = c; y2 = d;
    }
    int getX1() const {return x1;};
    int getX2() const {return x2;};
    int getY1() const {return y1;};
    int getY2() const {return y2;};
};

class intPair
{
    int x;
    int y;
protected:
    int getX() const;
    int getY() const;
public:
    intPair(int ax, int ay){
        x = ax;
        y = ay;
    }
    virtual int measure() const = 0;
    virtual ~intPair(){};
};

int intPair::getX() const
{
    return x;
}

int intPair::getY() const
{
    return y;
}

class intRectangle : public intPair
{
public:
    intRectangle(int ax = 0, int ay = 0) : intPair(ax, ay){};
    virtual int measure() const;
    virtual ~intRectangle(){};
    intRectangle operator+(intRectangle b);
};

int cmp(int x, int y)
{
    return x < y;
}

void swap(int * a, int * b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

intRectangle intRectangle::operator+(intRectangle b)
{
    int x1 = this -> getX();
    int y1 = this -> getY();
    int x2 = b.getX();
    int y2 = b.getY();
    if(cmp(x1, y1))
        swap(&x1, &y1);
    if(cmp(x2, y2))
        swap(&x2, &y2);
    if(x1 == x2)
        return intRectangle(x1, y1 + y2);
    if(x1 == y2)
        return intRectangle(x1, x2 + y1);
    if(y1 == x2)
        return intRectangle(y1, x1 + y2);
    if(y1 == y2)
        return intRectangle(y1, x1 + x2);
    throw badAddition(this -> getX(), this -> getY(), b.getX(), b.getY());
}

int intRectangle::measure() const
{
    return getX() * getY();
}

int main()
{
    try{
        intRectangle a(3, 5), b(5, 7), c(11, 4), d(6, 11);
        intRectangle p, q;
        p = a + b;
        q = c + d;
        printf("%d\n", (p+q).measure());
        printf("%d\n", (q+a).measure());
    }
    catch(const badAddition & bad){
        printf("Bad addition: (%d*%d) + (%d*%d)\n",
            bad.getX1(), bad.getY1(), bad.getX2(), bad.getY2());
    }
    return 0;
}
