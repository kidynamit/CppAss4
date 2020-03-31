//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGEPROCESSING_H
#define ASSIGNMENT_4_IMAGEPROCESSING_H

#include <vector>
#include <string>

namespace ZMMALE001{
    class ImageProcessing{

        struct pixel : public std::error_code {
        private:
            float red;
            float green;
            float blue;
            float grey;
        public:
            float getRed() const {
                return red;
            }

            float getGreen() const {
                return green;
            }

            float getBlue() const {
                return blue;
            }

            float getGrey() const {
                return grey;
            }

        public:
            pixel();
            pixel(float _r, float _g, float _b){
                red=_r;
                green=_g;
                blue=_b;
                grey = 0.21 * _r + 0.72 * _g + 0.07 * _b;
            }
            ImageProcessing:: pixel&operator=(pixel *rhs);

        };
    private:
        int rows,cols,intensity;
        std::vector<unsigned char **> slices;
    public:
        ImageProcessing(char *baseName);
        ~ImageProcessing();
        ImageProcessing(const ImageProcessing &oldImage);
        //ImageProcessing&operator=(const pixel &rhs);

        bool readImages(std::string baseName);
    };
}

#endif //ASSIGNMENT_4_IMAGEPROCESSING_H
