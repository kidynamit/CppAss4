//
// Created by User on 2020-03-27.
//

#ifndef ASSIGNMENT_4_IMAGE_H
#define ASSIGNMENT_4_IMAGE_H

#include <vector>
#include <string>

using std::vector;

namespace ZMMALE001{

    struct RGB {

        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char grey;

        RGB(): red(0),blue(0),green(0),grey(0){};

    };

    class Image{
    private:
        unsigned int width,height;
        vector<RGB> pixels;
        //vector< vector<Images> > bins;
    public:

        Image();
        Image(int w, int h);

        void addPixel(RGB pix);
        void processHist(Image &image, int bin_size);


        unsigned int getHeight();

        unsigned int getWidth();

        RGB &get(unsigned int a, unsigned int b);
    };
}
#endif //ASSIGNMENT_4_IMAGE_H