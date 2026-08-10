/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:31:45 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/10 18:09:59 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void testAttack(ScavTrap &scav, ClapTrap &clap)
{
	std::cout << "\n-- Attack action --\n";
	scav.attack("enemy");
	clap.attack("target");
}

void testTakeDamage(ScavTrap &scav, ClapTrap &clap)
{
	std::cout << "\n-- Take damage action --\n";
	scav.takeDamage(20);
	clap.takeDamage(5);
}

void testRepair(ScavTrap &scav, ClapTrap &clap)
{
	std::cout << "\n-- Repair action --\n";
	scav.beRepaired(10);
	clap.beRepaired(3);
}

void testSpecialAction(ScavTrap &scav)
{
	std::cout << "\n-- Special action (guardGate) --\n";
	scav.guardGate();
}

int main()
{
	std::cout << "=== ScavTrap/ClapTrap Actions ==\n\n";
	{
		std::cout << "-- Construction chaining --\n";
		ScavTrap scav("S-4V4G");
		ClapTrap clap("CL4P");
		testAttack(scav, clap);
		testTakeDamage(scav, clap);
		testRepair(scav, clap);
		testSpecialAction(scav);
		std::cout << "\n-- Copy & assignment --\n";
		ScavTrap scavCopy(scav);
		ScavTrap scavAssigned;
		scavAssigned = scav;
		std::cout << "\n-- Energy exhaustion test (will run many attacks) --\n";
		for (int i = 0; i < 60; ++i)
			scav.attack("training dummy");
		std::cout << "\n-- Death and repair prevention --\n";
		scavCopy.takeDamage(200);
		scavCopy.beRepaired(10);
		std::cout << "\n-- ScavTrap special behaviour --\n";
		scav.guardGate();
		std::cout << "\n-- End of local scope: destructors for scav, clap will run (check order) --\n";
	}
	std::cout << "\n=== Tester finished ===\n";
	return 0;
}
