//
// Created by User on 2020-03-27.
//
#include <iostream>
#include <fstream>
#include "ImageProcessing.h"
#include "Image.h"
#include <vector>
#include <experimental/filesystem>
#include <iomanip>

namespace fs = std::experimental::filesystem;
using ZMMALE001::ImageProcessing;
using ZMMALE001::Image;
using ZMMALE001::RGB;
using ZMMALE001::clustering;

ImageProcessing::ImageProcessing(string base, int clusters, int bin , bool colour) : baseName(base), numClusters(clusters), binSize(bin), colour(colour) {

    // load all the images from <basename> folder and add to this.images
    readImages(base);

}

// read all images from a given folder
bool ImageProcessing::readImages(std::string baseName) {
    std::cout<<"start reading in images"<<std::endl;
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
                Image img_ = readImage( baseName, filenameStr);
                images.push_back( img_ );
                //processHist(img_);
            }
            else
                // ignore
                continue;
    }
}

// read a single image when given a filepath and return an image variable
Image ImageProcessing::readImage(string baseName,string fname){

    std::cout<<"read in new image :"<< fname << std::endl;

    // read header
    std::ifstream header_fs(baseName+"/"+fname);
    std::string magic_number,r,c,i;
    header_fs >> magic_number;
    //std::cout<<magic_number;
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
    Image temp(w,h,fname);

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


    for (unsigned int y = 0; y < temp.getHeight(); ++y) {
        for (unsigned int x = 0; x < temp.getWidth(); ++x) {
                RGB &ref_colour = temp.get(x, y);
                //std::cout << "RGB {" <<std::setw (3) <<(int) ref_colour.red << ", " <<std::setw (3) << (int) ref_colour.green << ", "<<std::setw (3) << (int) ref_colour.blue << "}";
                //std::cout<< std::setw (3) << (int)ref_colour.grey<<" ";
                if((int)ref_colour.grey>100)
                {
                    std::cout<< std::setw (3) << (int)ref_colour.grey;
                } else{
                    std::cout<<std::setw(3)<<" ";
                }
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return temp;// todo why return this

}

void ZMMALE001::ImageProcessing::processAllHist() {
//    for(Image mage: images){
//        std::cout<<"Image : "<< mage.getFilename()<<std::endl;
//        mage.processHist(binSize,colour);
//        std::cout<<mage.hist_grey_bins_count[0];
//        std::cout<< std::endl;
//
//    }
    for(int i=0;i<images.size();i++){
        std::cout<<"Image : "<< images.at(i).getFilename()<<std::endl;
        images.at(i).processHist(binSize,colour);
        //std::cout<<images.at(i).hist_grey_bins_count[0];
        std::cout<< std::endl;

    }

    //std::cout<<images.at(0).hist_grey_bins_count[0];

}

void ZMMALE001::ImageProcessing::classify(string output) {

    clustering(numClusters,binSize,colour,images);
    if(output=="noOutputLoctation")
    for (int j = 0; j < numClusters; ++j) {
        std::cout<<"Cluster "<< j <<": ";
        for (Image i: images){
            if(i.getClusterValue()==j) {
                std::cout<< i.getFilename()+", ";
                //std::cout <<i.getClusterValue();
            }
        }
        std::cout<<std::endl;
    }
    else{
        //::ofstream ofs(output);
        //ofs.write()
        std::cout<<"yes";
    }
}
//template <typename T>
//std::ostream &operator<<(std::ostream &os, const vector<Image>& images) {
//    std::ofstream ofs ();
//    return os;
//}


