//
// Created by Liyf on 2017/6/14.
//

#ifndef RENDER_COLOR_H
#define RENDER_COLOR_H

#define MAX_COLOR 255

class Color {
public:
    double r, g, b;

    Color(): r(0), g(0), b(0) {}
    Color(double r, double g, double b): r(r), g(g), b(b) {}

    double getMaxChannel() {
        if (r > g) {
            if (r > b)
                return r;
            return b;
        }
        else if (g > b)
            return g;
        else
            return b;
    }

    Color operator* (double c) const {
        return Color(r * c, g * c, b * c);
    }

    Color operator+ (const Color &c) const {
        return Color(r + c.r, g + c.g, b + c.b);
    }

    Color& operator+= (const Color &c) {
        r += c.r;
        g += c.g;
        b += c.b;
        return *this;
    }

    Color normalize() const {
        double _r = r > MAX_COLOR ? MAX_COLOR : r;
        double _g = g > MAX_COLOR ? MAX_COLOR : g;
        double _b = b > MAX_COLOR ? MAX_COLOR : b;
        return Color(_r, _g, _b);
    }

    Color mix(const Color &c) const {
        return Color(r * c.r / MAX_COLOR,
                     g * c.g / MAX_COLOR,
                     b * c.b / MAX_COLOR);
    }
};

#endif //RENDER_COLOR_H
