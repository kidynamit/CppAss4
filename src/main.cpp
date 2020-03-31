#include <iostream>
#include "ImageProcessing.h"
#include "ClusterProcess.h"
#include <cctype>


using ZMMALE001::ImageProcessing;

int main(int argc, char *argv[]) {

    std::string format= "clusterer <dataset> [-o output] [-k n] [-bin b]";
    std::string output;
    int clusters;
    int bin;
    std::string arg1;
try {
    if (argc> 2 && argc < 9) {
        std::cout << "start proses.\n";
        ImageProcessing imageProcessing(argv[1]);
        arg1=argv[1];

        if (std::string(argv[2]).compare("-o") == 0) {
            output = argv[3];
            if (std::string(argv[4]).compare("-k") == 0) {
                clusters = std::stoi(argv[5]);
                if (std::string(argv[6]).compare("-bin") == 0) {
                    bin = std::stoi(argv[7]);
                } else {
                    bin = 1;
                }
            } else {
                clusters = 10;
                if (std::string(argv[4]).compare("-bin") == 0) {
                    bin = std::stoi(argv[5]);
                } else {
                    bin = 1;
                }
            }
        } else {
            //write finished clusters to cout
            if (std::string(argv[2]).compare("-k") == 0) {
                clusters = std::stoi(argv[3]);
                if (std::string(argv[4]).compare("-bin") == 0) {
                    bin = std::stoi(argv[5]);
                } else {
                    bin = 1;
                }
            } else {
                clusters = 10;
                if (std::string(argv[2]).compare("-bin") == 0) {
                    bin = std::stoi(argv[3]);
                } else {
                    bin = 1;
                }
            }
        }
    }
    if(argc==2 ){
        clusters=10;
        bin=1;
    }
    std::cout<<arg1<<" "<<output<<" "<<clusters<<" "<<bin;
}
catch( std::invalid_argument& e){
    std::cerr << e.what() << std::endl;
    std::cout<< format << std::endl;
    return -1;
}
    return 0;
}
