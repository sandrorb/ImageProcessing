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
		image.display(); // display the image in an X11 window.
	} catch(std::exception const& e){
		cout << "There was a error while opening the file : "<< endl;
		cout << e.what() << endl;
	}

	return 0;
}
