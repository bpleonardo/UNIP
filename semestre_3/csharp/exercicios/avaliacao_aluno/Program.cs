/*
Exercício 1 - Sistema de Avaliação de Aluno

Neste exercício, você deverá desenvolver um programa em C# que receba o nome do aluno, duas
notas e o percentual de frequência. O sistema deve calcular a média do aluno e informar sua
situação final (Aprovado, Recuperação ou Reprovado) de acordo com as regras definidas.
*/
using System.Globalization;

namespace avaliacao_aluno;

class Program
{
    static void Main()
    {
        Console.WriteLine("-=-=-= Avaliação aluno =-=-=-");
        string nome = ReadLine("Digite o nome do aluno: ");

        double n1 = double.Parse(ReadLine("Digite a primeira nota: "), CultureInfo.InvariantCulture);

        double n2 = double.Parse(ReadLine("Digite a segunda nota: "), CultureInfo.InvariantCulture);

        int freq = int.Parse(ReadLine("Digite a frequência do aluno (0-100): "));

        double media = (n1 + n2) / 2;

        string status;

        if (freq < 75 || media < 5)
        {
            status = "Reprovado";
        }
        else if (media < 6)
        {
            status = "Recuperação";
        }
        else
        {
            status = "Aprovado";
        }

        Console.WriteLine($"Nome do aluno: {nome}");
        Console.WriteLine($"Média final: {media:F2}");
        Console.WriteLine($"Frequência: {freq}");
        Console.WriteLine($"Situação final: {status}");
    }

    static string ReadLine(string prompt)
    {
        Console.Write(prompt);
        string output = "";

        while (output == "")
        {
            output = Console.ReadLine() ?? "";
        }

        return output;
    }
}
