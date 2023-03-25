#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

constexpr auto mod = 1'000'000'000;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	int n_{};
	int ans_{};

public:
	void input() {
		cin >> n_;
	}

	void solve() {
		auto dp = vvl(n_, vl(10, 0));
		for (auto d = 1; d < 10; ++d) {
			dp[0][d] = 1;
		}

		for (auto i = 1; i < n_; ++i) {
			dp[i][0] = dp[i - 1][1];
			for (auto d = 1; d < 9; ++d) {
				dp[i][d] = dp[i - 1][d - 1] + dp[i - 1][d + 1];
				dp[i][d] %= mod;
			}
			dp[i][9] = dp[i - 1][8];
		}

		ans_ = 0;
		for (auto d = 0; d < 10; ++d) {
			ans_ += dp[n_ - 1][d];
			ans_ %= mod;
		}
	}

	void output() const noexcept {
		cout << ans_;
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto s = solution{};
	s.input();
	s.solve();
	s.output();

	return 0;
}