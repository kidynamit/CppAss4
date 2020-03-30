//
// Created by User on 2020-03-30.
//

#ifndef ASSIGNMENT_4_PIXEL_H
#define ASSIGNMENT_4_PIXEL_H
namespace ZMMALE001 {
    class pixel {
    private:
        float red;
        float green;
        float blue;
        float pixelArray[3];
    public:
        pixel();
        pixel(float c);
        pixel(float _r, float _g, float _b);
    };
}

#endif //ASSIGNMENT_4_PIXEL_H
