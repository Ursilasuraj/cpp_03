/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 08:01:27 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/09 20:23:56 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) 
: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << " ClapTrap " << this->name << "constructed." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << "destructed " << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << "cant attack, it has no hot points" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack no energy left" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target 
		<< ", causing " << attackDamage << " points of damage! (EP left :" << energyPoints << ")" << std::endl;
	return ;
}
	
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << "is already dead and can't take more damage." << std::endl;
		return ;
	}
	hitPoints -= amount;
	if (hitPoints < 0)
			hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount
   << " points of damage! (HP left: " << hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0) 
	{
		std::cout << "ClapTrap " << name << " can't be repaired, it has no hit points (dead)." << std::endl;
		return;
	}
	if (energyPoints <= 0) 
	{
		std::cout << "ClapTrap " << name << " can't be repaired, it has no energy left." << std::endl;
		return;
	}

	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! (HP: " << hitPoints << ", EP left: "
		<< energyPoints << ")" << std::endl;
}
