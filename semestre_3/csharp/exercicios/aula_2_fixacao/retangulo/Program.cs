using System.Globalization;

namespace retangulo;

class Program
{
    static void Main()
    {
        Console.Write("Informe a largura: ");
        double largura = double.Parse(Console.ReadLine() ?? "");

        Console.Write("Informe a altura: ");
        double altura = double.Parse(Console.ReadLine() ?? "");

        Retangulo ret = new Retangulo();
        ret.Largura = largura;
        ret.Altura = altura;

        Console.WriteLine($"AREA = {ret.Area():F2}");
        Console.WriteLine($"PERIMETRO = {ret.Perimetro():F2}");
        Console.WriteLine($"DIAGONAL = {ret.Diagonal():F2}");
    }
}
