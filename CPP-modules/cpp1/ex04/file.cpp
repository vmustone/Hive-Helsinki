/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:42:51 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 12:27:46 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

void File::replaceInFile(std::string filename, std::string s1, std::string s2) {
    /*
	if (s1 == "") {
		std::cout << "Nothing to replace" << std::endl;
		exit(1);
	}
	*/
	std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);

    if (!outputFile) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        size_t startPos = 0;
        size_t foundPos;

        while ((foundPos = line.find(s1, startPos)) != std::string::npos) {
            outputFile << line.substr(startPos, foundPos - startPos);
            outputFile << s2;
            startPos = foundPos + s1.length();
        }

        outputFile << line.substr(startPos);
    }

    inputFile.close();
    outputFile.close();
}
