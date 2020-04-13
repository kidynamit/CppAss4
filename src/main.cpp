#include <iostream>
#include "ImageProcessing.h"
#include "Image.h"
#include "Clustering.h"
#include <cctype>



using ZMMALE001::ImageProcessing;
using ZMMALE001::Image;
using std::string;

int main(int argc, char *argv[]) {

    std::cout << "start proses.\n";

    std::string format= "clusterer <dataset> [-o output] [-k n] [-bin b] [-color]";

    std::string baseName;
    //default
    std::string output ="noOutputLoctation";
    int clusters=10;
    int bin=1;
    bool colour=false;
    try {
        baseName = argv[1];
        int i = 1;
        while (argv[i] != NULL) {
            if (std::string(argv[i]).compare("-o")==0) {
                output = argv[i + 1];
                i++;
            } else if (std::string(argv[i]).compare("-k")==0) {
                clusters = std::stoi(argv[i + 1]);
                i++;
            } else if (std::string(argv[i]).compare("-bin")==0) {
                bin = std::stoi(argv[i + 1]);
                i++;
            } else if (std::string(argv[i]).compare("-colour")==0) {
                colour = true;
            }
            i++;
        }

        ImageProcessing driver(string(baseName), clusters, bin ,colour);

        // print histogram (DEBUG)
        driver.processAllHist();

        // classify the images
        driver.classify(output);
    }
    catch( std::invalid_argument& e)
            {
                std::cerr << e.what() << std::endl;
                std::cout << format << std::endl;
                return -1;
            }
// end program
return 0;
}
