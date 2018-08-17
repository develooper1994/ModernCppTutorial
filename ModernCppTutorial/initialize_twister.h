#pragma once
// Teþekkürler: http://www.cplusplus.com/forum/beginner/176265/
std::mt19937 initialize_twister(std::size_t seed = std::chrono::system_clock::now().time_since_epoch().count())
{
	static constexpr std::size_t NUM_DISCARD = 10240;

	std::minstd_rand lcg(seed);
	lcg.discard(NUM_DISCARD);

	std::size_t seeds[std::mt19937::state_size];
	std::generate_n(seeds, std::mt19937::state_size, lcg);

	try
	{
		// check if there is a random_device available
		seeds[0] = std::random_device{}();
	}
	catch (const std::exception&)
	{
		/* ignore */
	}

	std::seed_seq seed_sequence(std::begin(seeds), std::end(seeds));
	return  std::mt19937{ seed_sequence }; // warm-up with seed seed_sequence.generate()
										   //   return seed_sequence;
}
