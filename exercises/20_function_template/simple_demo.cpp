#include <iostream>
#include <iomanip>
#include <cmath> // Required for std::abs

int main() {
    std::cout << "=== 浮点数精度问题演示 ===" << std::endl << std::endl;
    
    std::cout << "1. 十进制转二进制的原理：" << std::endl;
    std::cout << "   0.1 (十进制) = 1/10" << std::endl;
    std::cout << "   转换为二进制的过程：" << std::endl;
    std::cout << "   0.1 × 2 = 0.2  → 整数部分 0" << std::endl;
    std::cout << "   0.2 × 2 = 0.4  → 整数部分 0" << std::endl;
    std::cout << "   0.4 × 2 = 0.8  → 整数部分 0" << std::endl;
    std::cout << "   0.8 × 2 = 1.6  → 整数部分 1" << std::endl;
    std::cout << "   0.6 × 2 = 1.2  → 整数部分 1" << std::endl;
    std::cout << "   0.2 × 2 = 0.4  → 整数部分 0 (循环开始)" << std::endl;
    std::cout << "   结果：0.1 = 0.0001100110011...₂ (无限循环)" << std::endl << std::endl;
    
    std::cout << "2. 可以精确表示的分数：" << std::endl;
    std::cout << "   0.5 = 1/2 = 0.1₂" << std::endl;
    std::cout << "   0.25 = 1/4 = 0.01₂" << std::endl;
    std::cout << "   0.125 = 1/8 = 0.001₂" << std::endl;
    std::cout << "   0.75 = 3/4 = 0.11₂" << std::endl;
    std::cout << "   1.25 = 5/4 = 1.01₂" << std::endl;
    std::cout << "   2.5 = 5/2 = 10.1₂" << std::endl;
    std::cout << "   3.75 = 15/4 = 11.11₂" << std::endl << std::endl;
    
    std::cout << "3. 无法精确表示的分数：" << std::endl;
    std::cout << "   0.1 = 1/10 = 0.0001100110011...₂ (无限循环)" << std::endl;
    std::cout << "   0.2 = 2/10 = 0.001100110011...₂ (无限循环)" << std::endl;
    std::cout << "   0.3 = 3/10 = 0.01001100110011...₂ (无限循环)" << std::endl;
    std::cout << "   1/3 = 0.0101010101...₂ (无限循环)" << std::endl;
    std::cout << "   1/7 = 0.001001001...₂ (无限循环)" << std::endl << std::endl;
    
    std::cout << "4. 实际计算演示：" << std::endl;
    std::cout << std::fixed << std::setprecision(20);
    
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    double sum = a + b;
    
    std::cout << "   0.1 = " << a << std::endl;
    std::cout << "   0.2 = " << b << std::endl;
    std::cout << "   0.1 + 0.2 = " << sum << std::endl;
    std::cout << "   0.3 = " << c << std::endl;
    std::cout << "   差值 = " << std::abs(sum - c) << std::endl << std::endl;
    
    std::cout << "5. 可以精确表示的计算：" << std::endl;
    double x = 1.25;
    double y = 2.5;
    double z = 3.75;
    double sum2 = x + y;
    
    std::cout << "   1.25 = " << x << std::endl;
    std::cout << "   2.5 = " << y << std::endl;
    std::cout << "   1.25 + 2.5 = " << sum2 << std::endl;
    std::cout << "   3.75 = " << z << std::endl;
    std::cout << "   差值 = " << std::abs(sum2 - z) << std::endl << std::endl;
    
    std::cout << "6. 判断规则：" << std::endl;
    std::cout << "   ✓ 分母为2的幂次的分数可以精确表示" << std::endl;
    std::cout << "   ✓ 例如：1/2, 1/4, 1/8, 3/4, 5/8 等" << std::endl;
    std::cout << "   ✗ 分母包含非2的质因数的分数通常无法精确表示" << std::endl;
    std::cout << "   ✗ 例如：1/3, 1/5, 1/7, 1/10 等" << std::endl;
    
    return 0;
}

