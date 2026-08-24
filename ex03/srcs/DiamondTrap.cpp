/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:34:28 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/24 18:02:07 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap(), _name("Unnamed") 
{
    _hitPoints = 100; //FragTrap
    _energyPoints = 50; //scav
    _attackDamage = 30; //Frag
    std::cout << "DiamondTrap " << _name << " constructed (default)"  << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + _clap_name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " parametrized constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.ClapTrap::_name), ScavTrap(other), FragTrap(other), _name(other._name)
{
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap " << _name << "copy-constructed" << std::endl;
}

