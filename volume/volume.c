// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    // Aloca um espaço na memória reservando HEADER_SIZE * tamanho de uint8_t
    uint8_t header[HEADER_SIZE];

    // Lê do ponteiro input 1 elemento com o tamanho de HEADER_SIZE bytes e armazena em header
    fread(header, HEADER_SIZE, 1, input);

    // Escreve em output 1 elemento com o tamanho de HEADER_SIZE bytes o que está alocado no ponteiro header
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    // Aloca um espaço de int16_t na memória
    int16_t buffer;

    // A posição do ponteiro input permanece onde parou + 1 casa, na sua ultima vez usada, no caso na linha 42
    // fread retornará 0 se ocorrer algum erro
    // A partir daí, enquanto não retornar 0 (FALSE),
    // leia do ponteiro input, 1 elemento com o tamanho de int16_t (2 bytes) e aloca no endereço de buffer
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Multiplica o que está em buffer pelo fator
        buffer *= factor;

        // Escreve o que está no endereço de buffer, 1 elemento com o tamanho de int16_t (2 bytes) no ponteiro output
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
