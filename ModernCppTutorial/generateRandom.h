#pragma once
// non-const
template<typename T>
inline void rastgeleUret(std::vector<T>& vec, const size_t& N = 10, size_t& min = 1, size_t& max = 100) {
	/*
	 * vec: input vector
	 * N: size of vector
	 * min: minimum of generated numbers
	 * max: maximum of generated numbers
	 * 
	 * There is no output instead of referancing to input vector
	 */
	vec.resize(N); // reserve
	std::random_device randomDevice; std::default_random_engine dRandomEngine(randomDevice());
	std::uniform_int_distribution<T> uniformIntDistribution(min, max);
	std::generate(vec.begin(), vec.end(), [&min, &max, &dRandomEngine, &uniformIntDistribution](){ 
										  return uniformIntDistribution(dRandomEngine); });
}

template<typename T>
static inline std::vector<T> rastgeleUret(const size_t& N = 10, size_t& min = 1, size_t& max = 100) {
	/*
	* vec: input vector
	* N: size of vector
	* min: minimum of generated numbers
	* max: maximum of generated numbers
	*
	* return type is vector<T>
	*/
	std::vector<T> vec(N);
	vec.resize(N); // reserve
	std::random_device randomDevice; std::default_random_engine dRandomEngine(randomDevice());
	std::uniform_int_distribution<T> uniformIntDistribution(min, max);
	std::generate(vec.begin(), vec.end(), [&min, &max, &dRandomEngine, &uniformIntDistribution]() {
		return uniformIntDistribution(dRandomEngine); });
	return vec;
}

// const
template<typename T>
inline void rastgeleUret(std::vector<T>& vec, const size_t& N = 10, const size_t& min = 1, const size_t& max = 100) {
	/*
	* vec: input vector
	* N: size of vector
	* min: minimum of generated numbers
	* max: maximum of generated numbers
	*
	* There is no output instead of referancing to input vector
	*/
	vec.resize(N); // reserve
	std::random_device randomDevice; std::default_random_engine dRandomEngine(randomDevice());
	std::uniform_int_distribution<T> uniformIntDistribution(min, max);
	std::generate(vec.begin(), vec.end(), [&min, &max, &dRandomEngine, &uniformIntDistribution]() {
		return uniformIntDistribution(dRandomEngine); });
}

template<typename T>
static inline std::vector<T> rastgeleUret(const size_t& N = 10, const size_t& min = 1, const size_t& max = 100) {
	/*
	* vec: input vector
	* N: size of vector
	* min: minimum of generated numbers
	* max: maximum of generated numbers
	*
	* return type is vector<T>
	*/
	std::vector<T> vec(N);
	vec.resize(N); // reserve
	std::random_device randomDevice; std::default_random_engine dRandomEngine(randomDevice());
	std::uniform_int_distribution<T> uniformIntDistribution(min, max);
	std::generate(vec.begin(), vec.end(), [&min, &max, &dRandomEngine, &uniformIntDistribution]() {
		return uniformIntDistribution(dRandomEngine); });
	return vec;
}

static int GetRandom (int max) {
	srand(time(NULL));
	return rand() % max;
};