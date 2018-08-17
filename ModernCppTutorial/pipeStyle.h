#pragma once
#ifdef PIPEABLE

template<class F>
struct pipe_closure : F
{
	template<class... Xs>
	pipe_closure(Xs&&... xs) : F(std::forward<Xs>(xs)...)
	{}
};

template<class T, class F>
decltype(auto) operator|(T&& x, const pipe_closure<F>& p)
{
	return p(std::forward<T>(x));
}

struct add_one_f
{
	template<class T>
	auto operator()(T x) const
	{
		return x + 1;
	}
};

/*
const pipe_closure<add_one_f> add_one = {};
int number_3 = 1 | add_one | add_one;
std::cout << number_3 << std::endl;

-------------------------------------
int number_3 = 1 | sum(2);
std::cout << number_3 << std::endl;
*/

template<class F>
auto make_pipe_closure(F f)
{
	return pipe_closure<F>(std::move(f));
}

template<class F>
struct pipable
{
	template<class... Ts>
	auto operator()(Ts... xs) const
	{
		return make_pipe_closure([=](auto x) -> decltype(auto)
		{
			return F()(x, xs...);
		});
	}
};

/*
const constexpr pipable<sum_f> sum = {};
int number_3 = 1 | sum(2);
std::cout << number_3 << std::endl;

*/

#define REQUIRES(...) class=std::enable_if_t<(__VA_ARGS__)>

template<class T>
struct wrapper
{
	T value;
	template<class X, REQUIRES(std::is_convertible<T, X>())>
	wrapper(X&& x) : value(std::forward<X>(x))
	{}

	T get() const
	{
		return std::move(value);
	}
};

template<class T>
auto make_wrapper(T&& x)
{
	return wrapper<T>(std::forward<T>(x));
}

template<class F>
struct pipable
{
	template<class... Ts>
	auto operator()(Ts&&... xs) const
	{
		return make_pipe_closure([](auto... ws)
		{
			return [=](auto&& x) -> decltype(auto)
			{
				return F()(x, ws.get()...);
			};
		}(make_wrapper(std::forward<Ts>(xs)...)));
	}
};

template<class T, class F>
decltype(auto) operator|(T&& x, const pipable<F>& p)
{
	return F()(std::forward<T>(x));
}

/*
const constexpr pipable<add_one_f> add_one = {};
int number_3 = 1 | add_one | add_one;
std::cout << number_3 << std::endl;

*/



#endif // PIPEABLE

