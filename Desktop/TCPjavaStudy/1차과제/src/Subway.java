public class Subway {
    int line;
    int people;
    int income = 1000;
    int fee;

    Subway(int _line, int _people, int _fee) {
        line = _line;
        people = _people;
        fee = _fee;
    }

    public void ride() {
        people += 1;
        income += fee;
    }

    public void printSubway() {
        System.out.println("Subway");
        System.out.println("income :" + income);
    }

}
