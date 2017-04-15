package task5.actions;

import task5.SlijedBrojeva;
import java.util.Collections;
import java.util.List;

public class Medijan extends Akcija {

    public Medijan(SlijedBrojeva source) {
        super(source);
    }

    @Override
    public void update() {
        List<Integer> numbers = this.source.getNumberSequence();
        Collections.sort(numbers);
        int N = numbers.size();
        double median = ( N % 2 == 1) ? numbers.get(N/2) : (numbers.get(N/2) + numbers.get(N/2 - 1)) / 2.0;
        System.out.println("Medijan je: " + median);
    }
}
