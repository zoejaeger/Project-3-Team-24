
void redScanner(int column, std::vector<int> &redPixScanner){ // detects red pixels and then adds their horizontal index to a vector
	for (int i = 0; i < 150; i++) { // image is 150px wide
			 
			int pix = get_pixel(cameraView, column, i, 0); 
			
			int isRed;
			
			if (pix > 250) {
				isRed = 1;
			} else {
				isRed = 0;
			} 
			//std::cout<<isRed<<"";
			
			if (isRed == 1) {
				std::cout<<  i <<std::endl;
				redPixScanner.push_back(i); //Adds each red pixel index to the redWall vector
			} 
			
		}
}

void whiteScanner(int column, std::vector<int> &whitePixScanner){ // detects white pixels and then adds their horizontal index to a vector
	for (int i = 0; i < 150; i++) { // image is 150px wide
			int pix = get_pixel(cameraView, column, i, 3); // 50 is in the middle of the camera view
			
			int isWhite;
			int whiteIndex;
			
			if (pix > 250) {
				isWhite = 1;
			} else {
				isWhite = 0;
			} 
			std::cout<<isWhite<<" ";
			
			if (isWhite == 1) {
				whitePixScanner.push_back(i); //Adds each white pixel index to the vector
			}
		}
}
