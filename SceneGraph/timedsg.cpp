#include "timedsg.h"


TimedSG::TimedSG() {

}

void TimedSG::setSG( SceneGraph novoSG ) {

	this->sg = novoSG;

}

void TimedSG::prep() {

	this->sg.prep();

}

void TimedSG::draw() {

	bool aux = this->tmp.updateTime();
	this->sg.draw( aux );
}
