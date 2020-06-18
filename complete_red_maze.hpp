void completeRedMaze(double &vLeft, double &vRight){
	vLeft = vLeft * 2; // double the normal speeds since the challenge maze is longer
	vRight = vRight * 2;
	double a = 8.435; //ninetyDegreeTurnConstant
	
	std::vector<int> redWall; // primary red pixel horizontal index
	redWall.reserve(150);
		
	std::vector<int> gapScan; //side wall red pixel horizontal index
	gapScan.reserve(14); 
		
	std::vector<int> redAhead; // front line red pixel horizontal index
	redAhead.reserve(14);
		
	    
	redScanner(65, redWall); //Primary scanner
	redScanner(95, gapScan); //Scans for walls either side to decide which way to turn
	redScanner(20, redAhead); //Scans ahead for wall openings
	
		//If there is a wall ahead and a wall to the left, turn right.
		if (redWall.size() > 30 && gapScan[0] < 75 && redWall[75] >=75 && redWall[75] < 80 ) {
			vLeft = vLeft * a;
			vRight = vRight * 0; 
		}
		//If there is a wall ahead and a wall to the right, turn left. 
		if (redWall.size() > 30 && gapScan.back() > 75 && redWall[75] >=75 && redWall[75] < 80){
			vLeft = vLeft * 0;
			vRight = vRight * a;	
		}
		//If there is a wall ahead and a wall to the left and a wall to the right, turn around.
		if (redWall.size() > 30 && gapScan[0] < 75 && gapScan.back() > 75 && redWall[75] >=75 && redWall[75] < 80){
			vLeft = vLeft * 0;
			vRight = vRight * a *2;
		}
		//If there is red up to a thickness of two walls in camera view then continue moving straight.
		if (redWall.size() <= 30){
			vLeft = vLeft;
			vRight = vRight; 
		} 
		//If there are no walls aside from an opening ahead, try turning right to go through gap.
		if (redWall.size() == 0 && redAhead.size() > 1 && redAhead.size() <= 15 && redAhead[0] > 65){
			vLeft = vLeft * a;
			vRight = vRight * 0;
		} 
		//If there is a wall ahead and no walls either side, try turning right. 	
		if (redWall.size() > 50 && gapScan.size() == 0){
			vLeft = vLeft * a;
			vRight = vRight * 0;
		}
}
