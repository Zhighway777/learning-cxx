#include <iostream>
#include <iomanip>
#include <cmath>

// 将浮点数转换为二进制表示
void print_binary(double value) {
    std::cout << std::fixed << std::setprecision(20);
    std::cout << "十进制: " << value << std::endl;
    
    // 提取 IEEE 754 双精度浮点数的各个部分
    unsigned long long bits = *reinterpret_cast<unsigned long long*>(&value);
    
    // 符号位 (1 bit)
    bool sign = (bits >> 63) & 1;
    
    // 指数位 (11 bits)
    unsigned long long exponent = (bits >> 52) & 0x7FF;
    
    // 尾数位 (52 bits)
    unsigned long long mantissa = bits & 0xFFFFFFFFFFFFF;
    
    std::cout << "符号位: " << (sign ? "1" : "0") << std::endl;
    std::cout << "指数位: " << exponent << " (二进制: ";
    for (int i = 10; i >= 0; i--) {
        std::cout << ((exponent >> i) & 1);
    }
    std::cout << ")" << std::endl;
    
    std::cout << "尾数位: ";
    for (int i = 51; i >= 0; i--) {
        std::cout << ((mantissa >> i) & 1);
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << std::endl;
    
    // 计算实际值
    double actual_value = 0.0;
    if (exponent != 0) {
        // 正常数
        double m = 1.0 + mantissa / (1ULL << 52);
        int e = exponent - 1023;
        actual_value = m * std::pow(2.0, e);
    } else if (mantissa != 0) {
        // 非规格化数
        double m = mantissa / (1ULL << 52);
        int e = -1022;
        actual_value = m * std::pow(2.0, e);
    }
    
    if (sign) actual_value = -actual_value;
    std::cout << "实际值: " << actual_value << std::endl;
    std::cout << "误差: " << std::abs(value - actual_value) << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "=== 浮点数精度演示 ===" << std::endl << std::endl;
    
    // 可以精确表示的数
    std::cout << "1. 可以精确表示的数：" << std::endl;
    print_binary(0.5);  // 1/2 = 0.1₂
    print_binary(0.25); // 1/4 = 0.01₂
    print_binary(0.125); // 1/8 = 0.001₂
    print_binary(1.25); // 1 + 1/4 = 1.01₂
    print_binary(2.5);  // 2 + 1/2 = 10.1₂
    print_binary(3.75); // 3 + 3/4 = 11.11₂
    
    std::cout << "2. 无法精确表示的数：" << std::endl;
    print_binary(0.1);  // 1/10 = 0.0001100110011...₂ (无限循环)
    print_binary(0.2);  // 2/10 = 0.001100110011...₂ (无限循环)
    print_binary(0.3);  // 3/10 = 0.01001100110011...₂ (无限循环)
    
    std::cout << "3. 计算演示：" << std::endl;
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    double sum = a + b;
    
    std::cout << "0.1 + 0.2 = " << std::fixed << std::setprecision(20) << sum << std::endl;
    std::cout << "0.3 = " << c << std::endl;
    std::cout << "差值 = " << std::abs(sum - c) << std::endl;
    
    std::cout << "4. 可以精确表示的分数：" << std::endl;
    std::cout << "分母为2的幂次的分数都可以精确表示：" << std::endl;
    std::cout << "1/2 = 0.5" << std::endl;
    std::cout << "1/4 = 0.25" << std::endl;
    std::cout << "1/8 = 0.125" << std::endl;
    std::cout << "1/16 = 0.0625" << std::endl;
    std::cout << "3/4 = 0.75" << std::endl;
    std::cout << "5/8 = 0.625" << std::endl;
    
    std::cout << "5. 无法精确表示的分数：" << std::endl;
    std::cout << "分母包含非2的质因数的分数通常无法精确表示：" << std::endl;
    std::cout << "1/3 = 0.33333333333333331483..." << std::endl;
    std::cout << "1/5 = 0.20000000000000001110..." << std::endl;
    std::cout << "1/7 = 0.14285714285714284921..." << std::endl;
    std::cout << "1/9 = 0.11111111111111110494..." << std::endl;
    std::cout << "1/10 = 0.10000000000000000555..." << std::endl;
    
    return 0;
}
