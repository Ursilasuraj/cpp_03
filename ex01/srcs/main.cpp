/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:31:45 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/12 16:49:59 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main()
{
	std::cout << "\n=== ClapTrap: basic actions ===" << std::endl;
	ClapTrap clappy("Clappy");

	clappy.attack("a training bot");
	clappy.takeDamage(5);
	clappy.beRepaired(3);
	clappy.takeDamage(8);
	clappy.beRepaired(5); // should fail (dead)

	std::cout << "\n=== ScavTrap: construction, attack override and special ability ===" << std::endl;
	ScavTrap scavy("Scavy");

	scavy.attack("an intruder");
	scavy.guardGate();

	std::cout << "\n=== ScavTrap: copy and assignment ===" << std::endl;
	ScavTrap copyScav(scavy);   // copy constructor
	copyScav.attack("copied target");

	ScavTrap temp("Temp");      // temporary object
	temp = scavy;               // assignment operator
	temp.attack("assigned target");

	std::cout << "\n=== Nested scope: show construction/destruction chaining ===" << std::endl;
	{
			ClapTrap innerClap("InnerClap");
			ScavTrap innerScav("InnerScav");

			innerClap.attack("local bot");
			innerScav.attack("local intruder");
			innerScav.guardGate();
	} // innerClap and innerScav destruct here

	std::cout << "\n=== End of tests ===" << std::endl;

	return 0;
}

