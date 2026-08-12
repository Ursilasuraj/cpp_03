/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:15:28 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/12 17:09:52 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "default";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap parameterized constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy-constructed for " << other.name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap Copy-assigned for" << name << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructed " << name << std::endl;
}

void FragTrap::attack(const std::string &target) 
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " cannot attack, no hit points left." << std::endl;
		return ;
	}
	
	if (energyPoints == 0) 
	{
		std::cout << "FragTrap " << name << " cannot attack, no energy left." << std::endl;
		return ;
	}
	
	--energyPoints;
	std::cout << "FragTrap " << name << " attacks " << target 
		<< ", causing " << attackDamage << " points of damage!"
		<< " (EP left: " << energyPoints << ")" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap" << name 
	<< " requests a high five! " << std::endl;
} 
