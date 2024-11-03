/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:43:57 by linyao            #+#    #+#             */
/*   Updated: 2024/11/03 23:02:36 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

Contact::~Contact() {}

std::string Contact::getFirstName(void) {
        return (firstName);
}

std::string Contact::getLastName(void) {
        return (lastName);
}

std::string Contact::getNickName(void) {
        return (nickName);
}

std::string Contact::getPhoneNumber(void) {
        return (phoneNumber);
}

std::string Contact::getDarkestSecret(void) {
        return (darkestSecret);
}

void Contact::setFirstName(std::string str) {
        firstName = str;
}

void Contact::setLastName(std::string str) {
        lastName = str;
}

void Contact::setNickName(std::string str) {
        nickName = str;
}

void Contact::setPhoneNumber(std::string str) {
        phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str) {
        darkestSecret = str;
}
