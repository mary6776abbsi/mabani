#include <iostream>
#include <cstring>  // برای استفاده از strlen

// ساختار برای نگهداری شماره تلفن همراه
struct PhoneNumber {
    char number[12];  // 11 رقم برای شماره تلفن و یک رقم برای کاراکتر null
};

// تابع برای اعتبارسنجی شماره تلفن همراه
bool validatePhoneNumber(const PhoneNumber& phone) {
    // بررسی طول شماره تلفن
    if (strlen(phone.number) != 11) {
        return false;
    }

    // بررسی اینکه شماره با "09" شروع شود
    if (phone.number[0] != '0' || phone.number[1] != '9') {
        return false;
    }

    // بررسی اینکه بقیه کاراکترها عدد باشند
    for (int i = 2; i < 11; ++i) {
        if (phone.number[i] < '0' || phone.number[i] > '9') {
            return false;
        }
    }

    return true;
}

int main() {
    PhoneNumber phone;

    std::cout << "Enter a mobile phone number: ";
    std::cin >> phone.number;

    if (validatePhoneNumber(phone)) {
        std::cout << "The phone number is valid." << std::endl;
    }
    else {
        std::cout << "The phone number is invalid." << std::endl;
    }

    return 0;
}
