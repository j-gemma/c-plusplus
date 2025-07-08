#include <iostream>
#include "Sandbox.h"
#include "input.h"
#include "hiLo.h"
#include "swap.h"
#include "animalLegNums.h"
#include "calculateAdRevenue.h"
#include "multiplyFractions.h"
#include "Monster.h"
#include "Triad.h"
#include "Point3d.h"
#include "Ball.h"

int askWhichPgm() {
	return getIntFromUser("Which program?");
}

int main() {


	int whichPgm { askWhichPgm() };
	switch (whichPgm) {
	case 0: {
		runHiLo();
		break;
	}
	case 4: {
		runSwap();

		break;
	}
	case 5:{
		runAnimalLegNums();
		break;
	}
	case 6:{
		runCalculateAdRevenue();
		break;
	}
	case 7: {
		runMultiplyFractions();
		break;
	}
	case 8: {
		runInstantiateMonsters();
		break;
	}
	case 9: {
		runTriad();
		break;
	}
	case 10: {
		runClassExample();
		break;
	}
	case 11: {
		runBallClass();
		break;
	}
	default: {
		std::cout << "Default case";
		break;
	}
	}

	return 0;
}
