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
    std::vector<double> centroid_hist_stored;

public:
    centroid();
    centroid(const int,int);
    int getClusterNumber() const;

};

#endif //ASSIGNMENT_4_CENTROID_H
