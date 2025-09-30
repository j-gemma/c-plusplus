#include <iostream>
#include "Sandbox.h"
#include "input.h"
#include "hiLo.h"
#include "swap.h"
#include "animalLegNums.h"
#include "calculateAdRevenue.h"
#include "FractionStruct.h"
#include "Monster.h"
#include "TriadStruct.h"
#include "Point3d.h"
#include "Point2d.h"
#include "Ball.h"
#include "FractionClass.h"
#include "Triad.h"
#include "ClassRandom.h"
#include "Vector3d.h"
#include "stdVectorExample.h"

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
		runFractionStruct();
		break;
	}
	case 8: {
		runInstantiateMonsters();
		break;
	}
	case 9: {
		runTriadStruct();
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
	case 12: {
		runPoint2d();
		break;
	}
	case 13: {
		runFractionClass();
		break;
	}
	case 14: {
		runTriad();
		break;
	}
	case 15: {
		runRandomClass();
		break;
	}
	case 16:{
		runFriendExample();
		break;
	}
	case 17:{
		runInitMonster();
		break;
	}	
	case 18:{
		runMonsterStats();
		break;
	}	
	case 19: {
		runMonsterGenerator();
		break;
	}
	case 20: {
		runGenerate100Monsters();
		break;
	}
	case 21: {
		runGet3Numbers();
		break;
	}
	default: {
		std::cout << "Default case";
		break;
	}
	}

	return 0;
}
