#ifndef HELPMATH_HPP
#define HELPMATH_HPP

int map(int v, float min0, float max0, float min1, float max1) {
    if(v < min0)
        v = min0;
    else if(v > max0) 
        v = max0;
    return min1 + (max1 - min1) * ((v - min0) / (max0 - min0));
}

uint16_t map16(int v, float min0, float max0, uint16_t min1, uint16_t max1) {
    if(v < min0)
        v = min0;
    else if(v > max0) 
        v = max0;
    return min1 + (max1 - min1) * ((v - min0) / (max0 - min0));
}

#endif // HELPMATH_HPP