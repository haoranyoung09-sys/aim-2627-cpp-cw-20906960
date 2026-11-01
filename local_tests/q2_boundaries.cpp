#define main q2_public_main
#include "../src/main/A1_q2.cpp"
#undef main
int main() {
    CHECK(edit_labels("a,b,c", {{"a",""}}) == "b,c");
    CHECK(edit_labels("a,b,c", {{"b",""}}) == "a,c");
    CHECK(edit_labels("a,b,c", {{"c",""}}) == "a,b");
    CHECK(edit_labels("a", {{"a",""}}).empty());
    CHECK(edit_labels("a", {{"a",""},{"","b"}}) == "b");
    CHECK(edit_labels("cam2,xcam,cam", {{"cam","imu"}}) == "cam2,xcam,imu");
    CHECK(edit_labels("a,b,a", {{"a","x"}}) == "x,b,a");
    CHECK(edit_labels("A,a", {{"a","x"}}) == "A,x");
    CHECK(edit_labels("a", {{"z","x"},{"",""}}) == "a");
    CHECK(edit_labels("a,b", {}) == "a,b");
    CHECK(edit_labels("", {{"x",""},{"","a"},{"","a"}}) == "a,a");
    CHECK(edit_labels("a,b,a", {{"a","long_name"},{"b",""},{"a","z"}}) == "long_name,z");
    CHECK(edit_labels("a,a", {{"a","a"}}) == "a,a");
    std::string original = "a,b";
    const std::vector<LabelEdit> edits = {{"a","x"}};
    CHECK(edit_labels(original, edits) == "x,b");
    CHECK(original == "a,b" && edits[0].from == "a" && edits[0].to == "x");
    CHECK(edit_labels("", {}).empty());
    std::vector<LabelEdit> many(200, {"", std::string(32, 'x')});
    CHECK(edit_labels("", many).size() == 6599);
    std::cout << "Q2 boundaries 17/17\n";
}
