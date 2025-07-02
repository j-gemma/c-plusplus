#include <iostream>
#include "input.h"
#include "calculateAdRevenue.h"

void runCalculateAdRevenue() {

	printAdRevenueInfo({ getIntFromUser("How many ads were watched?") ,
						 getDoubleFromUser("What percentage of users clicked an ad?") ,
						 getDoubleFromUser("Average earnings per clicked ad?") });

}

void printAdRevenueInfo(RevenueInfo rInfo) {

	std::cout << "Ads watched: " << rInfo.adsWatched << '\n';
	std::cout << "Percentage of users who clicked an ad:  " << rInfo.pctUsrClicks << '\n';
	std::cout << "Average earnings per clicked ad: " << rInfo.avgEarnPerClick << '\n';
	std::cout << "\nTotal ad revenue today: $" << rInfo.adsWatched * (rInfo.pctUsrClicks / 100) * rInfo.avgEarnPerClick << '\n';

}