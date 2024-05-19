#ifndef BEADWIDGET_HPP_INCLUDED
#define BEADWIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include <string>

class BeadWidget {
protected:
    int _x, _y, _w, _h;
public:
    BeadWidget(int x, int y, int sx, int sy);
    virtual ~BeadWidget() {}
    virtual std::string get_value() const = 0;
    virtual void draw(bool next) const = 0;
    virtual bool is_selected(int mouse_x, int mouse_y) const {
        return (mouse_x >= _x && mouse_x <= _x + _w && mouse_y >= _y && mouse_y <= _y + _h);
    }
    virtual void handle_event(const genv::event &ev) = 0;
};

#endif // BEADWIDGET_HPP_INCLUDED
