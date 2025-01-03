#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

void main(int argc, char* argv[])
{

    if (argc > 1) {

        std::cout << "Cut will be export image file with pattern : " << argv[1] <<  " in sub folder : OUTPUT \n";
    }
    else {
        std::cout << "Please enter a pattern for output image file \n cut.exe motif \n it corresponds to subfolder value \n";
        return ;
    }
    std::cout << "Extracting movie : " << "input.mp4" << "\n";

    string filename = "input.mp4";
    VideoCapture capture(filename);
    Mat frame;
    std::vector<Mat*> buffer= std::vector<Mat*>();
   
    if (strlen(argv[1]) > 5) {
        std::cout << "pattern must not be more long than 5 Characters \n";
    }
        
    
   
    int  i = 1;
    while (true)
    {
  
            
        capture.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);
        if (waitKey(5) >= 0) {
            break;
        }
        char bufferexport[200];
        snprintf(bufferexport, 28, "./OUTPUT/%s_%05d.jpeg", argv[1], i);
        imwrite(bufferexport, frame);
        i++;

    }
    
   

    return ;
    
}

