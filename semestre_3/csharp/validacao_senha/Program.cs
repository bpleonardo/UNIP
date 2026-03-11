namespace validacao_senha {
    internal class Program {
        static void Main() {
            string senha_correta = "2026";

            Console.WriteLine("-=-=-= Validação de senha =-=-=-");
            while (true) {
                Console.Write("Digite senha: ");
                string senha = Console.ReadLine() ?? "";

                if (senha == senha_correta) {
                    Console.WriteLine("Acesso Permitido");
                    break;
                } else {
                    Console.WriteLine("Senha Invalida");
                }
            }
        }
    }
}
