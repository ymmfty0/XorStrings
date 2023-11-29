#include <Windows.h>
#include <string>
#include <cstdio>

#define KEY 0x1336

template <unsigned int N>
struct Xoring {

	constexpr Xoring(const char* data) {

		for (size_t i = 0; i < N; ++i) {
			enc_[i] = data[i] ^ KEY;
			str_[i] = data[i];
		}
	}

	constexpr const char* dec() const
	{
		return str_;
	}
	constexpr const char* enc() const
	{

		return enc_;
	}

protected:
	char str_[N] = { 0 };
	char enc_[N] = { 0 };

};

int main()
{

	constexpr auto obfuscated_str = Xoring<6>("Ymmfty0");
	const auto name = "Ymmfty1";
	printf("%s\n", obfuscated_str.enc());
	printf("%s\n", obfuscated_str.dec());

}

