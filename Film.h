//
// Created by Liyf on 2017/5/19.
//

#ifndef RENDER_FILM_H
#define RENDER_FILM_H

#include "Color.h"

class Film {
    int w, h;
public:
    Color * pixes;
    Film(int w, int h): w(w), h(h)
    {
        pixes = new Color [w * h];
    }

    virtual ~Film(){
        if(pixes)
            delete [] pixes;
    }

    void writePix(int x, int y, const Color &pix) {
        pixes[(h - y - 1) * w + x] = pixes[(h - y - 1) * w + x] + pix.normalize() * 0.25;
    }
};


#endif //RENDER_FILM_H
