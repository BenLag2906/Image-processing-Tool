# Image-processing-Tool

One executable to extract all image from input  MP4 vdeo file. 
By running the following command :
> cut.exe motif


All images are generated in OUTPUT folder with motif_0000X.jpeg

--------------------------
Other executable to make an video MP4 File based on jpeg input images.
By running the following command :
> generate.exe 2048 1592 motif1 motif2 motif3


All images are taken in subfolder TIMELINE with motif1_0000X.jpeg, then motif2_0000X.jpeg, motif3_0000X.jpeg. Notice than every images must have the input size. Here option setted, will take account  2048 * 1592 as input size.

--------------------------

All binary are available at this link :
https://drive.google.com/drive/folders/1BN0DgaXIAHkKFqZpf51XUxbzJN2tTDJ3?usp=sharing

To compilation of source file :
Visual Studio 2022.
In 64 bits, mode all dependancy are linked and for execution you could download previous linked to run exececutable generated.

For cut.exe :
  No special need execpt OpenCV version.

For generate.exe : 
  CLR is used, so it need the correct package with visual to compilation
