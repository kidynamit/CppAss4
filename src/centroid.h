//
// Created by User on 2020-04-07.
//

#ifndef ASSIGNMENT_4_CENTROID_H
#define ASSIGNMENT_4_CENTROID_H

#include "Image.h"
#include <vector>

class centroid{

private:
    int clusterNumber;
    int sizeForSeeding;
    int imageNumberSeeding;
public:
    int getImageNumberSeeding() const;

    void setImageNumberSeeding(int imageNumberSeeding);

public:
    centroid();
    centroid(const int,int,vector<int>);
    int getClusterNumber() const;
    std::vector<int> centroid_hist_stored;

    int getSizeForSeeding() const;
    void setSizeForSeeding(int sizeForSeeding);
};

#endif //ASSIGNMENT_4_CENTROID_H
