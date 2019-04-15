#ifndef TIMEDSG__H
#define TIMEDSG__H

#include "sg.h"
#include "cronometro.h"

class TimedSG {

	SceneGraph sg;
	Cronometro tmp;

	public:
		TimedSG();
		void setSG( SceneGraph );
		void prep();	
		void draw();
};

#endif
