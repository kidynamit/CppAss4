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

ZMMALE001::clustering::clustering(int numClusters,int binSize,bool colour,vector<Image> &images) {

    if (colour==false) {
        vector<int> numbersUsed;
        int count=0;
        while (count <= numClusters) {
            int r = rand() % 100;
            if (std::find(numbersUsed.begin(), numbersUsed.end(), r) != numbersUsed.end()) {
                /* numberUsed contains r */
            } else {
                /* numberUsed does not contain r */
                numbersUsed.push_back(r);
                vector<int> image = images.at(r).hist_grey_bins_count;
                centroid temp = centroid(binSize, count, image);
                clusters.push_back(temp);
                count++;
            }
        }
    } else{
        vector<int> numbersUsed;
        int count=0;
        //int r=5;
        while (count < numClusters) {
            int r = rand() % 100;

            if (std::find(numbersUsed.begin(), numbersUsed.end(), r) != numbersUsed.end()) {
                /* numberUsed contains r */
            } else {
                /* numberUsed does not contain r */
                numbersUsed.push_back(r);
                vector<int> image = images.at(r).hist_RBG_counts;
                centroid temp = centroid(binSize, count, image);
                clusters.push_back(temp);
                count++;
               //r =r+10;
            }
        }
    }

    kmean(colour,images);
}

void ZMMALE001::clustering::kmean(bool colour,vector<Image> &images) {

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
if(colour==false) {
    int not_yet = 10;

    while (not_yet) {

        not_yet--;

        // ----- step 4

        centroid temp_cluster;
        for (int i = 0; i < images.size(); i++) {
            temp_cluster = clusters.at(0);

            for (int j = 0; j < clusters.size(); j++) {

                double vector_new_clus_to_img = vectors_distance(clusters.at(j).centroid_hist_stored,
                                                                 images.at(i).hist_grey_bins_count);
                double vector_curr_clus_to_img = vectors_distance(temp_cluster.centroid_hist_stored,
                                                                  images.at(i).hist_grey_bins_count);

                if (vector_new_clus_to_img > vector_curr_clus_to_img) {
                    continue;
                } else {
                    temp_cluster = clusters.at(j);
                }
            }
            images.at(i).setClusterValue(temp_cluster.getClusterNumber());
            newClusterMean(colour,images);
        }

    } // end of k-means iteration
} else{
    int not_yet = 10;

    while (not_yet) {

        not_yet--;

        // ----- step 4

        centroid temp_cluster;
        for (int i = 0; i < images.size(); i++) {
            temp_cluster = clusters.at(0);

            for (int j = 0; j < clusters.size(); j++) {

                double vector_new_clus_to_img = vectors_distance(clusters.at(j).centroid_hist_stored,images.at(i).hist_RBG_counts);
                double vector_curr_clus_to_img = vectors_distance(temp_cluster.centroid_hist_stored,images.at(i).hist_RBG_counts);

                if (vector_new_clus_to_img > vector_curr_clus_to_img) {
                    continue;
                } else {
                    temp_cluster = clusters.at(j);
                }
            }
            images.at(i).setClusterValue(temp_cluster.getClusterNumber());
            newClusterMean(colour,images);
        }

    } // end of k-means iteration
}


}
void clustering:: newClusterMean(bool colour,vector<Image> &images){
    if(colour==false) {
        vector<int> sum(images.at(0).hist_grey_bins_count.size(), 0);
        // ----- step 5

        for (int c = 0; c < clusters.size(); c++) {
            int count_images_in_cluster = 0;
            sum = clusters.at(c).centroid_hist_stored;
            // find all images with centroid = c
            for (int i = 0; i < images.size(); i++) {

                if (images.at(i).getClusterValue() == clusters.at(c).getClusterNumber()) {
                    // this image is part of this cluster
                    sum = vectors_sum(sum, images.at(i).hist_grey_bins_count);
                    //sum=vectors_sum(sum,sum1);
                    count_images_in_cluster++;
                }
            }
            if (count_images_in_cluster > 0) {
                vector<int> avg = vector_divide(sum, count_images_in_cluster); // divide vector by the count.
                clusters.at(c).centroid_hist_stored = avg;
            }
        }
    }else{
        vector<int> sum(images.at(0).hist_RBG_counts.size(), 0);
        // ----- step 5

        for (int c = 0; c < clusters.size(); c++) {
            int count_images_in_cluster = 0;
            sum = clusters.at(c).centroid_hist_stored;
            // find all images with centroid = c
            for (int i = 0; i < images.size(); i++) {

                if (images.at(i).getClusterValue() == clusters.at(c).getClusterNumber()) {
                    // this image is part of this cluster
                    sum = vectors_sum(sum, images.at(i).hist_RBG_counts);
                    //sum=vectors_sum(sum,sum1);
                    count_images_in_cluster++;
                }
            }
            if (count_images_in_cluster > 0) {
                vector<int> avg = vector_divide(sum, count_images_in_cluster); // divide vector by the count.
                clusters.at(c).centroid_hist_stored = avg;
            }
        }
    }
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
        div[i] = int(a[i] / (b+1));
    }

    return div;
}

//clustering &ZMMALE001::clustering::operator+=(const vector<Image> &rhs) {
//    return *this;
//}


