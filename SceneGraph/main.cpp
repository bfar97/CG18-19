#include "timedsg.h"

using namespace std;

int main() {

	vector<Pontos> ptn;
	Pontos ptns[4] = {{0.0f, 0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}};
	TranslacaoC curva;
	TimedSG test;
	
	ptn.insert(ptn.begin(), ptns, ptns+4);
	curva.setCurva(ptn, 15);
	SceneGraph sg1, sg2;
	sg1.addFilho(sg2);
	sg1.setCurva(curva);
	test.setSG(sg1);
	sg1.addFilho(sg2);
	return 0;
}
