using System;

namespace salario;

public class Funcionario
{
    public string Nome;
    public double SalarioBruto;
    public double Imposto;

    public double SalarioLiquido()
    {
        return SalarioBruto - Imposto;
    }

    public void AumentarSalario(double porcentagem)
    {
        // 15 -> 1.15
        double multiplicador = porcentagem / 100 + 1;
        SalarioBruto *= multiplicador;
    }
}
