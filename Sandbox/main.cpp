#include <iostream>
#include "Sandbox.h"
//#include "Random.h"
//#include "Constants.h"
#include "hiLo_JMG.h"
#include "main.h"

int main() {
	int whichPgm { askWhichPgm() };
hello:
	switch (whichPgm) {
	case 0: {
		runHiLo();
		whichPgm = 2;
		goto hello;
		break;
	}

	case 1: {
		runAdder();
		break;  // Prevent fallthrough to default
	}
	case 2: {
		runMult();
		break;
	}

	case 3: {
		runSub();
		break;
	}
	case 4:
		runAnimalLegNums();
		break;
	default: {
		runSwap();
		break;
	}
	}
}
