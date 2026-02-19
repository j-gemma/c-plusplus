#include "lambda.h"

const auto best{
	std::max_element(studentsArr.begin(), studentsArr.end(), [](Student a, Student b) {
		return (a.m_points < b.m_points);
})


};

void runFindBestStudent() {
	std::cout << best->m_name << " is the best student.";
}

int sortSeasons() {
	std::sort(seasons.begin(), seasons.end(), [](Season a, Season b) {
		return (a.m_averageTemperature < b.m_averageTemperature);
		});

	for (const auto& season : seasons)
	{
		std::cout << season.m_name << '\n';
	}

	return 0;

}

void runSortSeasons() {
	sortSeasons();
}

int GameState::getStartInt(int min) {
	return { getIntFromUserWithLowerBound("Start where? ", min)};
}

int GameState::getHowMany(int min) {
	return { getIntFromUserWithLowerBound("How many?", min)};
}

void runSquareGame() {
	GameState newState{};
}
