#ifndef F1TEAM_H_
#define F1TEAM_H_
#include "F1Cars.h"

class F1Team {
private:
	char teamName[32];
	F1Car cars[2];
public:
	void readBinaryFile();
	void writeBinaryFile();

};


#endif
