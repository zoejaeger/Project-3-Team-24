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
	    
	    	std::vector<int> redWall; // primary red pixel horizontal index
		redWall.reserve(150);
		
		std::vector<int> gapScan;
		gapScan.reserve(14); 
		
		std::vector<int> redAhead; 
		redAhead.reserve(14);
		
		//RED, CHALLENGE
		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 65, i, 0); // 50 is in the middle of the camera view
			
			int isRed;
			
			if (pix > 250) {
				isRed = 1;
			} else {
				isRed = 0;
			} 
			//std::cout<<isRed<<"";
			
			if (isRed == 1) {
				std::cout<< i <<std::endl;
				redWall.push_back(i); //Adds each red pixel index to the redWall vector
			} 
		}
		
		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 95, i, 0); // 50 is in the middle of the camera view
			
			int isRed;
			
			if (pix > 250) {
				isRed = 1;
			} else {
				isRed = 0;
			} 
			//std::cout<<isRed<<"";
			
			if (isRed == 1) {
				std::cout << "GAP INDEX: " << i << std::endl; 
				gapScan.push_back(i); //Adds each red pixel index to the gapScan vector
			} 
		}
		
		for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, 20, i, 0); // 50 is in the middle of the camera view
			
			int isRed;
			
			if (pix > 250) {
				isRed = 1;
			} else {
				isRed = 0;
			} 
			//std::cout<<isRed<<"";
			
			if (isRed == 1) {
				 
				redAhead.push_back(i); //Adds each red pixel index to the redAhead vector
			} 
		}
		 
		if (redWall.size() > 30 && gapScan[0] < 75 && redWall[75] >=75 && redWall[75] < 80 ) {
			vLeft = vLeft*16.87;
			vRight = vRight * 0; 
		}
		if (redWall.size() > 30 && gapScan.back() > 75 && redWall[75] >=75 && redWall[75] < 80){
			vLeft = vLeft * 0;
			vRight = vRight * 16.87;
			
		}
		if (redWall.size() > 30 && gapScan[0] < 75 && gapScan.back() > 75 && redWall[75] >=75 && redWall[75] < 80){
			vLeft = vLeft * 0;
			vRight = vRight * 16.87 *2;
		
		}
		if (redWall.size() <= 30){
			vLeft = vLeft;
			vRight = vRight; 
		} 
		if (redWall.size() == 0 && redAhead.size() > 1 && redAhead.size() <= 15){
			vLeft = vLeft* 8.435;
			vRight = vRight * 0;
		} 
		if (redWall.size() > 30 && gapScan.size() == 0){
			vLeft = vLeft * 16.87;
			vRight = vRight * 0;
		}
		
		std::cout <<"RED PIXEL SIZE: " << redWall.size() << std::endl;
	    
	    
	    	// CORE / COMPLETION 
	    	/* commented out for now till only red pixels are detected for code above

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
		*/
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		vLeft = 0;
		vRight = 0;
  } //while

} // main
