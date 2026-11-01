#define main b1_public_main
#include "../src/main/A1_b1.cpp"
#undef main
int main() {
 int x=9;
 CHECK(parse_i32("2147483647",x) && x==2147483647);
 CHECK(parse_i32("-2147483648",x) && x==(-2147483647-1));
 for(const auto& s: std::vector<std::string>{"2147483648","-2147483649","","+","-"," 1","1 ","1.0","++1","+-1","12x",std::string(1000,'9'),std::string(1,static_cast<char>(0xff)),std::string("1\0",2)}) {
  x=123; CHECK(!parse_i32(s,x) && x==123);
 }
 CHECK(parse_i32("-0000",x) && x==0);
 CHECK(parse_i32("+0",x) && x==0);
 CHECK(parse_i32(std::string(1000,'0'),x) && x==0);
 std::cout << "B1 boundaries 19/19\n";
}
