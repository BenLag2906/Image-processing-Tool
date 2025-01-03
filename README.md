# Image-processing-Tool

One executable to extract all image from an input MP4 video file. 
By running the following command :
> cut.exe pat1



After execute this command in OUPTUT directory : jpeg files are created with the following name "./OUTPUT/pat1_0000X.jpeg"
notice than pattern "pat1" must not exceed 5 characters.
--------------------------
Other executable to make an video MP4 File based on jpeg input images.
By running the following command :
> generate.exe 2048 1592 pat1 pat2 pat3


All images are taken in subfolder TIMELINE with pat1_0000X.jpeg, then pat2_0000X.jpeg, pat3_0000X.jpeg. Notice than every images must have the input size. Here option setted, will take account  2048 * 1592 as input size.

--------------------------

All binary are available at this link :
https://drive.google.com/drive/folders/1BN0DgaXIAHkKFqZpf51XUxbzJN2tTDJ3?usp=sharing

--------------------------

To compilation of source file :
--------------------------
Visual Studio 2022.
  In 64 bits mode, all dependancies are linked and for execution : you could download previous linked to run executable generated.

For cut.exe :
--------------------------
  No special needs, except OpenCV version.

For generate.exe :
--------------------------
  CLR is used, so it needs the correct package with visual studio to process compilation.
