/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:31:45 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/25 14:27:37 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

void testBasicActions(DiamondTrap &dia, ClapTrap &clap)
{
    std::cout << "\n-- Basic actions --\n";
    dia.attack("monsta");
    clap.attack("target");

    dia.takeDamage(20);
    clap.takeDamage(5);

    dia.beRepaired(10);
    clap.beRepaired(3);
}

void testSpecialAbility(DiamondTrap &dia)
{
    std::cout << "\n-- DiamondTrap special ability --\n";
    dia.highFivesGuys();
    dia.guardGate(); //scav special
}

void testIdentity(DiamondTrap &dia)
{
    std::cout << "\n-- DiamondTrap test identity --\n";
    dia.whoAmI();  
}

void testCopyAndAssignment(DiamondTrap &dia)
{
    std::cout << "\n-- Copy & assignment tests --\n";

    std::cout << "\nDiamondTrap copy & assignment:\n";
    DiamondTrap diaCopy(dia);
    DiamondTrap diaAssigned;
    diaAssigned = dia;
}

void testEnergyExhaustion(DiamondTrap &dia)
{
    std::cout << "\n-- Energy exhaustion test --\n";
    for (int i = 0; i < 60; ++i)
        dia.attack("training dummy");
}

void testDeathBehavior(DiamondTrap &dia)
{
    std::cout << "\n-- Death and repair prevention --\n";
    dia.takeDamage(200);
    dia.beRepaired(10);
}

int main()
{
    std::cout << "=== FragTrap ===\n\n";
    {
        std::cout << "-- Construction chaining --\n";
        DiamondTrap dia("eva");
        DiamondTrap d;
        FragTrap frag("Frodo");
		ScavTrap scav("Scavy");
        ClapTrap clap("Clappy");

        testBasicActions(dia, clap);
        testSpecialAbility(dia);
        testIdentity(dia);
        testCopyAndAssignment(dia);
        testEnergyExhaustion(dia);
        testDeathBehavior(dia);

        std::cout << "\n-- End of scope: destructors will run --\n";
    }
    return 0;
}
