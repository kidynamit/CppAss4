//
// Created by User on 2020-03-27.
//
#include <iostream>
#include <fstream>
#include "ImageProcessing.h"
#include <vector>
#include <cstring>

using ZMMALE001::ImageProcessing;

ImageProcessing::ImageProcessing() {
    width=0;
    height=0;
}

ImageProcessing::ImageProcessing(char *baseName){
    ImageProcessing img;
    //slices = std::vector<unsigned char **>(0);
    std::cout<<"constructor\n";
    std::string temp = std::string(baseName);
    std::cout << "reading image\n";
    //std::string header_fname = "Gradient_Numbers_PPMS/" + temp + ".ppm";
    std::string header_fname = "Gradient_Numbers_PPMS/zero_5.ppm";

    std::ifstream header_fs(header_fname.c_str());
    //header_fs >> header_fname;
    //if(strcmp(header_fname.c_str(),"P6")!=0) throw ("Can't read input file");
    std::string magic_number,r,c,i;
    header_fs>> magic_number;
    if(magic_number!="P6") {
        header_fs.close();
    }
    header_fs>> r;
    header_fs>> c;
    header_fs>> i;
    img.setRows(atoi(r.c_str()));
    img.setCols(atoi(c.c_str()));
    //rows =atoi(r.c_str());
    //cols =atoi(c.c_str());
    pixels.clear();
    header_fs.ignore(,'\n');
    RGB tmp;
    char _r;
    char _g;
    char _b;
    int size= img.getWidth()*img.getHeight();
    for (unsigned int j = 0; j < size; ++j) {
        header_fs>> _r;
        header_fs>> _g;
        header_fs>> _b;
        tmp.red=char(_r);
        tmp.green=char(_g);
        tmp.blue=char(_b);
        tmp.grey=0.21 * tmp.red + 0.72 * tmp.green + 0.07 * tmp.blue;
        img.pixels.push_back(tmp);
        std::cout<<tmp.red;
    }
    header_fs.close();
    int p=0;
    //unsigned int size = img.getRows() * img.getCols();
    for (unsigned int b = 0; b < img.getHeight(); b++) {
        for (unsigned int a = 0; a < img.getWidth(); a++) {
            if(p==32){
                std::cout<<std::endl;
                p=0;
            } else {
                p++;
                RGB &ref_colour = img.get(a, b);
                //std::cout << "RGB {" << (int) ref_colour.red << ", " << (int) ref_colour.green << ", "<< (int) ref_colour.blue << "}";
               std::cout<< (int)ref_colour.grey<<" ";
            }
//           RGB& ref_colour = img.get(a, b);
//           std::cout << "RGB {" << (int)ref_colour.red << ", " << (int)ref_colour.green << ", " << (int)ref_colour.blue << "}" << std::endl;
        }
    }

}

ImageProcessing:: RGB& ImageProcessing::get(unsigned int a, unsigned int b) {
    return pixels[(b * width) + a];
}

unsigned int ZMMALE001::ImageProcessing::getWidth(){
    return width;
}

unsigned int ZMMALE001::ImageProcessing::getHeight(){
    return height;
}

void ZMMALE001::ImageProcessing::setRows(unsigned int width) {
    ImageProcessing::width = width;
}

void ZMMALE001::ImageProcessing::setCols(unsigned int height) {
    ImageProcessing::height = height;
}

//ImageProcessing::~ImageProcessing() {
//    rows = 0;
//    cols= 0;
//    intensity =0;
//
//    for (int i = 0; i < slices.size(); ++i) {
//        for (int j = 0; j < cols; ++j) {
//            for (int k = 0; k < rows; ++k) {
//                slices[i][j][k]=0;
//            }
//            delete[] slices[i][j];
//        }
//        delete[] slices[i];
//    }
//    slices.clear();
//}
//
//bool ImageProcessing::readImages(std::string baseName) {
//
//
//    unsigned char pix[3];
//   // std::string header_fname = "Gradient_Numbers_PPMS/" + baseName + ".ppm";
//    std::string header_fname = "Gradient_Numbers_PPMS/eight_1.ppm";
//    std::ifstream image_fs(header_fname, std::ios::binary);
//
//    pixel** image = (pixel**) new pixel** [this->cols];
//    for (int i = 0; i < cols; ++i) {
//        image[i] = (pixel*) new pixel*[rows];
//        for (int j = 0; j < rows; ++j) {
//            image_fs.read(reinterpret_cast<char *>(pix), 3);
//            long red = pix[0];
//            long green =pix[1];
//            long blue = pix[2];
//           //auto *p = new pixel(red, green, blue);
//            image[i][j] = pixel(red, green, blue);
//
//        }
//    }
//    for(int i=0; i<cols; i++)
//    {
//        for(int j=0; j<rows; j++)
//        {
//            std::cout<<"["<<image[i][j].getRed()<<","<<image[i][j].getGreen()<<","<<image[i][j].getBlue()<<"]"<<" ";
//        }
//        std::cout<<"\n";
//    }
//
//    image_fs.close();
//
//    return true;
//}

