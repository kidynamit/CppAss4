//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGEPROCESSING_H
#define ASSIGNMENT_4_IMAGEPROCESSING_H

#include <vector>
#include <string>
#include "Image.h"
#include "clustering.h"
#include <iostream>

using std::string;
using std::vector;

//using ZMMALE001::clustering;
namespace ZMMALE001{
    class ImageProcessing {

friend class clustering;
friend class centroid;

    private:
        string baseName;
        int numClusters, binSize;
        bool colour;
        vector<Image> images;
        Image readImage(string baseName, string fname);
        bool readImages(string baseName);

    public:
        ImageProcessing();
        ImageProcessing(string, int, int, bool);

        void processAllHist();
        void classify(string output);
//        template <typename  T>
//        std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
//
//        }


    };
}

#endif //ASSIGNMENT_4_IMAGEPROCESSING_H
