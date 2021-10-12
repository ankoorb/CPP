C++/C  Problem Statement:
------------------------------
Create a C++ or C program which performs the following in the order:

1. Take two arguments, width and height, from the command line
2. Create an unsigned char matrix M of size width x height
3. Fill M with some random data
4. Apply [-1, 0, 1] filter along x and y axes (i.e. convolve the image with [-1, 0, 1] kernel along horizontal and vertical axes) in order to compute derivatives dx and dy of M along x and y axis respectively (you must explicitly compute dx & dy matrices)
5. Print min and max values of the computed dx & dy matrices
6. Print total time taken by the machine in computing dx, dy, min and max operations



### Solution: Instructions
I used **`C++ 17`** to develop the application.


1. **`cd ImageDerivative`**
3. Run **`make build`** to build the **CLI** application (`make clean` if you want to remove build files and executable)
4. Run **`cd build`**
5. **`./ImageDerivative width height`** to run the application. 

> Example: `./ImageDerivative 224 256`
