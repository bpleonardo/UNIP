namespace ContaBancaria
{
    internal class Program
    {
        static void Main()
        {
            string nomeTitularC1 = "Lucas Teodoro";
            string cpfC1 = "123.456.789-10";
            double saldoC1 = 2500.0;

            string nomeTitularC2 = "Maria Clara";
            string cpfC2 = "987.654.321-00";
            double saldoC2 = 5300.00;

            saldoC1 = deposito(saldoC1, 500);
            saldoC1 = deposito(saldoC1, 350);
            saldoC1 = saque(saldoC1, 350);

            saldoC2 = deposito(saldoC2, 50);
            saldoC2 = deposito(saldoC2, 350);
            saldoC2 = saque(saldoC2, 350);

            Console.WriteLine($"Nome do titular: {nomeTitularC1}, CPF: {cpfC1} e Saldo: {saldoC1}.");
            Console.WriteLine($"Nome do titular: {nomeTitularC2}, CPF: {cpfC2} e Saldo: {saldoC2}.");
        }

        static double deposito(double saldo, double valor)
        {
            return saldo += valor;
        }

        static double saque(double saldo, double valor)
        {
            if (saldo > valor)
            {
                return saldo -= valor;
            }
            else
            {
                return saldo;
            }
        }
    }
}
