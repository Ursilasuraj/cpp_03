/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:56:50 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/10 17:20:38 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;

	public:
		  ClapTrap();
		  ClapTrap(const std::string &name);
		  ClapTrap(const ClapTrap &other);
		  ClapTrap &operator=(const ClapTrap &other);
		 ~ClapTrap();
			
		void attack(const std::string& target); 
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif

