//
// Created by User on 2020-03-27.
//
#include <iostream>
#include <fstream>
#include "ImageProcessing.h"
#include "Image.h"
#include <vector>
#include <cstring>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
using ZMMALE001::ImageProcessing;
using ZMMALE001::Image;
using ZMMALE001::RGB;

ImageProcessing::ImageProcessing(string base, int clusters, int bin) : baseName(base), numClusters(clusters), binSize(bin) {

    // load all the images from <basename> folder and add to this.images
    readImages(base);

}

// read all images from a given folder
bool ImageProcessing::readImages(std::string baseName) {
    // https://www.bfilipek.com/2019/04/dir-iterate.html#using-c17
    // iterate through all images in basename folder
    for (const auto& entry : fs::directory_iterator(baseName)) {
            const auto filenameStr = entry.path().filename().string();
            if (is_directory(entry)) {
                // ignore
                continue;
            }
            else if (is_regular_file(entry)) {
                // PPM file. read it  in as an image and add to this.images
                Image img_ = readImage(string(filenameStr));
                images.push_back( img_ );
                processHist(img_);
            }
            else
                // ignore
                continue;
    }
}

// read a single image when given a filepath and return an image variable
Image ImageProcessing::readImage(string fname){

    // read header
    std::ifstream header_fs(fname.c_str());
    std::string magic_number,r,c,i;
    header_fs>> magic_number;
    if(magic_number!="P6") {
        header_fs.close();
        std::cerr << "Wrong image format";
        exit(1);
    }
    header_fs>> r;
    header_fs>> c;
    header_fs>> i;
    int h = (atoi(r.c_str()));
    int w = (atoi(c.c_str()));

    // create the image variable
    Image temp(w,h);

    //header_fs.ignore(,'\n');

    RGB tmp_pix;
    char _r;
    char _g;
    char _b;
    int size = h*w;
    for (unsigned int j = 0; j < size; ++j) {
        header_fs>> _r;
        header_fs>> _g;
        header_fs>> _b;
        tmp_pix.red=char(_r);
        tmp_pix.green=char(_g);
        tmp_pix.blue=char(_b);
        tmp_pix.grey= (0.21 * tmp_pix.red + 0.72 * tmp_pix.green + 0.07 * tmp_pix.blue);
        temp.addPixel(tmp_pix);
    }
    header_fs.close();

    // DEBUG CODE

    int p=0;
    //unsigned int size = img.getRows() * img.getCols();
    for (unsigned int b = 0; b < temp.getHeight(); b++) {
        for (unsigned int a = 0; a < temp.getWidth(); a++) {
            if(p==32){
                std::cout<<std::endl;
                p=0;
            } else {
                p++;
                RGB &ref_colour = temp.get(a, b);
                //std::cout << "RGB {" << (int) ref_colour.red << ", " << (int) ref_colour.green << ", "<< (int) ref_colour.blue << "}";
                std::cout<< (int)ref_colour.grey<<" ";
            }
//           RGB& ref_colour = img.get(a, b);
//           std::cout << "RGB {" << (int)ref_colour.red << ", " << (int)ref_colour.green << ", " << (int)ref_colour.blue << "}" << std::endl;
        }
    }

    return temp;

}

void ImageProcessing::printHist() {

    // process the histogram



}

void ZMMALE001::ImageProcessing::processHist(Image image) {
    //todo

}
