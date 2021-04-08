#include <stdio.h>
#include <stdlib.h>

class badSegment
{
};

class badAddition
{
    float a1, a2, b1, b2;
public:
    badAddition(float xa1, float xa2, float xb1, float xb2)
    {
        a1 = xa1;
        a2 = xa2;
        b1 = xb1;
        b2 = xb2;
    };
    float getA1() const {return a1;};
    float getA2() const {return a2;};
    float getB1() const {return b1;};
    float getB2() const {return b2;};
};

class floatPair
{
    float a;
    float b;
protected:
    float getA() const
    {
        return a;
    }
    float getB() const
    {
        return b;
    }
public:
    virtual float measure() const = 0;
    virtual ~floatPair(){};
    floatPair(float xa, float xb) {
        a = xa;
        b = xb;
    };
};

class segment : public floatPair
{
public:
    virtual float measure() const
    {
        return getB() - getA();
    };
    virtual ~segment(){};
    segment(float xa = 0, float xb = 0) : floatPair(xa, xb)
    {
        if(xa > xb)
            throw badSegment();
    }
    segment operator+(segment op) const;
};

float max(float a1, float a2, float b1, float b2)
{
    float max = a1;
    if(a2 > max)
        max = a2;
    if(b1 > max)
        max = b1;
    if(b2 > max)
        max = b2;
    return max;
}

float min(float a1, float a2, float b1, float b2)
{
    float min = a1;
    if(a2 < min)
        min = a2;
    if(b1 < min)
        min = b1;
    if(b2 < min)
        min = b2;
    return min;
}

segment segment::operator+(segment op) const
{
    float a1 = getA();
    float a2 = op.getA();
    float b1 = getB();
    float b2 = op.getB();
    if(b1 >= a2 && b2 >= a1)
        return segment(min(a1, a2, b1, b2), max(a1, a2, b1, b2));
    throw badAddition(a1, a2, b1, b2);
}

int main()
{
    try{
        segment f(1, 2), g(0.5, 5), h(2.5, 6.5);
        printf("%3.3f, %3.3f, %3.3f\n",
            (f+g).measure(), (g+h).measure(), (f+g+h).measure());
        printf("%3.3f\n", (f+h).measure());
    }
    catch(const badAddition & bad){
        printf("Bad addition: [%3.3f; %3.3f] + [%3.3f; %3.3f]\n",
            bad.getA1(), bad.getB1(), bad.getA2(), bad.getB2());
    }
    catch(badSegment b){
        printf("Bad segment\n");
    }
    return 0;
}