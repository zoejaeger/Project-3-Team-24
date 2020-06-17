void completeRedMaze(double &vLeft, double &vRight){
	std::vector<int> redWall; // primary red pixel horizontal index
	redWall.reserve(150);
		
	std::vector<int> gapScan;
	gapScan.reserve(14); 
		
	std::vector<int> redAhead; 
	redAhead.reserve(14);
		
	    
	redScanner(65, redWall);
	redScanner(95, gapScan);
	redScanner(20, redAhead);
	
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
}
