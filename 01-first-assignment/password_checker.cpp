/*
 1. 数字判断：原代码 contains_between(password, 0, 9) 传入的是整数 0 和 9，对应 ASCII 码的 '\0' 和 '\t'，而不是真正的阿拉伯数字字符，修改为字符 '0' 和 '9'。
 2. 长度判断：原代码使用 <= 10，表示长度不能超过10，而题目要求的“至少10个字符”，则修改为 >= 10。
 3. 范围边界：原代码使用小于号 (lower < ch && ch < upper)，导致边界字符（如 'A', 'Z', '0', '9'）被漏判，修改为小于等于号 (lower <= ch && ch <= upper)。
  
 测试输入及预期输出：
 1. 输入: zhang san Abcdef1234 预期输出: VALID
 2. 输入: zhang san 00000000Aa  预期输出: VALID
 3. 输入: zhang san Abcdef123 预期输出: INVALID
 4. 输入: zhang san abcdef1234 (预期输出: INVALID
 5. 输入: zhang san zhang123Aa 预期输出: INVALID
 */
#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;
    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}
