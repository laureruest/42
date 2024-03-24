/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gentest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:42:08 by lruiz-es          #+#    #+#             */
/*   Updated: 2024/03/24 09:59:37 by lruiz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//Comm_ent & Uncomment where necessary
#include <stdio.h>
// #include "libftprintf.h"

int	main(void)
{
	// starting with data for generator and for tests
	const char	battery_test_strings[5][3][300] = {
		{{"A \0\nEsto es una cadena de formato NULL%s"}, {"Esto es un string que\
 no se imprimira"}, {"Esto tampoco"}},
		{{"B En esta prueba imprimimos un caracter S: %s Adios\n\0 y a partir \
de aqui nada %s mas\n"}, {"S"}, {"Simplemente esta no tiene \
que salir siquiera"}},
		{{"C En esta prueba imprimimos un cadena Se imprimio solo la , el re\
	sto se ignora: %s   Adios\n\0 y a partir de aqui na%sda mas"}, \
	   {"Se imprimio solo la \0primera s"}, {"Esta ni entrara a printf"}},
		{{"D En esta prueba imprimimos el primer caracter de la cadena \34Se impr\
imio solo la \34 que por lo tanto es la S: %s\nY ahora la cadena\
completa \34Se imprimio solo la \34: %s\n"}, {"S"}, {"Se imprimio solo la "}},
		{{"E En esta prueba imprimimos el signo %%%%: %%. Y ahora el primer\
caracter de la cadena \34Se imprimio solo la \34, que por lo tanto\
es la S: %s\nY ahora la cadena completa \34Se imprimio solo la \34: %s\n"},\
{"S"}, {"Se imprimio solo la \0y esto no se imprime"}}
	};
	void	*p[8];
	int	i;
	int nreturned;

	p[0] = (void *) 0U;
	p[1] = (void *) 255U;
	p[2] = (void *) 65535U;
	p[3] = (void *) 167777215U;
	p[4] = (void *) 4294967295U;
	p[5] = (void *) 1099511627775U;
	p[6] = (void *) 281474976710655U;
	p[7] = (void *) 18446744073709551615U;
	for (i = 0; i < 5; i++)
	{
	//	nreturned = printf(battery_test_strings[i][0], battery_test_strings
	//			[i][1], battery_test_strings[i][2]);
		nreturned = printf(&battery_test_strings[i][0][0],\
&battery_test_strings[i][1][0], &battery_test_strings[i][2][0]);
	}
	//nreturned = printf("Imprimimos un monton de caracteres iniciales de
	// cuatro cadenas diferentes %%c:%c, %%c:%c, %%c:%c,y un string %%s:%s\n",
	//  'A', 'B', 'C', "Esto es la cadena completa");
	nreturned = printf("imprimo null %s:", p[0]);
	nreturned = printf("Imprimimos un monton de caracteres iniciales de\
 cuatro cadenas diferentes %%c:%c, %%c:%c, %%c:%c, y un string %%s:%s", 'A', 'B', 'C', "Esto es la cadena completa");
	for (i = 0; i < 7; i += 2)
	{
//		nreturned = printf("Imprimo el puntero numero:%i:%p y el puntero numero
//		%%i:%p\n", i, p[i], i + 1, p[i+1]); 
		nreturned = printf("Imprimo el puntero numero:%i:%p y el puntero num\
ero:%i:%p\n", i, p[i], i + 1, p[i+1]);
	}
	nreturned = printf("Imprimo el 0 como %%i: %i, %%d: %d, %%u: %u, %%x: %x, %%X: %X", 0, 0, 0, 0, 0);
	for (i = -2147483648; i < 2147382646; i += 77777)
	{
//		nreturned = printf("Imprimo el entero como %%i:%i\n", i);
//		nreturned = printf("Imprimo el entero como %%d:%d\n", i);
//		nreturned = printf("Imprimo el entero como %%u:%u\n",i);
//		nreturned = printf("Imprimo en hexadecimal minuscula %%x:%x, y en
//		hexadecimal mayuscula %%X:%X\n", i, i);
		nreturned = printf("Imprimo el entero como %%i:%i\n", i);
		nreturned = printf("Imprimo el entero como %%d:%d\n", i);
		nreturned = printf("Imprimo el entero como %%u:%u\n",i);
		nreturned = printf("Imprimo en hexadecimal minuscula %%x:%x, y\
 en hexadecimal mayuscula %%X:%X\n", i, i);
	}
	return (nreturned);
}
