#include <curl/curl.h>
#include <iostream>
#include <string>
#include <windows.h>

size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main() {


    for (; ; )
    {
    std::string steamProfileUrl;
    std::cout << "Введите Steam профиль игрока: ";
    std::getline(std::cin, steamProfileUrl);

    std::string dotabuffUrl = "https://www.dotabuff.com/players/";
    std::size_t startPos = steamProfileUrl.find_last_of('/') + 1;
    std::size_t endPos = steamProfileUrl.find_last_not_of('/');
    if (startPos != std::string::npos && endPos != std::string::npos) {
        std::string steamId = steamProfileUrl.substr(startPos, endPos - startPos + 1);
        dotabuffUrl += steamId;

        std::cout << "Открывается ссылка на Dotabuff: " << dotabuffUrl << std::endl;

        // Открытие ссылки
        ShellExecuteA(NULL, "open", dotabuffUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
    else {
        std::cout << "Неверная ссылка =( " << std::endl;
    }
  }
    return 0;
}