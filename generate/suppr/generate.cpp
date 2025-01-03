// suppr.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "opencv2/opencv.hpp"
#include <string>
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
//#include <dirent.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>

#include <string>
#include <iostream>
#include <filesystem>
#using <system.dll>

using namespace System;
using namespace System::IO;




using namespace cv;
using namespace std;




int main(int argc, char* argv[])
{
    
    if (argc > 3) {

        std::cout << "Input image must have the size : " << argv[1] << argv[2] << " in sub folder : TIMELINE \n";
    }
    else {
        std::cout << "Please enter a value of size input image in argument : \n generate.exe 4608 2582 motif : corresponding to subfolder value \n";
        return 0;
    }
    
    VideoWriter writer;
    int codec = VideoWriter::fourcc('M', 'P', '4', 'V');
    double fps = 10.0;
    string filename2 = "live.mp4";
    
    cout << "Started writing video... " << endl;
    int w = stoi(argv[1]);
    int h = stoi(argv[2]);
    char* motif = argv[3];

    //read pattern 
    int ipattern = 3;
    std::vector < char* > patterns;
    while (ipattern < argc)
    {
        patterns.push_back(argv[ipattern]);
        cout << "pattern writing video... " << argv[ipattern] << endl;
        ipattern++;
    }

    cout << "pattern  writing video... " << endl;
    cv::Size sz = cv::Size(w, h);
    Mat framet3 = Mat(sz, CV_8UC3);
    
    writer.open(filename2, codec, fps, sz, true);
   
    int  i = 1;
    int integrated = 0;
    
    
    
    
    
    int index = 0;
    while (index < patterns.size()) {
        std::cout << patterns[index]  << " pattern for live.mp4" << "\n";
        System::String^ f0 = "./TIMELINE/";
        integrated = 0;
        string temp = string(patterns[index]);

        string tem2 = temp + "_";
        const char* cString = tem2.c_str();
        System::String^ f1 = gcnew System::String(cString);
        
        System::String^ test = f0 ;
        int files_motif = 0;
        auto filess = Directory::GetFiles(test);
        int files = filess->Length;
        for (int path_find = 0; path_find < filess->Length; path_find++) {

            if (filess[path_find]->Contains(f1)) {
                files_motif++;
            }
        }
        
        std::cout << files_motif << " files will be integrated in output movie live.mp4" << "\n";

        while (true)
        {
            std::cout << i << " " << integrated << " " << files_motif <<  " " << patterns[index] <<  "\n ";// " All files have been integrated in output movie live.mp4" << "\n";
            if (integrated > (files_motif -1)) {
                std::cout << " All files have been integrated in output movie live.mp4" << "\n";
                integrated = 0;
                break;
            }


            try {
                char buffer[200];
                snprintf(buffer, 28, "./TIMELINE/%s_%05d.jpeg", patterns[index], i);
                std::cout << " file " << buffer << "\n";

                FILE* file;
                int err = fopen_s(&file, buffer, "r");
                if (err != 0)
                {
                    std::cout << " error Empty file " << "\n";
                    i++;

                    continue;
                }

                Mat framet3 = imread(buffer);
                if (framet3.data == NULL) {
                    std::cout << " Empty file " << "\n";
                    i++;
                    integrated++;
                    continue;
                }
                writer.write(framet3);

                std::cout << " file " << buffer << "   is integrated in output movie live.mp4" << "\n";
                integrated++;
            }
            catch (...) {
                std::cout << " error file ";
            }
            i++;

        }
        index++;
        i = 1;
    }
    writer.release();

    return 0;
    
}

