typedef struct aluno
{
    int nota1, nota2;
    float media;
} aluno;

int main()
{
    aluno x[2];
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Digite as notas do % do aluno : ", i + 1);
        scanf("% d % d", &(x[i].nota1), &(x[i].nota2));
    }
    for (i = 0; i < 2; i++)
    {
        x[i].media = (x[i].nota1 + x[i].nota2) / 2.0;
    }
    for (i = 0; i < 2; i++)
    {
        printf("Media do % do aluno : % .1f\n", i + 1, x[i].media);
    }
    return (0);
}