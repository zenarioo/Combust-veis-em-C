#include <stdio.h>

int main() {
    int id, tipoCombustivel;
    float kmInicial, kmFinal, combustivelConsumido;
    float precoCombustivel, kmPorLitro, custoPorKm;
    int totalVeiculos = 0, abaixoDe060 = 0, acimaDe060 = 0;



while (id != 0) {
    printf("Digite o número de identificação do veículo (ID) ou 0 para encerrar: ");
    scanf("%d", &id);

    if(id == 0 ){
        break;
    }
        totalVeiculos++;

        
        printf("Digite o tipo de combustível (1: Etanol, 2: Gasolina, 3: Diesel): ");
        scanf("%d", &tipoCombustivel);

        switch (tipoCombustivel) {
            case 1:
                precoCombustivel = 3.99;
                break;
            case 2:
                precoCombustivel = 5.89;
                break;
            case 3:
                precoCombustivel = 5.99;
                break;
            default:
                printf("Tipo de combustível inválido! Tente novamente.\n");
                totalVeiculos--;
                continue;
        }

        
        printf("Digite a quilometragem inicial: ");
        scanf("%f", &kmInicial);

        printf("Digite a quilometragem final: ");
        scanf("%f", &kmFinal);

        printf("Digite a quantidade de combustível consumido (litros): ");
        scanf("%f", &combustivelConsumido);

        
        if (kmFinal > kmInicial && combustivelConsumido > 0) {
            kmPorLitro = (kmFinal - kmInicial) / combustivelConsumido;
            custoPorKm = precoCombustivel / kmPorLitro;

            printf("Veículo ID %d -> Km/L: %.2f, Custo por Km: R$ %.2f\n", id, kmPorLitro, custoPorKm);

           
            if (custoPorKm < 0.60) {
                abaixoDe060++;
            } else {
                acimaDe060++;
            }
        } else {
            printf("Dados inválidos para quilometragem ou consumo de combustível. Tente novamente.\n");
            totalVeiculos--;
        }

       
        printf("\nDigite o número de identificação do próximo veículo (ID) ou 0 para encerrar: ");
        scanf("%d", &id);
    }

    
    printf("\nNúmero total de veículos processados: %d\n", totalVeiculos);
    printf("Número de veículos com custo por Km abaixo de R$ 0,60: %d\n", abaixoDe060);
    printf("Número de veículos com custo por Km acima de R$ 0,60: %d\n", acimaDe060);

    return 0;
}
