#include "ch25SummaryQuiz.h"

int ch25SummaryQuizMain(){

  std::vector<Shape*> v{
    new Circle{Point{1, 2}, 7},
    new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
    new Circle{Point{ 7, 8}, 3}
  };

  std::cout << "The largest radius is: << getLargestRadius(v) << '\n';


  return 0;
}
