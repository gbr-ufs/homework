import java.io.Console;

interface Temperatura {
    public double paraCelsius();
    public double paraFahrenheit();
}

class Celsius implements Temperatura {
    private double valor = 0.00;

    public Celsius(double valor) {
        this.valor = valor;
    }
    
    public double paraCelsius() {
        return valor;
    }

    public double paraFahrenheit() {
        return (valor * 9 / 5) + 32;
    }
}

class Fahrenheit implements Temperatura {
    private double valor = 0.00;

    public Fahrenheit(double valor) {
        this.valor = valor;
    }

    public double paraCelsius() {
        return (valor - 32) * 5 / 9;
    }

    public double paraFahrenheit() {
        return valor;
    }
}

public class ConversorDeGrau {
    public static void main(String[] args) throws Exception{
        double valor;
        String tipo;
        Console console = System.console();

        valor = Double.parseDouble(console.readLine("Qual o valor da sua temperatura? "));
        tipo = console.readLine("Seu valor está em Celsius ou Fahrenheit? ");

        if (tipo.equals("Celsius")) {
            System.out.println("Seu valor será convertido para Fahrenheit");
            Celsius temperatura = new Celsius(valor);
            System.out.println(temperatura.paraFahrenheit() + " °F");
        } else if (tipo.equals("Fahrenheit")) {
            System.out.println("Seu valor será convertido para Celsius");
            Fahrenheit temperatura = new Fahrenheit(valor);
            System.out.println(temperatura.paraCelsius() + " °C");
        } else {
            throw new Exception("Tipo desconhecido ou não implementado");
        }
    }
}
