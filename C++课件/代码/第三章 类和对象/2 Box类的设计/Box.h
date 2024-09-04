//
// Created by Administrator on 2021/7/25.
//

#ifndef CODE_BOX_H
#define CODE_BOX_H
//声明Box类
class Box
{
private:
    //属性
    int _len = 10;
    int _w = 10;
    int _h = 10;

    int _s;
    int _v;
public:
    //声明方法
    bool set_len(int len);
    bool set_w(int w);
    bool set_h(int h);

    int get_len();
    int get_w();
    int get_h();

    int get_s();
    int get_v();
};

Box box;

#endif //CODE_BOX_H
