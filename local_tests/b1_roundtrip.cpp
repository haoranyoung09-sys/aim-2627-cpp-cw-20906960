#define main b1_public_main
#include "../src/main/A1_b1.cpp"
#undef main
int main() {
    int cases=0;
    for (int value=-100000;value<=100000;++value) {
        const std::string text=std::to_string(value);
        int output=17;
        CHECK(parse_i32(text,output) && output==value);
        CHECK(!parse_i32(text+"x",output) && output==value);
        const std::string padded=(value<0 ? "-000" : "+000")+std::to_string(value<0 ? -value : value);
        CHECK(parse_i32(padded,output) && output==value);
        cases+=3;
    }
    std::cout << "B1 roundtrip cases: " << cases << '\n';
}
