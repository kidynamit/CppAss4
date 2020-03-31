//
// Created by User on 2020-03-27.
//
#include <iostream>
#include <fstream>
#include "ImageProcessing.h"
#include <vector>
#include <cstring>

using ZMMALE001::ImageProcessing;

ImageProcessing::ImageProcessing(char *baseName){
    slices = std::vector<unsigned char **>(0);
    std::cout<<"constructor\n";
    std::string temp = std::string(baseName);
    std::cout << "reading image\n";
    std::string header_fname = "Gradient_Numbers_PPMS/" + temp + ".ppm";

    std::ifstream header_fs;
    header_fs >> header_fname;
    if(strcmp(header_fname.c_str(),"P6")!=0) throw ("Can't read input file");
    int r,c,i;
    header_fs>> r;
    header_fs>> c;
    header_fs>> i;
    header_fs.ignore(256,'\n');
    header_fs.close();
    rows=r;
    cols=c;
    intensity=i;
   this->readImages(temp);

}

ImageProcessing::~ImageProcessing() {
    rows = 0;
    cols= 0;
    intensity =0;

    for (int i = 0; i < slices.size(); ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < rows; ++k) {
                slices[i][j][k]=0;
            }
            delete[] slices[i][j];
        }
        delete[] slices[i];
    }
    slices.clear();
}

bool ImageProcessing::readImages(std::string baseName) {


    unsigned char pix[3];
    std::string header_fname = "Gradient_Numbers_PPMS/" + baseName + ".ppm";
    std::ifstream image_fs(header_fname, std::ios::binary);

    pixel** image = (pixel**) new pixel** [this->cols];
    for (int i = 0; i < cols; ++i) {
        image[i] = (pixel*) new pixel*[rows];
        for (int j = 0; j < rows; ++j) {
            image_fs.read(reinterpret_cast<char *>(pix), 3);
            char red = pix[0];
            char green =pix[1];
            char blue = pix[2];
            image[i][j] = pixel(red, green, blue);
        }
    }
    image_fs.close();
//    std::cout << "done\n";
    return true;
}

