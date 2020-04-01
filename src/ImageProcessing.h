//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGEPROCESSING_H
#define ASSIGNMENT_4_IMAGEPROCESSING_H

#include <vector>
#include <string>

namespace ZMMALE001{
    class ImageProcessing{

        struct RGB {

            unsigned char red;
            unsigned char green;
            unsigned char blue;
            unsigned char grey;

            RGB(): red(0),blue(0),green(0),grey(0){};
//            pixel(long _r, long _g, long _b){
//                red=_r;
//                green=_g;
//                blue=_b;
//                grey = 0.21 * _r + 0.72 * _g + 0.07 * _b;
//            }
//            ImageProcessing:: pixel&operator=(pixel *rhs);

        };
    private:
        unsigned int width,height,intensity;
        std::vector<RGB> pixels;
    public:
        void setRows(unsigned int width);

        void setCols(unsigned int height);

        ImageProcessing();
        ImageProcessing(char *baseName);
        //~ImageProcessing();
        //ImageProcessing(const ImageProcessing &oldImage);
        //ImageProcessing&operator=(const pixel &rhs);
        RGB& get(unsigned int a, unsigned int b);
        unsigned int getWidth();
        unsigned int getHeight();

        bool readImages(std::string baseName);
    };
}

#endif //ASSIGNMENT_4_IMAGEPROCESSING_H
