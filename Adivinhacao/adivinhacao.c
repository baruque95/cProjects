#include <stdio.h>

int main()
{
	// Imprimindo o cabecalho do jogo
	printf("************************************\n");
	printf("* Bem-vindo ao jogo da adivinhacao *\n");
	printf("************************************\n");

	int numerosecreto = 42;
	int chute;
	int pontuacao = 1000;
	int adivinhou = 0;
	int tentativa = 1;

	// Tentativas até zerar a pontuação do jogo.

	while (adivinhou == 0)
	{
		printf("Tentativa %d: Digite um numero: ", tentativa);
		scanf("%d", &chute);

		if (chute == numerosecreto)
		{
			printf("O numero %d eh o número secreto! Parabéns!\n", chute);
			printf("Você fez %d pontos e acertou na %da tentativa.", pontuacao, tentativa);
			adivinhou = 1;
			printf("%d", tentativa);

			printf("Aperte qualquer botao para encerrar");
			getchar();
		}
		else
		{
			if (chute > numerosecreto)
			{
				printf("O numero %d eh maior que o numero secreto... Tente novamente:\n", chute);
				pontuacao -= 100;
				tentativa++;
			}
			else
			{
				printf("O numero %d eh menor que o numero secreto... Tente novamente:\n", chute);
				pontuacao -= 100;
				tentativa++;
			}
		}

		if (pontuacao == 0)
			printf("Você perdeu o jogo...");
		break;
	}
}
