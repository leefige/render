//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_INT4_H
#define RENDER_INT4_H

class int4 {
public:
    int x0, x1, x2, x3;
    int4()
    {
        x0 = 0;
        x1 = 0;
        x2 = 0;
        x3 = 0;
    }

    int4(int _x0, int _x1, int _x2, int _x3)
    {
        x0 = _x0;
        x1 = _x1;
        x2 = _x2;
        x3 = _x3;
    }

    virtual ~int4(){}
};

#endif //RENDER_INT4_H
