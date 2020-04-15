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

namespace ZMMALE001{
    class ImageProcessing {

friend class clustering;

    private:
        string baseName;
        int numClusters, binSize;
    public:
        int getNumClusters() const;

    private:
        bool colour;
        vector<Image> images;
        Image readImage(string baseName, string fname);
        bool readImages(string baseName);

    public:
        ImageProcessing();
        ImageProcessing(string, int, int, bool);

        void processAllHist();
        void classify(string output);
       friend std::ostream& operator<<(std::ostream& os, const ImageProcessing& kt);
//       vector<Image> get_buffer() const {
//           return images;
//       }
   };
}

#endif //ASSIGNMENT_4_IMAGEPROCESSING_H
