/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:48:14 by linyao            #+#    #+#             */
/*   Updated: 2024/11/02 15:48:18 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; av[i]; i++)
        {
            for (int j = 0; av[i][j]; j++)
                av[i][j] = std::toupper(av[i][j]);
            std::cout << av[i];
        }
        std::cout << std::endl;
    }
    return (0);
}
/*
int main(int ac, char **av)
{
    int i = 1, j = 0;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[i] && av[i][j] != '\0')
        {
            j = 0;
            while (av[i][j] != '\0')
            {
                if (av[i][j] <= 'z' &&av[i][j] >= 'a')
                    av[i][j] -= 32;
                j++;
            }
            i++;
        }
        i = 1;
        while (av[i])
            std::cout << av[i++];
        std:: cout << std::endl;
    }
    return (0);
}
*/