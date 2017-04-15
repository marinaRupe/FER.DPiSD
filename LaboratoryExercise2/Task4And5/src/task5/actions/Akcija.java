package task5.actions;


import task5.SlijedBrojeva;

public abstract class Akcija {
    protected SlijedBrojeva source;

    public Akcija(SlijedBrojeva source) {
        this.source = source;
        source.attach(this);
    }

    public void setSource(SlijedBrojeva source) {
        if (this.source != null) {
            this.source.dettach(this);
        }
        this.source = source;
    }

    public abstract void update();
}
