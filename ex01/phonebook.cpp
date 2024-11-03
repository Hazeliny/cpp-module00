/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:41:14 by linyao            #+#    #+#             */
/*   Updated: 2024/11/03 22:50:08 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

PhoneBook::~PhoneBook() {
    std::cout << "The program quits and the contacts are lost forever! Bye!" << std::endl;
}

void PhoneBook::add() {
    std::string str;
    
    if (PhoneBook::currentIndex > 7)
    {
        std::cout << "Attention!! No. " << currentIndex % 8 << " " << contacts[currentIndex % 8].getFirstName() \
                    << " " << "will be overwritten." << std::endl;
    }
    std::cout << "Input the information of the new contact." << std::endl;
    str = "";
//    currentIndex = currentIndex % 8;
    while (!std::cin.eof() && str == "")
    {
        std::cout << "First name: ";
        if (std::getline(std::cin, str) && str != "")
            PhoneBook::contacts[PhoneBook::currentIndex % 8].setFirstName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Last name: ";
        if (std::getline(std::cin, str) && str != "")
            PhoneBook::contacts[PhoneBook::currentIndex % 8].setLastName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Nickname: ";
        if (std::getline(std::cin, str) && str != "")
            PhoneBook::contacts[PhoneBook::currentIndex % 8].setNickName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Phone number: ";
        if (std::getline(std::cin, str) && str != "")
            PhoneBook::contacts[PhoneBook::currentIndex % 8].setPhoneNumber(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Darkest secret: ";
        if (std::getline(std::cin, str) && str != "")
            PhoneBook::contacts[PhoneBook::currentIndex % 8].setDarkestSecret(str);
    }
    currentIndex++;
    if (PhoneBook::totalContacts < 8)
        PhoneBook::totalContacts++;
}
bool PhoneBook::isNumeric(const std::string& str) {
    if (str.empty())
        return (false);
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(static_cast<unsigned char>(*it)))
            return (false);
    }
    return (true);
}

std::string PhoneBook::formatString(const std::string& str, std::string::size_type width) {
    if (str.length() >= width)
        return (str.substr(0, width - 1) + ".");
    return (str);
}

void PhoneBook::displayContacts() {
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < PhoneBook::totalContacts; i++)
        std::cout << "|" << std::setw(10) << std::right << i << "|" \
            << std::setw(10) << std::right << formatString(PhoneBook::contacts[i].getFirstName(), 10) << "|" \
            << std::setw(10) << std::right << formatString(PhoneBook::contacts[i].getLastName(), 10) << "|" \
            << std::setw(10) << std::right << formatString(PhoneBook::contacts[i].getNickName(), 10) << "|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::printContact(int index) {
    std::cout << "Displaying the requested information of contact... " << std::endl;
    std::cout << "First Name: " << PhoneBook::contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << PhoneBook::contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << PhoneBook::contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << PhoneBook::contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << PhoneBook::contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::search() {
    std::string istr;
    
    istr = "";
    if (totalContacts <= 0)
        std::cout << "The phone book is empty." << std::endl;
    else
    {
        displayContacts();
        while (!std::cin.eof())
        {
            std::cout << "Enter the index of the contact you want to search: ";
            if (std::getline(std::cin, istr) && istr != "" && isNumeric(istr) && \
                            std::stoi(istr) < totalContacts && std::stoi(istr) >= 0)  
            {
                    break ;
            }                      
            else
                std::cout << "Invalid input!" << std::endl;
        }
        if (!std::cin.eof())
        {
            printContact(std::stoi(istr));
        }
    }
}
