#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

std::map<std::string, float> loadBitcoinData(const std::string &filename);
std::string findClosestDate(const std::map<std::string, float> &bitcoinData, const std::string &targetDate);

bool isNumeric(const std::string& str);
bool isValidDate(const std::string& dateString);
#endif