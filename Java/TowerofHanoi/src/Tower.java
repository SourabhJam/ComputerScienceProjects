import java.util.ArrayList;

public class Tower {
	ArrayList<Disc> discs = new ArrayList<Disc>();

	public void draw() {
		for (int i = 6; i > 0; i--) {
			System.out.println("|");
		}

		for (int i = 0; i < discs.size(); i++) {
			Disc d = this.discs.get(i);
			d.draw();
			
		}
	}

	public void addDisc(Disc disc) {
		this.discs.add(disc);
	}

	public Disc removeDisc() throws Exception {
		this.validateDisc();
		Disc disc = this.discs.remove(0);
		return disc;
	}
	
	private void validateDisc( ) throws Exception {
		if (discs.size()==0) {
			throw new Exception("No Discs Avaliable");
		}

	}
}
