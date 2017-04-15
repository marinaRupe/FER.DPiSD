package task5.source;

import java.io.*;

public class DatotecniIzvor implements IIzvorBrojeva {
    private BufferedReader reader;

    public DatotecniIzvor(File file) {
        try {
            reader = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public int next() {
        try {
            String line = reader.readLine();
            if (line == null) {
                return -1;
            }
            return Integer.parseInt(line);
        } catch (IOException e) {
            return -1;
        }
    }
}
