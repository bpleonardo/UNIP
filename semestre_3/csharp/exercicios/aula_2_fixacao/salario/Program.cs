namespace salario;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Nome: ");
        string nome = Console.ReadLine() ?? "";
        Console.Write("Salário bruto: ");
        double salario = double.Parse(Console.ReadLine() ?? "");
        Console.Write("Imposto: ");
        double imposto = double.Parse(Console.ReadLine() ?? "");

        Funcionario func = new Funcionario();

        func.Nome = nome;
        func.SalarioBruto = salario;
        func.Imposto = imposto;

        Console.WriteLine($"Funcionário: {func.Nome}, R${func.SalarioLiquido():F2}");

        Console.Write("Digite a porcentagem para aumentar o salário: ");
        double perc = double.Parse(Console.ReadLine() ?? "");

        func.AumentarSalario(perc);

        Console.WriteLine($"Dados atualizados: {func.Nome}, R${func.SalarioLiquido():F2}");
    }
}
