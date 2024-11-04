/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:10:52 by linyao            #+#    #+#             */
/*   Updated: 2024/11/04 15:25:37 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0; // number of accounts created
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0; // times of deposits
int Account::_totalNbWithdrawals = 0; // times of withdrawals

Account::Account() {}

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    Account::_totalAmount += Account::checkAmount();
    Account::_nbAccounts++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int	Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals() {
    return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now);
    std::cout << std::put_time(localTime, "[%Y%m%d_%H%M%S]");
}

void	Account::makeDeposit(int deposit) {
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << Account::checkAmount() << ";deposit:" << deposit \
            << ";amount:" << Account::checkAmount() + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    
}
bool	Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << Account::checkAmount() << ";withdrawal:";
    if (this->_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    std::cout << withdrawal << ";amount:" << Account::checkAmount() - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    return (true);
}
int		Account::checkAmount() const {
    return (this->_amount);
}
void	Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits \
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" \
            << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
