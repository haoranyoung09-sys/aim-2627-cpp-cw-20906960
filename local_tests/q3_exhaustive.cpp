#define main q3_public_main
#include "../src/main/A1_q3.cpp"
#undef main
int main() {
    int cases = 0;
    for (int n = 0; n <= 6; ++n) {
        int combinations = 1;
        for (int i = 0; i < n; ++i) combinations *= 3;
        for (int code = 0; code < combinations; ++code) {
            std::vector<int> values(n);
            int digits = code;
            for (int& value : values) { value = digits % 3 - 1; digits /= 3; }
            for (int k = -1; k <= n + 1; ++k) {
                for (int threshold = -7; threshold <= 7; ++threshold) {
                    std::vector<int> expected;
                    if (k > 0 && k <= n) {
                        for (int end = k - 1; end < n; ++end) {
                            long long sum = 0;
                            for (int j = end - k + 1; j <= end; ++j) sum += values[j];
                            if (sum > threshold) expected.push_back(end);
                        }
                    }
                    CHECK(alarms(values, k, threshold) == expected);
                    ++cases;
                }
            }
        }
    }
    std::cout << "Q3 exhaustive cases: " << cases << '\n';
}
