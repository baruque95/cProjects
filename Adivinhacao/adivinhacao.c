#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	// Imprimindo o cabecalho do jogo
	printf("************************************\n");
	printf("* Bem-vindo ao jogo da adivinhacao *\n");
	printf("************************************\n");

	int segundos = time(0);
	srand(segundos);
	int numerosecreto = rand() % 100; // Numero secreto ainda nao randomizado
	int chute;
	int pontuacao = 1000;
	int adivinhou = 0;
	int tentativa = 1;

	// Tentativas até zerar a pontuação do jogo.

	while (adivinhou == 0) // Loop while com problema!
	{
		printf("Tentativa %d: Digite um numero: ", tentativa);
		scanf("%d", &chute);

		if (chute == numerosecreto)
		{
			printf("O numero %d eh o numero secreto! Parabens!\n", chute);
			printf("Voce fez %d pontos e acertou na %da tentativa.", pontuacao, tentativa);
			adivinhou = 1;
		}
		else
		{
			if (chute > numerosecreto)
			{
				printf("O numero %d eh maior que o numero secreto... Tente novamente:\n", chute);
				pontuacao -= (chute - numerosecreto);
				tentativa++;
			}
			else
			{
				printf("O numero %d eh menor que o numero secreto... Tente novamente:\n", chute);
				pontuacao -= (numerosecreto - chute);
				tentativa++;
			}
		}

		if (pontuacao == 0)
			printf("Você perdeu o jogo...");
		break;
	}
}
