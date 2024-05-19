#include "gamemaster.hpp"

using namespace genv;

GameMaster::GameMaster(BoardWidget &bw, int width)
    : board(7, std::vector<bool>(6, false)), colors(7, std::vector<bool>(6, false)), column_heights(7, 0),
      current_color(true), game_over(false), winner_color(true), board_widget(bw), win_width(width) {}

bool GameMaster::check_win(int x, int y, bool color) {
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

    for (auto &dir : directions) {
        int count = 1;

        for (int i = 1; i < 4; ++i) {
            int nx = x + dir[0] * i;
            int ny = y + dir[1] * i;
            if (nx >= 0 && nx < 7 && ny >= 0 && ny < 6 && board[nx][ny] && colors[nx][ny] == color) {
                count++;
            } else {
                break;
            }
        }

        for (int i = 1; i < 4; ++i) {
            int nx = x - dir[0] * i;
            int ny = y - dir[1] * i;
            if (nx >= 0 && nx < 7 && ny >= 0 && ny < 6 && board[nx][ny] && colors[nx][ny] == color) {
                count++;
            } else {
                break;
            }
        }

        if (count >= 4) {
            return true;
        }
    }
    return false;
}

void GameMaster::handle_event(const event &ev) {
    if (ev.type == ev_mouse && ev.button == btn_left && !game_over) {
        if (ev.pos_y <= 96 && ev.pos_y >= 30) {
            for (int i = 0; i < 7; i++) {
                if (ev.pos_x <= 40 + i * 110 + 60 && ev.pos_x >= 40 + i * 110) {
                    int height = column_heights[i];
                    if (height < 6) {
                        board[i][height] = true;
                        colors[i][height] = current_color;
                        board_widget.add_token(i, height, current_color);
                        if (check_win(i, height, current_color)) {
                            game_over = true;
                            winner_color = current_color;
                        }
                        column_heights[i]++;
                        current_color = !current_color;
                    }
                    break;
                }
            }
        }
    }
}


void GameMaster::show_winner() const {
    if (game_over) {
        gout << color(250, 240, 230) << move_to(0, 800) << box(win_width, 100);
        gout << color(0, 0, 0) << move_to(win_width / 2 - 100, 850) << text(winner_color ? "Red wins!" : "Yellow wins!");
        gout << refresh;
    }
}

bool GameMaster::get_current_color() const {
    return current_color;
}
