//
// Created by User on 2020-04-06.
//
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include "Image.h"
#include "clustering.h"
#include "ImageProcessing.h"
#include <iostream>
#include <fstream>
#include "ImageProcessing.h"
#include "Image.h"
#include "clustering.h"
#include <vector>
#include <cstring>
#include <experimental/filesystem>
#include <iomanip>

using ZMMALE001::clustering;
using ZMMALE001:: Image;
using ZMMALE001:: ImageProcessing;
using ZMMALE001::RGB;

double clustering::vectors_distance(const std::vector<int> &a, const std::vector<int> &b) {
//    std::vector<double>	auxiliary;
//    std::transform (a.begin(), a.end(), b.begin(), std::back_inserter(auxiliary),[](int element1, int element2) {return pow((element1-element2),2);});
//    return  std::sqrt(std::accumulate(auxiliary.begin(), auxiliary.end(), 0.0));
    double total=0;
    for (int i = 0; i <a.size(); ++i) {
        total+=pow(a[i]-b[i],2);
    }
    return sqrt(total);
}

void clustering::cluster(int numClusters, int binSize, bool colour) {

}

ZMMALE001::clustering::clustering(int numClusters,int binSize,vector<Image> i) {
    for (int i = 0; i < numClusters; ++i) {
        centroid temp = centroid(binSize,i);
        clusters.push_back(temp);
    }
    kmean(i);
}

void ZMMALE001::clustering::kmean(vector<Image>* x) {
    centroid temp;
    Image tem;
    vector<Image> imag = x;
    for (Image i: x){
        for (centroid c : clusters) {
            double vecter1= vectors_distance(tem.getHistGreyBins(),c);
            double vecter2 = vectors_distance(i,c);
            if(vecter1 > vecter2){
                continue;
            }else{
                tem=i;
                temp=c;
            }
        }
        tem.setClusterValue(temp.getClusterNumber());
    }

}
