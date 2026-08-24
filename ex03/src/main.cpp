/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:31:45 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/12 17:53:59 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void testBasicActions(FragTrap &frag, ClapTrap &clap)
{
    std::cout << "\n-- Basic actions --\n";
    frag.attack("orc");
    clap.attack("target");

    frag.takeDamage(20);
    clap.takeDamage(5);

    frag.beRepaired(10);
    clap.beRepaired(3);
}

void testSpecialAbility(FragTrap &frag)
{
    std::cout << "\n-- FragTrap special ability --\n";
    frag.highFivesGuys();
}

void testCopyAndAssignment(FragTrap &frag)
{
    std::cout << "\n-- Copy & assignment tests --\n";

    std::cout << "\nFragTrap copy & assignment:\n";
    FragTrap fragCopy(frag);
    FragTrap fragAssigned;
    fragAssigned = frag;
}

void testEnergyExhaustion(FragTrap &frag)
{
    std::cout << "\n-- Energy exhaustion test --\n";
    for (int i = 0; i < 110; ++i)
        frag.attack("training dummy");
}

void testDeathBehavior(FragTrap &frag)
{
    std::cout << "\n-- Death and repair prevention --\n";
    frag.takeDamage(200);
    frag.beRepaired(10);
}

int main()
{
    std::cout << "=== FragTrap ===\n\n";
    {
        std::cout << "-- Construction chaining --\n";
        FragTrap frag("Frodo");
		ScavTrap scav("Scavy");
        ClapTrap clap("Sam");

        testBasicActions(frag, clap);
        testSpecialAbility(frag);
        testCopyAndAssignment(frag);
        testEnergyExhaustion(frag);
        testDeathBehavior(frag);

        std::cout << "\n-- End of scope: destructors will run --\n";
    }

    std::cout << "\n=== Tester finished ===\n";
    return 0;
}
