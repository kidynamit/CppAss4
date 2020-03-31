//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGEPROCESSING_H
#define ASSIGNMENT_4_IMAGEPROCESSING_H

#include <vector>
#include <string>

namespace ZMMALE001{
    class ImageProcessing{

        struct pixel {
        private:
            float red;
            float green;
            float blue;
            float grey;
        public:
            pixel(float _r, float _g, float _b){
                grey = 0.21 * _r + 0.72 * _g + 0.07 * _b;
                red=_r;
                green=_g;
                blue=_b;
            }
        };
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
