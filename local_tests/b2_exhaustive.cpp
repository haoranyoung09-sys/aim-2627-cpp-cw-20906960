#define main b2_public_main
#include "../src/main/A1_b2.cpp"
#undef main
#include <iterator>
int main() {
    int cases=0;
    for(int n=0;n<=7;++n) {
        int combinations=1;
        for(int i=0;i<n;++i) combinations*=3;
        for(int code=0;code<combinations;++code) {
            std::vector<int> original(n);
            int digits=code;
            for(int& value:original) {value=digits%3-1;digits/=3;}
            for(int low=-2;low<=2;++low) for(int high=-2;high<=2;++high) {
                std::vector<int> expected;
                std::copy_if(original.begin(),original.end(),std::back_inserter(expected),
                             [=](int value){return value>=low && value<=high;});
                auto data=original;
                const auto count=compact(data.data(),data.size(),low,high);
                CHECK(count==expected.size());
                CHECK(std::equal(expected.begin(),expected.end(),data.begin()));
                if(low>high) CHECK(data==original);
                ++cases;
            }
        }
    }
    std::cout << "B2 exhaustive cases: " << cases << '\n';
}
