#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: btc input_file" << std::endl;
        return 1;
    }

    std::string inputFilename = argv[1];
    std::ifstream inputFile(inputFilename);
    if (!inputFile) {
        std::cerr << "Error: could not open " << inputFilename << " file." << std::endl;
        return 1;
    }

    std::map<std::string, float> bitcoinData;

    try {
        bitcoinData = loadBitcoinData("data.csv");
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::string line;
    while (getline(inputFile, line)) {
        if (line == "date | value") {
            continue;
        }

        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateString = line.substr(0, delimiterPos - 1);
        std::string valueString = line.substr(delimiterPos + 2);
        if (!isValidDate(dateString)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        try {
            value = std::stof(valueString);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << "bad input" << " => " << valueString << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

		if (!isNumeric(valueString)) {
            std::cerr << "Error: bad input => " << valueString << std::endl;
    		continue;
        }

        std::string closestDate = findClosestDate(bitcoinData, dateString);
        float exchangeRate = bitcoinData[closestDate];
        std::cout << dateString << " => " << value << " = " << value * exchangeRate << std::endl;
    }

    return 0;
}
