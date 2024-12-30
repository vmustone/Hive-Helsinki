#include "BitcoinExchange.hpp"

std::map<std::string, float> loadBitcoinData(const std::string &filename) {
    std::map<std::string, float> bitcoinData;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::invalid_argument("could not open data.csv file");

    std::string line;
    getline(file, line);
    while (getline(file, line)) {
        if (line.size() >= 12) {
            std::string dateString = line.substr(0, 10);
            std::string priceString = line.substr(11);
            bitcoinData[dateString] = std::stof(priceString);
        }
    }
    return bitcoinData;
}

std::string findClosestDate(const std::map<std::string, float> &bitcoinData, const std::string &targetDate) {
    std::string closestDate;
    double minDifference = std::numeric_limits<double>::max();

    std::tm targetTm = {};
    strptime(targetDate.c_str(), "%Y-%m-%d", &targetTm);
    time_t targetTime = mktime(&targetTm);

    std::map<std::string, float>::const_iterator it;

    for (it = bitcoinData.begin(); it != bitcoinData.end(); ++it) {
        const std::string &key = it->first;
        const float &value = it->second;

        std::tm mapTm = {};
        strptime(key.c_str(), "%Y-%m-%d", &mapTm);
        time_t mapTime = mktime(&mapTm);

        double difference = difftime(targetTime, mapTime);
        if (difference >= 0 && difference < minDifference) {
            minDifference = difference;
            closestDate = key;
        }
    }

    return closestDate;
}
bool isNumeric(const std::string& str) {
    bool decimalPointFound = false;
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (c == '.') {
            if (decimalPointFound) {
                return false;
            }
            decimalPointFound = true;
        } else if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isValidDate(const std::string& dateString) {
    std::tm tm = {};
	char *date = strptime(dateString.c_str(), "%Y-%m-%d", &tm);
    if (date == nullptr || *date != 0 || tm.tm_mday <= 0) {
        return false;
    }
    return true;
}
