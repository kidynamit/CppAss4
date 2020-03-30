//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGEPROCESSING_H
#define ASSIGNMENT_4_IMAGEPROCESSING_H

#include <vector>
#include <string>

namespace ZMMALE001{
    class ImageProcessing{
    private:
        int rows,cols,intensity;
        std::vector<unsigned char **> slices;
    public:
        ImageProcessing(char *baseName);
        ~ImageProcessing();
        ImageProcessing(const ImageProcessing &oldImage);

        bool readImages(std::string baseName);
    };
}

#endif //ASSIGNMENT_4_IMAGEPROCESSING_H
