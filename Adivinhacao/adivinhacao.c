#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	// Imprimindo o cabecalho do jogo
	printf("************************************\n");
	printf("* Bem-vindo ao jogo da adivinhacao *\n");
	printf("************************************\n\n");

	int segundos = time(0);
	srand(segundos);
	int numerosecreto = rand() % 100; // Numero secreto ainda nao randomizado
	int chute;
	int pontuacao = 1000;
	int tentativa = 1;
	int max_attempts;
	int dificuldade;

	printf("Escolha um nivel de dificuldade:\n");
	printf("1 - FACIL\n");
	printf("2 - MEDIO\n");
	printf("3 - DIFICIL\n\n");
	scanf("%d", &dificuldade);

	while (dificuldade < 1 || dificuldade > 3)
	{
		printf("Número inválido. Tente novamente.\n");
		printf("Escolha um nivel de dificuldade:\n");
		printf("1 - FACIL\n");
		printf("2 - MEDIO\n");
		printf("3 - DIFICIL\n");

		scanf("%d", &dificuldade);

		if (dificuldade < 1 || dificuldade > 3)
		{
			break;
		}
	}

	switch (dificuldade)
	{
	case 1:
		max_attempts = 15;
	case 2:
		max_attempts = 10;
	case 3:
		max_attempts = 5;
	}

	// Tentativas até zerar a pontuação do jogo.

	for (int i = 0; i < max_attempts; i++) // Loop while com problema!
	{
		printf("\nTentativa %d: Digite um numero:  ", tentativa);
		scanf("%d", &chute);

		if (chute == numerosecreto)
		{
			printf("O numero %d eh o numero secreto! Parabens!\n", chute);
			printf("Voce fez %d pontos e acertou na %da tentativa.", pontuacao, tentativa);
			getchar();
			break;
		}
		else
		{
			if (chute > numerosecreto)
			{
				printf("O numero %d eh maior que o numero secreto...\n", chute);
				pontuacao -= (chute - numerosecreto);
				tentativa++;
			}
			else
			{
				printf("O numero %d eh menor que o numero secreto...\n", chute);
				pontuacao -= (numerosecreto - chute);
				tentativa++;
			}
		}
	}

	if (chute != numerosecreto)
	{
		printf("\n\nSuas tentativas acabaram e voce perdeu o jogo...\n\n");
		getchar();
	}
}
