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
	return { getIntFromUserWithLowerBound("How many? ", min)};
}

void GameState::playGame() {
	const std::string START_MESSAGE{ std::format("I have generated {} square numbers.\
    Do you know what each number is after multiplying it by {}?\n", m_howMany, m_mult) };

	static std::string message{ START_MESSAGE };

	while (!m_win && !m_lose) {
	int guess{ getTFromUser<int>(message) };

	auto found{ std::find(m_generated.begin(), m_generated.end(), guess)};

	if(found == m_generated.end())
	{
		auto closest{ std::min_element(m_generated.begin(), m_generated.end(), [guess](int a, int b) {
			return abs(a - guess) < abs(b - guess); }) };

		std::cout << std::format("{} is wrong! Try {} next time", guess, *closest);
		m_lose = true;
	}

	else {
		m_generated.erase(found);
		size_t currSize{ m_generated.size() };
		switch(currSize) {
			case 0: {
				m_win = true;
				std::cout << "Nice! You found all the numbers, good job!";
				break;
			}
			default: {
				message = std::format("Nice! {} number(s) left.\n", currSize);
				break;
			}
		}
		}	
	}
}


int runSquareGame() {
	GameState newState{};
	newState.playGame();
	
	return 0;
}

//function prototypes Chapter 20 Quiz q1 
/*
double max(double a, double b);

me: void swap(int a, int b);

correct: void swap(int& a, int& b);

int& getLargestElement(std::array<int>, int length)

correct: int& getLargestElement(int* array, int length)o

TIP: use a pointer to the array type for the address of a dynamically allocated array
*/
