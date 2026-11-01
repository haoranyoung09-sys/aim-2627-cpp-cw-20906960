#define main q4_public_main
#include "../src/main/A1_q4.cpp"
#undef main
void verify(const std::vector<std::string>& lines, long long value, int accepted) {
 const auto r=execute(lines);
 CHECK(r.value==value && r.accepted==accepted && r.rejected==static_cast<int>(lines.size())-accepted);
}
int main() {
 verify({},0,0);
 verify({"SET 5","RESET x"},5,1);
 verify({"SET 1000000","ADD 1"},1000000,1);
 verify({"SET -1000000","ADD -1"},-1000000,1);
 verify({"add 5",""," ","ADD","SET","RESET 0"},0,0);
 verify({"ADD +2","RESET"},0,2);
 verify({" \tSET -2 \r\n","ADD 2"},0,2);
 verify({"SET 7","SET 8 x","ADD 2.5","ADD 12x","ADD 1 2"},7,1);
 verify({"SET 7","SET 999999999999999999999999999","SET 1000001","ADD -1000001"},7,1);
 verify({"SET 0009","ADD -0","RESET","RESET"},0,4);
 verify(std::vector<std::string>(10000,"ADD 1"),10000,10000);
 std::cout << "Q4 boundaries 11/11\n";
}
