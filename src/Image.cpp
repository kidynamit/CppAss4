//
// Created by User on 2020-03-27.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include "ImageProcessing.h"
#include "Image.h"

using ZMMALE001::ImageProcessing;
using ZMMALE001::Image;
using ZMMALE001::RGB;


void Image::addPixel (RGB pix){
    pixels.push_back(pix);
}

void Image::processHist(int bin_size){
    // create the histogram
    //int lower = 0, upper = bin_size; // lower <= x < upper

    // TODO determine the bounds for the bin size
    // TODO create all empty bins
    // TODO iterate through the pixels and add each pixel to it's respective bin.

    int num_bins = ceil(255/bin_size);

//    for (int i = 0; i < num_bins+1; ++i)
//    {
//        std::vector<RGB> v;
//        hist_grey_bins.push_back(v);
//    }
    for (int i = 0; i < num_bins+1; ++i)
    {
        std::vector<int> v;
        hist_grey_bins.push_back(v);
    }


    for (RGB &pix : pixels){
        // grey scale only
        int upper = bin_size;

        // bin_index = index of the bin in the histogram vector
        for (int bin_index = 0; bin_index < num_bins; ++bin_index)
        {
            if (pix.grey > upper) {
                upper+=bin_size;
                continue;
            } else {
                int greyValue=pix.grey;
                hist_grey_bins[bin_index].push_back(greyValue);
                break;
            }
        }// done with one pixel

    } // done with all pixels


    // print the hist
    for (int pixel_bin = 0; pixel_bin < hist_grey_bins.size(); ++pixel_bin)
    {
        int amount =(bin_size + (pixel_bin*bin_size));
        std::cout << "bin number = " << pixel_bin << " (" << pixel_bin*bin_size << ","<< amount << ") >> ";
        for (int p : hist_grey_bins[pixel_bin])
        {
            std::cout << p << " ";
        }
      //  std::cout<< hist_grey_bins[pixel_bin].size();
        std::cout << std::endl;
    }
    std::cout << std::endl << " ++++++ " << std::endl << std::endl;

}

unsigned int &ZMMALE001::Image::getHeight() {
    return height;
}

unsigned int &ZMMALE001::Image::getWidth() {
    return width;
}

RGB &ZMMALE001::Image::get(unsigned int x, unsigned int y) {
    return pixels[(y*width)+x];
}

ZMMALE001::Image::Image() {
    width = 0;
    height = 0;
}

ZMMALE001::Image::Image(int w, int h, std::string fname) {
    width = w ;
    height = h;
    filename=fname;
}

const string &ZMMALE001::Image::getFilename() const {
    return filename;
}


