#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class stream
{
public:
    stream(){};
    virtual int getChar() = 0;
    virtual ~stream(){};
};

class strStream : public stream
{
    char * str;
    unsigned int ind;
public:
    strStream(char * astr) : str(astr), ind(-1){};
    int getChar(){
        ind++;
        if(ind < strlen(str))
            return str[ind];
        return EOF;
    }
    virtual ~strStream(){};
};

class stdStream : public stream
{
public:
    stdStream(){};
    int getChar(){
        int c = getchar();
        return c;
    }
    virtual ~stdStream(){};
};

class syntaxer
{
    int chr;
    stream * str;
    void R();
    void N();
    void setChar(){
        chr = str->getChar();
    }
    void S();
public:
    void start();
    syntaxer(stream * a) : str(a){};
};

void syntaxer::S()
{
    if(chr != '(')
        throw "Expected (";
    setChar();
    R();
}

void syntaxer::R()
{
    if(chr == '*'){
        setChar();
        S();
        if(chr != ')')
            throw "Expected )";
        setChar();
    }
    else if(chr == '('){
        setChar();
        N();
        if(chr != ')')
            throw "Expected )";
        setChar();    
    }
    else
        throw "Expected * or (";
}

void syntaxer::N()
{
    if(chr == '('){
        setChar();
        R();
        N();
    }
    else if(chr != '*' && chr != EOF && chr != ')'){
        setChar();
        N();
    }
    else if(chr == ')')
        return;
}

void syntaxer::start()
{
    setChar();
    if(chr == EOF)
        return;
    S();
    if(chr != EOF)
        throw "Expected EOF";
}

int main(int argc, char ** argv)
{
    int errflag = 0;
    try{
        if(argc > 1){
            stream * a;
            strStream aobj(argv[1]);
            a = &aobj;
            syntaxer obj(a);
            obj.start();
        }
        else{
            stream * a;
            stdStream aobj;
            a = &aobj;
            syntaxer obj(a);
            obj.start();
        }
    }
    catch(const char * err){
        errflag = 1;
        printf("%s\n", err);
    }
    if(!errflag)
        printf("OK\n");
    return 0;
}