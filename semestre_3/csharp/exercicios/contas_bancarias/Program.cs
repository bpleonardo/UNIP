using System.Globalization;

namespace contas_bancarias;

class Program
{
    static void Main(string[] args)
    {
        List<string> nomes = [];
        List<double> saldos = [];

        bool executando = true;

        while (executando)
        {
            ExibirMenu();

            if (!int.TryParse(Console.ReadLine(), out int opcao))
            {
                continue;
            }

            switch (opcao)
            {
                case 1:
                    CadastrarConta(nomes, saldos);
                    break;
                case 2:
                    ListarContas(nomes, saldos);
                    break;
                case 3:
                    Depositar(nomes, saldos);
                    break;
                case 4:
                    Sacar(nomes, saldos);
                    break;
                case 5:
                    executando = false;
                    break;
                default:
                    break;
            }
        }
    }

    static void Pausar(string? mensagem = null)
    {
        if (mensagem != null)
        {
            Console.WriteLine(mensagem);
        }
        Console.WriteLine("Pressione qualquer tecla para continuar.");
        Console.ReadKey();
    }

    static void ExibirMenu()
    {
        Console.Clear();
        Console.WriteLine("------- Gerenciamento Bancário -------");
        Console.WriteLine("1. Cadastrar conta");
        Console.WriteLine("2. Listar contas");
        Console.WriteLine("3. Depositar");
        Console.WriteLine("4. Sacar");
        Console.WriteLine("5. Sair");
        Console.WriteLine("--------------------------------------");
        Console.Write("> ");
    }

    static void CadastrarConta(List<string> nomes, List<double> saldos)
    {
        Console.Clear();

        int n = nomes.Count;

        if (n == 3)
        {
            Pausar("Limite máximo de contas atingido!");
            return;
        }

        Console.Write($"Digite o nome do {n + 1}º títular: ");
        string nome = Console.ReadLine() ?? "";
        if (nome == "")
        {
            Pausar("Nome inválido!");
            return;
        }

        Console.Write($"Digite seu saldo inicial: ");
        if (!double.TryParse(Console.ReadLine(), CultureInfo.InvariantCulture, out double saldo))
        {
            Pausar("Saldo inválido.");
            return;
        }

        nomes.Add(nome);
        saldos.Add(saldo);
    }

    static void ListarContas(List<string> nomes, List<double> saldos)
    {
        Console.Clear();
        Console.WriteLine("------- Contas cadastradas -------");
        for (int i = 0; i < nomes.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {nomes[i]} - Saldo: R${saldos[i]:F2}.");
        }
        Console.WriteLine("----------------------------------");
        Pausar();
    }

    static void Depositar(List<string> nomes, List<double> saldos)
    {
        Console.Clear();

        Console.WriteLine("------- Contas cadastradas -------");
        for (int i = 0; i < nomes.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {nomes[i]} - Saldo: R${saldos[i]:F2}.");
        }
        Console.WriteLine("----------------------------------");

        Console.Write("Selecione o número da conta: ");
        if (!int.TryParse(Console.ReadLine(), out int opcao) || opcao <= 0 || opcao > nomes.Count)
        {
            Pausar("Conta inválida.");
            return;
        }

        double saldoAnt = saldos[opcao - 1];

        Console.Write($"Insira o valor a depositar (atual: R${saldoAnt:F2}): ");
        if (!double.TryParse(Console.ReadLine(), out double depost) || depost < 0)
        {
            Pausar("Depósito inválido.");
            return;
        }

        saldos[opcao - 1] += depost;
    }

    static void Sacar(List<string> nomes, List<double> saldos)
    {
        Console.Clear();

        Console.WriteLine("------- Contas cadastradas -------");
        for (int i = 0; i < nomes.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {nomes[i]} - Saldo: R${saldos[i]:F2}.");
        }
        Console.WriteLine("----------------------------------");

        Console.Write("Selecione o número da conta: ");
        if (!int.TryParse(Console.ReadLine(), out int opcao) || opcao <= 0 || opcao > nomes.Count)
        {
            Pausar("Conta inválida.");
            return;
        }

        double saldoAnt = saldos[opcao - 1];

        Console.Write($"Insira o valor a sacar (atual: R${saldoAnt:F2}): ");
        if (!double.TryParse(Console.ReadLine(), out double saque) || saque < 0)
        {
            Pausar("Saque inválido.");
            return;
        }

        if ((saldoAnt - saque) < 0)
        {
            Pausar("Saque deixaria o títular negativado!");
            return;
        }

        saldos[opcao - 1] -= saque;
    }
}
