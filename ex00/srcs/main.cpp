/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:31:45 by uvadakku          #+#    #+#             */
/*   Updated: 2026/08/10 14:46:52 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("CL4P-TP");
	ClapTrap b("FR4G-TP");
	
	a.attack("an enemy");
	b.takeDamage(3);
	b.beRepaired(5);
	
	//Drain CL4P-TP's energy
	for (int i = 0; i < 10; i++)
		a.attack("dummy");
	//these shoud fail(no energy left);
	a.attack("dummy");
	a.attack("dummy");

	b.takeDamage(12); 
	b.beRepaired(5);
	
	return (0);
}
