#include <cstdio>
FILE _iob[] = {*stdin, *stdout, *stderr};extern "C" FILE * __cdecl __iob_func(void){    return _iob;}  // remove this fix before submitting 

#include "robot.hpp"

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
    double vLeft = 3.0;
    double vRight = 3.0;
    	
    while(1){
		takePicture();
		SavePPMFile("i0.ppm",cameraView);
		
		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 50, i, 3); // 50 is in the middle of the camera view
			int isWhite;
			
			if (pix > 250){
				isWhite = 1;
			} else {
				isWhite = 0;
			}
			
			std::cout<<isWhite<<" ";
		}
		
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // main
