#include <cstdio>
FILE _iob[] = {*stdin, *stdout, *stderr};extern "C" FILE * __cdecl __iob_func(void){    return _iob;}  // remove this fix before submitting 

#include "robot.hpp"
#include "pixel_scanners.hpp"
#include "complete_red_maze.hpp"
#include "follow_white_path.hpp"


int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	// ask a user which program to run (Core, Completion or Challenge) and store their answer as "mode" - either 1, 2, or 3
	int mode;
	std::cout<< "Please select a mode: \nCore: enter '1' \nCompletion: enter '2' \nChallenge: enter '3'\n";
	std::cin>> mode;
        
    while(1){
		takePicture();
		SavePPMFile("i0.ppm",cameraView);
		double vLeft = 10.0;
		double vRight = 10.0;
		
		
		
		if (mode == 1 || mode == 2) { // core and completion 		 
			followWhitePath(vLeft, vRight);
		} else if (mode == 3) { // challenge
			completeRedMaze(vLeft, vRight); 
		} 
	        
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		vLeft = 0;
		vRight = 0;
  } //while

} // main


