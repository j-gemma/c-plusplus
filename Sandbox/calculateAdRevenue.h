#pragma once

struct RevenueInfo {
	int adsWatched{};
	double pctUsrClicks{};
	double avgEarnPerClick{};
};

void printAdRevenueInfo(RevenueInfo rInfo);

void runCalculateAdRevenue();