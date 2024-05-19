#ifndef TOKEN_HPP
#define TOKEN_HPP

struct Token {
    int posx;
    int posy;
    bool color;

    Token(int x, int y, bool c) : posx(x), posy(y), color(c) {}
};

#endif // TOKEN_HPP_INCLUDED
