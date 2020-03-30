//
// Created by User on 2020-03-30.
//

#include "pixel.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using ZMMALE001::pixel;

pixel::pixel(): red(0),green(0),blue(0){}
pixel::pixel(float c): red(c),green(c),blue(c){}
pixel::pixel(float _r, float _g, float _b){
    grey = 0.21 * _r + 0.72 * _g + 0.07 * _b;
    pixelArray[0]=_r;
    pixelArray[1]=_g;
    pixelArray[2]=_b;
}