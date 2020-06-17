void followWhitePath(double &vLeft, double &vRight){
	
	double d = 1.8; // placeholder constant for turning
	std::vector<int> whiteLine; //white pixel horizontal index
    whiteLine.reserve(4); // stops segmentation fault error by reserving memory manually.
		
	std::vector<int> scanAhead; // adds extra scanning of white pixels for when there is a slight gap in the path
	scanAhead.reserve(4); 
	
	whiteScanner(80, whiteLine);
	whiteScanner(81, scanAhead);
	
	if ((whiteLine.size() == 0 && scanAhead.size() == 0) || (whiteLine.size() > 50 && scanAhead.size() > 50))  {  //(if no white pixels ) or (if approaching white image) turn robot around to try again 
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

}
