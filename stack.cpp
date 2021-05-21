#include <stdio.h>
#include <stdlib.h>

struct list
{
    int value;
    list * next;
};

class abstractStack
{
    list * stack;
protected:
    virtual bool check(int a) const = 0;
public:
    bool pop(int & x){
        if(stack){
            x = stack -> value;
            list * tmp = stack;
            stack = stack -> next;
            delete tmp;
            return true;
        }
        return false;
    };
    bool push(int x){
        if(check(x)){
            list * tmp = new list;
            tmp -> value = x;
            tmp -> next = stack;
            stack = tmp;
            return true;
        }
        return false;
    };
    abstractStack(){
        stack = NULL;
    }
    virtual ~abstractStack(){
        list * tmp = stack;
        while(stack){
            tmp = stack;
            stack = stack -> next;
            delete tmp;
        }
    };
};

class deciStack : public abstractStack
{
    int key;
    bool check(int a) const{
        return(abs(a) % 10 == key);     //abs!!
    }
public:
    deciStack(int a) : key(a){};
    virtual ~deciStack(){};
};

class simpleStack : public abstractStack
{
    bool check(int a) const{
        return true;
    }
public:
    virtual ~simpleStack(){};
};

class oddStack : public abstractStack
{
    bool check(int a) const{
        return(abs(a) % 2 == 0);
    }
public:
    virtual ~oddStack(){};
};

class negStack : public abstractStack
{
    bool check(int a) const{
        return (a < 0);
    }
    virtual ~negStack(){};
};

int main()
{
    const int vec[12] = {27, 1, 0, 15, -4, 12, 78, 63, 16, -5, 101, 7};
    abstractStack * obj[5] = {new simpleStack, new oddStack, new negStack,
        new deciStack(2), new deciStack(5)};
    int counters[5] = {0, 0, 0, 0, 0};
    int x;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 5; j++)
            if(obj[j] -> push(vec[i]))
                counters[j]++;
    for (int i = 0; i < 5; i++){
        printf("%2d: ", counters[i]);
        while(obj[i] -> pop(x))
            printf("%3d ", x);
        printf("\n");
    }
    return 0;
}

/*
output:
12:   7 101  -5  16  63  78  12  -4  15   0   1  27 
 5:  16  78  12  -4   0 
 2:  -5  -4 
 1:  12 
 2:  -5  15
*/