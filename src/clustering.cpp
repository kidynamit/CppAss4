//
// Created by User on 2020-04-06.
//
#include <vector>
#include <cmath>
#include "Image.h"
#include "clustering.h"
#include "ImageProcessing.h"

using ZMMALE001::clustering;
using ZMMALE001:: Image;
using ZMMALE001:: ImageProcessing;
using ZMMALE001::RGB;

double clustering::vectors_distance(const std::vector<int> &a, const std::vector<int> &b) {

    double total=0;
    for (int i = 0; i <a.size(); ++i) {
        total+=pow(a[i]-b[i],2);
    }
    return sqrt(total);
}

void clustering::cluster(int numClusters, int binSize, bool colour) {

}

ZMMALE001::clustering::clustering(int numClusters,int binSize,vector<Image> &images) {
    for (int i = 0; i < numClusters; ++i) {
        centroid temp = centroid(binSize,i);
        clusters.push_back(temp);
    }

    kmean(images);
}

void ZMMALE001::clustering::kmean(vector<Image> &images) {

//     ## K-Means Clustering
//     1. Choose the number of clusters(K) and obtain the data points
//     2. Place the centroids c_1, c_2, ..... c_k randomly
//     3. Repeat steps 4 and 5 until convergence or until the end of a fixed number of iterations
//     4. for each data point x_i:
//            - find the nearest centroid(c_1, c_2 .. c_k)
//            - assign the point to that cluster
//     5. for each cluster j = 1..k
//            - new centroid = mean of all points assigned to that cluster
//     6. End



    int not_yet = 10;

    while(not_yet)
    {

        not_yet--;

        // ----- step 4

        centroid temp_cluster;
        for (int i=0;i<images.size();i++){
            std::cout<<images.at(i).hist_grey_bins_count[0];
            temp_cluster = clusters.at(0);

            for (centroid clus : clusters) {

                double vector_new_clus_to_img = vectors_distance(clus.centroid_hist_stored, images.at(i).hist_grey_bins_count);
                double vector_curr_clus_to_img = vectors_distance(temp_cluster.centroid_hist_stored, images.at(i).hist_grey_bins_count);

                if(vector_new_clus_to_img > vector_curr_clus_to_img){
                    continue;
                }else{
                    temp_cluster=clus;
                }
            }
            images.at(i).setClusterValue(temp_cluster.getClusterNumber());
        }


        vector<int> sum;

        std::fill(sum.begin(), sum.end(), 0);
        int count_images_in_cluster = 0;

        // ----- step 5

        for (centroid &c : clusters)
        {
            // find all images with centroid = c
            for (int i=0;i<images.size();i++){

                if (images.at(i).getClusterValue() == c.getClusterNumber()){
                    // this image is part of this cluster
                    //sum=vectors_sum(sum, img.hist_grey_bins_count);
                    sum=vectors_sum(sum,vectors_sum(sum, images.at(i).hist_grey_bins_count));
                    count_images_in_cluster++;
                }
            }
            vector<int> avg = vector_divide(sum,count_images_in_cluster); // divide vector by the count.

            // TODO
            // if (c == avg){
            //     not_yet = false;
            // }

            c.centroid_hist_stored = avg;
        } // end of for loop to recalculate the centroids.

    } // end of k-means iteration



}

vector<int> clustering::vectors_sum(const std::vector<int> &a, const std::vector<int> &b) {

    vector<int> sum(a.size(), 0);

    for (int i = 0; i <a.size(); ++i) {
        sum[i] = a[i] + b[i];
    }

    return sum;
}

vector<int> clustering::vector_divide(const std::vector<int> &a, int b) {

    vector<int> div(a.size(), 0);

    for (int i = 0; i <a.size(); ++i) {
        div[i] = int(a[i] / b);
    }

    return div;
}

clustering &ZMMALE001::clustering::operator+=(const vector<Image> &rhs) {
    return *this;
}


