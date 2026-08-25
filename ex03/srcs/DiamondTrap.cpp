/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:34:28 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/25 13:07:05 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap(), name("Unnamed") 
{
    hitPoints = 100; //FragTrap
    energyPoints = 50; //scav
    attackDamage = 30; //Frag
    std::cout << "DiamondTrap " << name << " constructed (default)"  << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap " << name << " parametrized constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.ClapTrap::name), ScavTrap(other), FragTrap(other), name(other.name)
{
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "DiamondTrap " << name << "copy-constructed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap " << name << "Copy-assigned" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << name << " destructed" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: "<< name << " | ClapTrap name: "<< ClapTrap::name << std::endl;
}


