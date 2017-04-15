package task5.actions;

import task5.SlijedBrojeva;
import java.util.Collection;

public class Prosjek extends Akcija {

    public Prosjek(SlijedBrojeva source) {
        super(source);
    }

    @Override
    public void update() {
        Collection<Integer> numbers = this.source.getNumberSequence();
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        System.out.println("Prosjek je: " + sum/(double)numbers.size());
    }
}
