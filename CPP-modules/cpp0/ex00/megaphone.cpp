/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:00:52 by vmustone          #+#    #+#             */
/*   Updated: 2023/10/03 00:11:30 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	for (int i = 1; argv[i] != nullptr; i++){
		string output;
		for (int j = 0; argv[i][j]; j++){
			if (islower(argv[i][j]))
				output += toupper(argv[i][j]);
			else
				output += argv[i][j];
		}
		if (argv[i] != nullptr)
			cout << ' ';
		cout << output;
	}
	cout << endl;
	return 0;
}