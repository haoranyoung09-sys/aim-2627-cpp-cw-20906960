#define main q5_public_main
#include "../src/main/A1_q5.cpp"
#undef main
int main() {
 CHECK(risk({}).empty());
 EXPECT_INVALID(risk({""}));
 EXPECT_INVALID(risk({"..","."}));
 EXPECT_INVALID(risk({"..",".x"}));
 CHECK((risk({"."})==std::vector<std::vector<int>>{{0}}));
 CHECK((risk({"#"})==std::vector<std::vector<int>>{{-1}}));
 CHECK((risk({".","#"})==std::vector<std::vector<int>>{{1},{-1}}));
 CHECK((risk({"#.#"})==std::vector<std::vector<int>>{{-1,2,-1}}));
 CHECK((risk({"#.",".."})==std::vector<std::vector<int>>{{-1,1},{1,0}}));
 CHECK(risk({".#.","#.#",".#."})[1][1]==4);
 const std::vector<std::string> grid(300,std::string(300,'#'));
 CHECK(risk(grid)==std::vector<std::vector<int>>(300,std::vector<int>(300,-1)));
 CHECK(grid[299][299]=='#');
 std::cout << "Q5 boundaries 12/12\n";
}
