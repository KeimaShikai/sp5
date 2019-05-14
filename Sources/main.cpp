#include "CMain.h"

int main( int argc, char* args[] )
{
	CMain* cMain = new CMain(640, 480);
	cMain->loop();
	return 0;
}