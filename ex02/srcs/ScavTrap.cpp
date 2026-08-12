/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:27:47 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/12 17:03:34 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;

	std::cout << "ScavTrap default constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) 
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy-constructed for " << other.name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap copy-assigned for " << name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack, no hit points left." << std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " attack cannot be done, no energy left " << std::endl;
		return ; 
	}
		--energyPoints;
		std::cout << "ScavTrap " << name << " attacks " << target 
		<< ", causing " << attackDamage << " points of damage! " 
		<< " (EP left: " << energyPoints << ")" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in gate keeper mode" << std::endl;
}