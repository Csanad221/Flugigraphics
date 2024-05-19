#include <vector>
#include "boardwidget.hpp"
#include "token.hpp"

using namespace genv;

BoardWidget::BoardWidget(int x, int y, int w, int h) : BeadWidget(x, y, w, h) {}

void BoardWidget::add_token(int x, int y, bool color) {
    tokens.push_back(Token(x, y, color));
}

void BoardWidget::draw(bool next) const {
    gout << color(250, 240, 230) << move_to(0, 0) << box(_w, _h);

    for (int k = 0; k < 7; k++) {
        gout << move_to(40 + k * 110, 30) << color(100, 100, 100) << box(60, 66)
             << move_to(44 + k * 110, 34) << color(190, 190, 190) << box(52, 58);
        if (next) {
            gout << color(255, 0, 0) << move_to(62 + k * 110, 40) << box(16, 15);
            for (int l = 0; l < 16; l++) {
                gout << move_to(54 + k * 110 + l, 55 + l) << box(32 - l * 2, l + 1);
            }
        } else {
            gout << color(255, 255, 0) << move_to(62 + k * 110, 40) << box(16, 15);
            for (int l = 0; l < 16; l++) {
                gout << move_to(54 + k * 110 + l, 55 + l) << box(32 - l * 2, l + 1);
            }
        }
    }

    gout << move_to(10, 120) << color(74, 25, 44) << box(780, 670);

    for (int j = 0; j < 7; j++) {
            for (int i = 0; i < 6; i++) {
                gout << color(250, 240, 230) << move_to(20 + j * 110, 130 + i * 110) << box(100, 100);
            }
        }

    for (const auto &token : tokens) {
        int pixel_x = 20 + token.posx * 110;
        int pixel_y = 680 - token.posy * 110;
        if (token.color) {
            gout << move_to(pixel_x, pixel_y) << color(255, 0, 0) << box(100, 100);
        } else {
            gout << move_to(pixel_x, pixel_y) << color(255, 255, 0) << box(100, 100);
        }
    }

    gout << refresh;
}
