//
// Created by User on 2020-04-07.
//

#include "centroid.h"
#include <cstdlib>
#include <cmath>
#include "ImageProcessing.h"

using ZMMALE001::Image;
using ZMMALE001::ImageProcessing;

centroid::centroid(const int binSize,int i, vector<int> image) {

    clusterNumber =i;

//    int num_bins = ceil(255 / binSize);
//    for (int i = 0; i < num_bins; ++i) {
//        double v = rand()%600;
//        centroid_hist_stored.push_back(v);
//
//    }
    centroid_hist_stored=image;


}

int centroid::getClusterNumber() const {
    return clusterNumber;
}

centroid::centroid() {

}
