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
		double vLeft = 10.0;
		double vRight = 10.0;
		double d = 1.8; // placeholder constant for turning
		std::vector<int> whiteLine; //white pixel horizontal index
    		whiteLine.reserve(4); // stops segmentation fault error by reserving memory manually.
		
	    	std::vector<int> scanAhead; // adds extra scanning of white pixels for when there is a slight gap in the path
		scanAhead.reserve(4); 

		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 80, i, 3); // 50 is in the middle of the camera view
			
			int isWhite;
			int whiteIndex;
			
			if (pix > 250) {
				isWhite = 1;
			} else {
				isWhite = 0;
			} 
			std::cout<<isWhite<<" ";
			
			if (isWhite == 1) {
				//std::cout<< i <<std::endl;
				whiteLine.push_back(i); //Adds each white pixel index to the vector
			}
		}
		
		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 81, i, 3); // 50 is in the middle of the camera view
			int isWhite;
			
			if (pix > 250){
				isWhite = 1;
			} else {
				isWhite = 0;
			}
			
			std::cout<<isWhite<<" ";
            
			if (isWhite == 1){ 
				scanAhead.push_back(i);
			}

		}

  		// There are 4 white pixels and to be in the centre they need to be at 73,74,75,76.
  
		if (whiteLine.size() == 0 && scanAhead.size() == 0)  {  //(if no white pixels ) turn robot around to try again
			vRight = -1 * vRight;
			vLeft = vLeft;
		}	
		if (whiteLine[0] < 73) { // white line moving to the left
			vRight = vRight * d; // turn robot left

		}
		if (whiteLine[3] > 76) { // white line moving to the right
			vLeft = vLeft * d; // turn robot right
		}
		if (whiteLine.size() > 4 && scanAhead.size() > 4) {
			if (whiteLine[3] > 76){ // 90 degree right turn detection
				vLeft = vLeft * 2 * d; //turn robot right sharply
			} else if (whiteLine[0] < 73){ // 90 degree left turn detection
				vRight = vRight * 2 * d; //turn robot left sharply
			}
		} 		
		
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		vLeft = 0;
		vRight = 0;
  } //while

} // main
