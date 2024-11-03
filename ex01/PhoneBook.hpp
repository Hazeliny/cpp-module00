/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:24:25 by linyao            #+#    #+#             */
/*   Updated: 2024/11/03 22:06:22 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int currentIndex;
        int totalContacts;
    public:
        PhoneBook();
        ~PhoneBook();
        void add();
        void search();
        bool isNumeric(const std::string& str);
        std::string formatString(const std::string& str, std::string::size_type width); 
        void displayContacts();
        void printContact(int index);
};

#endif
