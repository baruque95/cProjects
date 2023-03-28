#include <stdio.h>
#include <stdbool.h>

int main()
{
	// Imprimindo o cabecalho do jogo
	printf("************************************\n");
	printf("* Bem-vindo ao jogo da adivinhacao *\n");
	printf("************************************\n");

	int numerosecreto = 42;
	int chute;
	int pontuacao = 1000;
	bool adivinhou = false;

	// Tentativas até zerar a pontuação do jogo.

	while (adivinhou == false)
	{
		printf("Digite um numero: ");
		scanf("%d", &chute);

		if (chute == numerosecreto)
		{
			printf("O numero %d eh o número secreto! Parabéns!\n", chute);
			printf("Você fez %d pontos", pontuacao);
			adivinhou = true;
			printf("Aperte qualquer botao para encerrar");
			getchar();
		}
		else
		{
			if (chute > numerosecreto)
			{
				printf("O numero %d eh maior que o numero secreto... Tente novamente:\n", chute);
				pontuacao -= 100;
			}
			else
			{
				printf("O numero %d eh menor que o numero secreto... Tente novamente:\n", chute);
				pontuacao -= 100;
			}
		}

		if (pontuacao == 0)
			printf("Você perdeu o jogo...");
		break;
	}
}
