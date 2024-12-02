//
// Created by Badi on 11/29/2024.
//
#include "Helper.h"

// Function definitions
std::string buildDisplayedText(const std::vector<std::string>& lines) {
    std::string displayedText;
    for (const auto& line : lines) {
        displayedText += line + "\n";
    }
    return displayedText;
}

std::string getFormattedDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm localTime = *std::localtime(&now_c);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d\n    %H:%M:%S");
    return oss.str();
}

std::string trim(const std::string& str) {
    auto start = std::find_if_not(str.begin(), str.end(), ::isspace);
    auto end = std::find_if_not(str.rbegin(), str.rend(), ::isspace).base();
    return (start < end) ? std::string(start, end) : "";
}

std::vector<std::string> sliceStringByChar(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string segment;

    // Extract segments separated by the delimiter
    while (std::getline(ss, segment, delimiter)) {
        result.push_back(segment);
    }

    return result;
}
