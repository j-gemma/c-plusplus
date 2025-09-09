
template <typename T, typename X, typename Y>
class Triad {

private:
	T m_first{};
	X m_second{};
	Y m_third{};

public:

	Triad(const T& first, const X& second, const Y& third)
		: m_first{ first }
		, m_second{ second }
		, m_third{ third }
	{

	}

	const T& getFirst() const { return m_first; }
	const X& getSecond() const { return m_second; }
	const Y& getThird() const { return m_third; }

	void print() const;
};

template <typename T, typename X, typename Y>
void Triad<T, X, Y>::print() const {
	std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]";
}

void runTriad();