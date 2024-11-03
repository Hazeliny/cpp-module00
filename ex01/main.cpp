/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:35:02 by linyao            #+#    #+#             */
/*   Updated: 2024/11/03 22:02:23 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;
    
    std::cout << "Welcome to the Phone Book!" << std::endl;
    while (cmd != "EXIT")
    {
        std::cout << "Enter the following commands: ADD, SEARCH, EXIT. -> " << std::endl;
        std::getline(std::cin, cmd);
        if (std::cin.fail())
        {
            std::cerr << "Input error ocurred! Exiting." << std::endl;
            break;
        }
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Invalid command! Re-enter the right command." << std::endl;
    }
    return (0);
}
