//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGEPROCESSING_H
#define ASSIGNMENT_4_IMAGEPROCESSING_H

#include <vector>
#include <string>
#include "Image.h"

using std::string;
using std::vector;

namespace ZMMALE001{
    class ImageProcessing {

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
        void printHist();



    };
}

#endif //ASSIGNMENT_4_IMAGEPROCESSING_H
