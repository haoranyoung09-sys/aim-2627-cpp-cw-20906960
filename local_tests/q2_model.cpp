#define main q2_public_main
#include "../src/main/A1_q2.cpp"
#undef main
#include <random>

std::string join(const std::vector<std::string>& labels) {
    std::string text;
    for (const auto& label : labels) {
        if (!text.empty()) text += ',';
        text += label;
    }
    return text;
}

int main() {
    std::mt19937 random(20906960);
    const std::vector<std::string> names = {"", "a", "aa", "A", "cam", "cam2", "xcam", "_", std::string(32, 'z')};
    int checks = 0;
    for (int trial = 0; trial < 1000; ++trial) {
        std::vector<std::string> model;
        for (unsigned i = 0, n = random() % 12; i < n; ++i)
            model.push_back(names[1 + random() % (names.size() - 1)]);
        const std::string initial = join(model);
        std::vector<LabelEdit> edits;
        for (int step = 0; step < 200; ++step) {
            LabelEdit edit{names[random() % names.size()], names[random() % names.size()]};
            edits.push_back(edit);
            if (edit.from.empty()) {
                if (!edit.to.empty()) model.push_back(edit.to);
            } else {
                const auto found = std::find(model.begin(), model.end(), edit.from);
                if (found != model.end()) {
                    if (edit.to.empty()) model.erase(found);
                    else *found = edit.to;
                }
            }
            CHECK(edit_labels(initial, edits) == join(model));
            ++checks;
        }
    }
    std::cout << "Q2 model checks: " << checks << '\n';
}
