/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:35:41 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/16 08:39:01 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
    	std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
	File	newFile;
    newFile.replaceInFile(argv[1], argv[2], argv[3]);
    return 0;
}