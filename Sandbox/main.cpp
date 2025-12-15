#include <iostream>
#include "bubbleSort.h"
#include "input.h"
#include "hiLo.h"
#include "swap.h"
#include "animalLegNums.h"
#include "calculateAdRevenue.h"
#include "FractionStruct.h"
#include "Monster.h"
#include "TriadStruct.h"
#include "Point3d.h"
#include "Ball.h"
#include "Point2d.h"
#include "FractionClass.h"
#include "Triad.h"
#include "ClassRandom.h"
#include "Vector3d.h"
#include "stdVectorExample.h"
#include "arrayLoop.h"
#include "rangeBased.h"
#include "enumIndex.h"
#include "vectorStack.h"
#include "cppMan.h"
#include "quiz16.h"
#include "ch17ArraysPt1.h"
#include "perfectSquares.h"
#include "roscoes.h"
#include "deck52.h"

int askWhichPgm() {
	return getTFromUser<int>("Which program?\n");
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
	case 31: {
		runQuiz16();
		break;
	}
	case 32: {
		playCPPMan();
		break;
	}
	case 33: {
		runArrayIntro();
		break;
	}
	case 34: {
		runPrintArray();
		break;
	}
	case 35: {
		runPrintItems();
		break;
	}
	case 36: {
		runArrayOfAnimals();
		break;
	}
	case 37: {
		runPerfectSquares();
		break;
	}
	case 38: {
		runPrintArrayUsingPointers();
		break;
	}
	case 39: {
		runRoscoes();
		break;
	}case 40: {
		runDeck52();
		break;
	}
	case 41: {
		runDealCards();
		break;
	}
	case 42: {
		runPlayBlackjack();
		break;
	}
	case 43: {
		runBubbleSort();
		break;
	}

	default: {
		std::cout << "Default case";
		break;
	}
	}

	return 0;
}
