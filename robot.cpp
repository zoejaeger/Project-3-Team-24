#include <cstdio>
FILE _iob[] = {*stdin, *stdout, *stderr};extern "C" FILE * __cdecl __iob_func(void){    return _iob;}  // remove this fix before submitting 

#include "robot.hpp"

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
    
    	
    while(1){
		takePicture();
		SavePPMFile("i0.ppm",cameraView);
		double vLeft = 5.0;
		double vRight = 5.0;
		double d = 1.1; //placeholder constant for turning
		int[] whiteLine = new int[3]; //white pixel horizontal index
	    
		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 50, i, 3); // 50 is in the middle of the camera view
			int isWhite;
			int whiteIndex;
			
			if (pix > 250){
				isWhite = 1;
			} else {
				isWhite = 0;
			}
			
			std::cout<<isWhite<<" ";
			
			if (isWhite == 1){
				//std::cout << i <<std::endl;
				Whiteline[0] = i;   //Need to figrue out to append the 4 whitepixel indexs to the whiteLine array
		}
		if (Whiteline[0] < 73){    //white line moving to the left
			vRight = vRight * d; //turn robot left
		}
		if (Whiteline[3] > 76){	   //white line moving to the right
			vLeft = vLeft * d;   //turn robot right
		}
			
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // main
