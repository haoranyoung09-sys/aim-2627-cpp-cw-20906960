#define main q5_public_main
#include "../src/main/A1_q5.cpp"
#undef main

int main() {
    int cases = 0;
    for (int rows = 1; rows <= 3; ++rows) {
        for (int cols = 1; cols <= 4; ++cols) {
            for (int mask = 0; mask < (1 << (rows * cols)); ++mask) {
                std::vector<std::string> grid(rows, std::string(cols, '.'));
                for (int i = 0; i < rows * cols; ++i)
                    if (mask & (1 << i)) grid[i / cols][i % cols] = '#';
                const auto original = grid;
                std::vector<std::vector<int>> expected(rows, std::vector<int>(cols, 0));
                for (int r = 0; r < rows; ++r) {
                    for (int c = 0; c < cols; ++c) {
                        if (grid[r][c] == '#') { expected[r][c] = -1; continue; }
                        for (int y = 0; y < rows; ++y)
                            for (int x = 0; x < cols; ++x)
                                if (grid[y][x] == '#' && std::abs(y-r)+std::abs(x-c)==1)
                                    ++expected[r][c];
                    }
                }
                CHECK(risk(grid) == expected && grid == original);
                ++cases;
            }
        }
    }
    std::vector<std::string> grid(3, std::string(4, '.'));
    for (int i = 0; i < 12; ++i) {
        grid[i / 4][i % 4] = 'x';
        EXPECT_INVALID(risk(grid));
        grid[i / 4][i % 4] = '.';
    }
    for (int row = 0; row < 3; ++row) {
        grid[row].pop_back();
        EXPECT_INVALID(risk(grid));
        grid[row].push_back('.');
    }
    std::cout << "Q5 exhaustive maps: " << cases << "; invalid variants: 15\n";
}
