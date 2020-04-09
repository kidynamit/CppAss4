//
// Created by User on 2020-04-06.
//

#ifndef ASSIGNMENT_4_CLUSTERING_H
#define ASSIGNMENT_4_CLUSTERING_H

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>
#include <vector>
#include "centroid.h"

namespace ZMMALE001 {
    class clustering {

    private:
        std::vector<centroid> clusters;

    public:
        clustering(int,int,vector<Image>);

        void cluster(int numClusters, int binSize, bool colour);

        double vectors_distance(const std::vector<int> &a, const std::vector<int> &b);

        void kmean(vector<Image>*);
    };
}
#endif //ASSIGNMENT_4_CLUSTERING_H
