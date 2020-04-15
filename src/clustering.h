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
        friend class ImageProcessing;

    private:
        std::vector<centroid> clusters;

    public:
        clustering(int,int,bool,vector<Image>&);

        void cluster(int numClusters, int binSize, bool colour);

        double vectors_distance(const std::vector<int> &a, const std::vector<int> &b);

        void kmean(bool,vector<Image>&);

        vector<int> vectors_sum(const vector<int> &a, const vector<int> &b);

        vector<int> vector_divide(const vector<int> &a, int b);
        clustering &operator+=(const vector<Image>& rhs);

        void newClusterMean(bool,vector<Image> &images);
    };
}
#endif //ASSIGNMENT_4_CLUSTERING_H
