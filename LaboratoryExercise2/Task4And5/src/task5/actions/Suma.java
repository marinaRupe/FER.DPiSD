package task5.actions;

import task5.SlijedBrojeva;
import java.util.Collection;

public class Suma extends Akcija {

    public Suma(SlijedBrojeva source) {
        super(source);
    }

    @Override
    public void update() {
        Collection<Integer> numbers = this.source.getNumberSequence();
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        System.out.println("Suma je: " + sum);
    }
}
