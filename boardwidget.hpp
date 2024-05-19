#ifndef BOARDWIDGET_HPP_INCLUDED
#define BOARDWIDGET_HPP_INCLUDED

#include "beadwidget.hpp"
#include "token.hpp"
#include <vector>

class BoardWidget : public BeadWidget {
    std::vector<Token> tokens;
public:
    BoardWidget(int x, int y, int w, int h);

    void add_token(int x, int y, bool color);
    void draw(bool next) const override;
    std::string get_value() const override { return ""; }
    void handle_event(const genv::event &ev) override {}
    void show_board(const std::vector<Token> &t);
};

#endif // BOARDWIDGET_HPP_INCLUDE
