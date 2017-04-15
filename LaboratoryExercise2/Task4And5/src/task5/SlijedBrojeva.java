package task5;


import task5.actions.Akcija;
import task5.source.IIzvorBrojeva;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class SlijedBrojeva {
    private IIzvorBrojeva source;
    private Collection<Akcija> observers;
    private List<Integer> numberSequence;

    public SlijedBrojeva(IIzvorBrojeva source) {
        this.source = source;
        observers = new ArrayList<>();
        numberSequence = new ArrayList<>();
    }

    public IIzvorBrojeva getSource() {
        return source;
    }

    public void setSource(IIzvorBrojeva source) {
        this.source = source;
    }

    public List<Integer> getNumberSequence() {
        return new ArrayList<>(numberSequence);
    }

    public void attach(Akcija action) {
        observers.add(action);
    }

    public void dettach(Akcija action) {
        observers.remove(action);
    }

    private void notifyObservers() {
        for (Akcija action : observers) {
            action.update();
        }
    }

    public void kreni() {
        int num;
        while ((num = source.next()) >= 0){
            numberSequence.add(num);
            notifyObservers();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
