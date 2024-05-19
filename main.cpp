#include "boardwidget.hpp"
#include "gamemaster.hpp"

const int XX = 800;
const int YY = 900;

using namespace genv;

int main() {
    gout.open(XX, YY);
    BoardWidget board_widget(0, 0, XX, YY);
    GameMaster game_master(board_widget, XX);

    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        game_master.handle_event(ev);
        board_widget.draw(game_master.get_current_color());
        game_master.show_winner();
    }
    return 0;
}
