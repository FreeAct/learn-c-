#pragma once
#ifndef __COMPLEX__
#define __COMPLEX__

class complex {
public:
    std::string idx;
    complex() :re(0), im(0),idx("number") {};
    complex(int _re, int _im,std::string _idx) :re(_re), im(_im),idx(_idx) {};
    const complex operator+(const complex& b)const {
        complex tmp;
        tmp.im = b.im + im;
    };
    complex& operator+=(const complex &Z) {
        re += Z.re;
        im += Z.im;
        idx += Z.idx;
        return *this;
    }

private:
    int re;
    int im;
};
size_t hasher(const complex& a) {
    std::hash<std::string>h;
    return h(a.idx);
}
bool eqon(const complex& a, const complex& b) {
    return a.idx == b.idx;
}
std::ostream& operator<<(std::ostream& os, const complex& Z) {
    os << Z.idx;
    return os;
}

#endif // !__COMPLEX__//
