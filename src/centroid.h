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


public:
    centroid();
    centroid(const int,int);
    int getClusterNumber() const;
    std::vector<int> centroid_hist_stored;
};

#endif //ASSIGNMENT_4_CENTROID_H
