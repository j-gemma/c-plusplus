#include "ch25SummaryQuiz.h"
#include <memory>

int ch25Question2b()
{
    Circle c{ Point2d{ 1, 2 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point2d{ 1, 2 }, Point2d{ 3, 4 }, Point2d{ 5, 6 }};
    std::cout << t << "\n\n\n";

    return 0;
}

int getLargestRadius(const std::vector<Shape*>& v){
  int largestRad{};

  for(const auto* shape : v){
    if(auto* c { dynamic_cast<const Circle*>(shape) }){
      largestRad = std::max(largestRad, c->getRadius());
      }
    }
  return largestRad;
}

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& v){
  int largestRad{};

  for(const auto& shape : v){
    if(auto* c {dynamic_cast<const Circle*>(shape.get())}){
      largestRad = std::max(largestRad, c->getRadius());
    }
  }

  return largestRad;
}

int ch25SummaryQuizMain(){

  std::vector<Shape*> v{
    new Circle{Point2d{1, 2}, 7},
    new Triangle{Point2d{ 1, 2 }, Point2d{ 3, 4 }, Point2d{ 5, 6 }},
    new Circle{Point2d{ 7, 8}, 3}
  };

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

  return 0;
}

int ch25SummaryQuizMain2(){

  std::vector<std::unique_ptr<Shape>> v{};

  v.push_back(std::make_unique<Circle>(Point2d{1, 2}, 7));
  v.push_back(std::make_unique<Triangle>(Point2d{ 1, 2 }, Point2d{ 3, 4 }, Point2d{ 5, 6 }));
  v.push_back(std::make_unique<Circle>(Point2d{7, 8}, 3));

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

  return 0;
}
