package task5.source;

import java.util.Scanner;

public class TipkovnicniIzvor implements IIzvorBrojeva {
    private Scanner reader;

    public TipkovnicniIzvor() {
        reader = new Scanner(System.in);
    }

    @Override
    public int next() {
        return reader.nextInt();
    }
}
