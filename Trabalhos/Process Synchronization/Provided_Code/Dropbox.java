public class Dropbox {
    private int number;
    private boolean evenNumber = false;
    public int take(final boolean even) {
        System.out.format("%s CONSUMIDOR obtem %d.%n", even ? "PAR" : "IMPAR", number);
        return number;
    }

    public void put(int number) {
        this.number = number;
        evenNumber = number % 2 == 0;
        System.out.format("PRODUTOR gera %d.%n", number);
    }
}
