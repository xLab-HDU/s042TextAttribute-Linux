#include <iostream>
#include <vector>

int main() {
    std::cout << "下面将显示前景色代码与效果：" << std::endl;

    // 显示 16 种前景色（30-37, 90-97）
    for (int i = 0; i < 16; ++i) {
        int ansiCode = (i < 8) ? (30 + i) : (90 + (i - 8));
        std::cout << "\033[" << ansiCode << "m"
                  << ansiCode << " 的颜色"
                  << "\033[0m" << std::endl;
    }

    std::cout << "\n下面将显示背景色代码与效果：" << std::endl;

    // 显示背景色（40-47, 100-107）
    std::vector<int> bgCodes;
    for (int i = 0; i < 8; ++i) bgCodes.push_back(40 + i);
    for (int i = 0; i < 8; ++i) bgCodes.push_back(100 + i);

    for (int code : bgCodes) {
        std::cout << "\033[" << code << "m"
                  << code << " 的颜色"
                  << "\033[0m" << std::endl;
    }

    std::cout << "\n按回车键结束...";
    std::cin.get();
    return 0;
}
