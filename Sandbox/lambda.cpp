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

bool GameState::playGame() {
	int guess{ getTFromUser<int>(std::format("I have generated {} square numbers.\
        Do you know what each number is after multiplying it by {}?\n", m_howMany, m_mult)) };

	auto found{ std::find(m_generated.begin(), m_generated.end(), guess)};

	if(found == m_generated.end())
	{
		auto closest{ std::min_element(m_generated.begin(), m_generated.end(), [guess](int a, int b) {
			return abs(a - guess) < abs(b - guess); }) };

		std::cout << std::format("{} is wrong! Try {} next time", guess, *closest);
	}

	else {
		m_generated.erase(found);
		getTFromUser<int>(std::format("Nice! {} number(s) left.\n", m_generated.size()));
	}

	return false;

}


bool runSquareGame() {
	GameState newState{};
	bool win{ newState.playGame() };

	return win;
}
