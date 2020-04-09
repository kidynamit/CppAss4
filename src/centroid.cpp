//
// Created by User on 2020-04-07.
//

#include "centroid.h"
#include <cstdlib>
#include <cmath>
using ZMMALE001::Image;

centroid::centroid(const int binSize,int i) {

    clusterNumber =i;

    int num_bins = ceil(255 / binSize);
    for (int i = 0; i < num_bins; ++i) {
        double v = rand()%100;
        centroid_hist_stored.push_back(v);

    }

}

int centroid::getClusterNumber() const {
    return clusterNumber;
}
