#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
    H,
    A,
    B,
    C,
    S,
    ERR
};

class lexer
{
    int status;
    int chr;
    void Aa();
    void Bb();
    void Cc();
    void Ss();
    void Hh();
    void Error() {};
public:
    int isCorrect() const{
        return status == S;
    }
    void setChar(int c); 
    lexer(){
        status = H;
        chr = -1;
    }
};

void lexer::setChar(int c)
{
    chr = c;
    if(status == A)
        Aa();
    else if(status == B)
        Bb();
    else if(status == C)
        Cc();
    else if(status == ERR)
        Error();
    else if(status == H)
        Hh();
    else if(status == S)
        Ss();
}

void lexer::Aa()
{
    if(chr == '@'){
        status = S;
    }
    else if(!(chr == '<' || chr == '=' || chr == '-'))
        status = ERR;
}

void lexer::Bb()
{
    if(chr == '*'){
        status = S;
    }
    else if(!(chr == '>' || chr == '=' || chr == '-'))
        status = ERR;
}

void lexer::Cc()
{
    if(chr == '<')
        status = A;
    else if(chr == '>')
        status = B;
    else if(!(chr == '=' || chr == '-'))
        status = ERR;
}

void lexer::Ss()
{
    status = ERR;
}

void lexer::Hh()
{
    if(chr == '-')
        status = C;
    else
        status = ERR;
}

int main(int argc, char ** argv)
{
    lexer obj;
    if(argc > 1){
        int len = strlen(argv[1]);
        for (int i = 0; i < len; i++)
            obj.setChar(argv[1][i]);
    }
    else {
        int c;
        while((c = getchar()) != EOF){
            obj.setChar(c); 
        }
    }
    if(obj.isCorrect())
        printf("OK\n");
    else
        printf("Not OK\n");
    return 0;
}
