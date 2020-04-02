//
// Created by tchemvur on 4/1/2020.
//

#include <iostream>
#include <fstream>
#include "ImageProcessing.h"
#include "Image.h"
#include <vector>
#include <cstring>
#include <experimental/filesystem>

//namespace fs = std::filesystem;
using ZMMALE001::ImageProcessing;
using ZMMALE001::Image;
using ZMMALE001::RGB;


void Image::addPixel (RGB pix){
    pixels.push_back(pix);
}

void Image::processHist(Image &image, int bin_size){
    // create the histogram
    //int lower = 0, upper = bin_size; // lower <= x < upper

    // TODO determine the bounds for the bin size
    // TODO create all empty bins
    // TODO iterate through the pixels and add each pixel to it's respective bin.

}

unsigned int ZMMALE001::Image::getHeight() {
    return height;
}

unsigned int ZMMALE001::Image::getWidth() {
    return width;
}

RGB &ZMMALE001::Image::get(unsigned int a, unsigned int b) {
    return pixels[(b*width)+a];
}

ZMMALE001::Image::Image() {
    width = 0;
    height = 0;
}

ZMMALE001::Image::Image(int w, int h) {
    width = w ;
    height = h;
}


