/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:24:22 by linyao            #+#    #+#             */
/*   Updated: 2024/11/05 11:47:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        ~Contact();
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickName(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);
/*        
        void setContact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& pn, const std::string& ds);
        std::string formatString(const std::string& s, int width);
        void printContact(const Contact& c) const;
*/
};

#endif
