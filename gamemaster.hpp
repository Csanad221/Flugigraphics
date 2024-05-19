#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "graphics.hpp"
#include "boardwidget.hpp"
#include <vector>

class GameMaster {
    std::vector<std::vector<bool>> board;
    std::vector<std::vector<bool>> colors;
    std::vector<int> column_heights;
    bool current_color;
    bool game_over;
    bool winner_color;
    BoardWidget &board_widget;
    int win_width;

    bool check_win(int x, int y, bool color);

public:
    GameMaster(BoardWidget &bw, int width);

    void handle_event(const genv::event &ev);
    void show_winner() const;
    bool get_current_color() const;
};

#endif // GAMEMASTER_HPP_INCLUDED
