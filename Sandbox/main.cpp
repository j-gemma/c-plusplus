#include <iostream>
#include "projectHeaders.h"

int askWhichPgm() {
	return getIntFromUser("Which program?\n");
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
	case 22: {
		runLengthAndIndex();
		break;
	}
	case 23: {
		runPrintElement();
		break;
	}
	case 24: {
		runArrayLoopEx();
		break;
	}
	case 25: {
		runArraySearch();
		break;
	}
	case 26: {
		runFindMax();
		break;
	}
	case 27: {
		runFizzBuzz();
		break;
	}
	case 28: {
		runFindName();
		break;
	}
	case 29: {
		runEnumIndex();
		break;
	}
	case 30: {
		runVectorStack();
		break;
	}
	default: {
		std::cout << "Default case";
		break;
	}
	}

	return 0;
}
