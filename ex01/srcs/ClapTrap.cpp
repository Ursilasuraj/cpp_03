/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 08:01:27 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/03 17:52:29 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "default";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;

	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;

	std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called for " << _name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = (other._name);
	_hitPoints =(other._hitPoints);
	_energyPoints = (other._energyPoints);
	_attackDamage = (other._attackDamage);
	}
	std::cout << "ClapTrap Copy assignment operator called for " << _name << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!isOperational())
	{
		std::cout << _name << " has been already destroyed!" << std::endl;
		return ;
	}
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " cannot attack (no energy)" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!isOperational())
	{
		std::cout << _name << " has been already destroyed!" << std::endl;
		return ;
	}
	if (amount <= static_cast<unsigned int>(_hitPoints))
		_hitPoints = _hitPoints - amount;
	else
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! "
			<< "Has " << _hitPoints << " points after." << std::endl;
	}
	if (!isOperational())
		std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!isOperational())
	{
		std::cout << _name << " has been already destroyed!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left, cannot repair" << std::endl;
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired by " << amount
		<< " points! (HP: " << _hitPoints << ", EP left: " << _energyPoints << ")" << std::endl;
}
