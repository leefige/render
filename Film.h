//
// Created by Liyf on 2017/5/19.
//

#ifndef RENDER_FILM_H
#define RENDER_FILM_H

#include "Color.h"

class Film {
    int w, h;
public:
    Color * c;
    Film(int w, int h): w(w), h(h)
    {
        c = new Color [w * h];
    }

    virtual ~Film(){
        if(c)
            delete [] c;
    }
};


#endif //RENDER_FILM_H
