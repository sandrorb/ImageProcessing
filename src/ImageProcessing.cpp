//============================================================================
// Name         : ImageProcessing.cpp
// Author       : Sandro R. Boschetti
// Version      : 0.1
// Date         : March 13, 2013
// Copyright    : This is totally free!!!
// Description  : Test program used to learn image manipulation using Magick++
//============================================================================

#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main(int argc, char **argv) {

// In an internet example, I read this two lines are needed.
// 	int main(ssize_t /*argc*/, char ** argv) {
// 	InitializeMagick(*argv);

	string fileNameFullPath = "/Volumes/Dados/Workspace-Eclipse-Juno-cpp/ImageProcessing/NM_image.jpg";

	try {
		Image image;
		image.read(fileNameFullPath);

		// put a 10x10 blue square at the point (50,50)
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				image.pixelColor( 50 + i, 50 + j, "blue" );
			}
		}

		// Making a red circle
		const double PI = 3.141592653589793238462;
		double angle = 0.0;
		double radius = 20.0;
		const int centerX = 55;
		const int centerY = 55;
		do {
			int x = radius * cos(angle);
			int y = radius * sin(angle);
			image.pixelColor(centerX + x, centerY + y, "red");
			angle = angle + 0.01;
		} while (angle < 2*PI);

		// display the image in an X11 window and the program stays here until the window is closed.
		image.display();

//		Pixels pixels(image);
//		*(pixels.get( 108, 94, 10 ,10 )) = Color("green");
//		pixels.sync();
//
//		image.write(fileNameFullPath);
//		image.display();

	} catch(std::exception const& e){
		cout << "There was an error while opening the file : "<< endl;
		cout << e.what() << endl;
	}


	return 0;
}
